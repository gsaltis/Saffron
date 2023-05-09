/*****************************************************************************
 * FILE NAME    : ProjectDisplayBodyWindow.cpp
 * DATE         : December 01 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ProjectDisplayBodyWindow.h"
#include "Trace.h"
#include "ModuleCreateDialog.h"
#include "Project.h"
#include "Module.h"
#include "ModuleMimeData.h"
#include "ModuleDisplayWidget.h"

/*****************************************************************************!
 * Function : ProjectDisplayBodyWindow
 *****************************************************************************/
ProjectDisplayBodyWindow::ProjectDisplayBodyWindow
() : SaffronDisplayWindow()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  setMouseTracking(true);
  setAcceptDrops(true);
  initialize();
  CreateMenu();
}

/*****************************************************************************!
 * Function : ~ProjectDisplayBodyWindow
 *****************************************************************************/
ProjectDisplayBodyWindow::~ProjectDisplayBodyWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ProjectDisplayBodyWindow::initialize()
{
  project = NULL;
  InitializeSubWindows();  
  CreateSubWindows();
  ActionNewModule = new QAction("New Module", this);
  connect(ActionNewModule, SIGNAL(triggered()), this, SLOT(SlotNewModule()));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ProjectDisplayBodyWindow::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ProjectDisplayBodyWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : paintEvent
 *****************************************************************************/
void
ProjectDisplayBodyWindow::paintEvent
(QPaintEvent* InEvent)
{
  QPainter                              painter(this);
  QSize                                 s = size();
  QLinearGradient                       grad(QPoint(0, 0), QPoint(0, s.height()));
  QBrush                                brush;
  QPen                                  pen;
  
  grad.setColorAt(0, QColor(160, 160, 255));
  grad.setColorAt(1, QColor(240, 240, 240));

  pen = QPen(QColor(0, 0, 0, 0));
  brush = QBrush(grad);

  painter.setBrush(brush);
  painter.setPen(pen);
  painter.drawRect(InEvent->rect());
}

/*****************************************************************************!
 * Function : dragEnterEvent
 *****************************************************************************/
void
ProjectDisplayBodyWindow::dragEnterEvent
(QDragEnterEvent* InEvent)
{
  InEvent->acceptProposedAction();
}

/*****************************************************************************!
 * Function : dragMoveEvent
 *****************************************************************************/
void
ProjectDisplayBodyWindow::dragMoveEvent
(QDragMoveEvent* InEvent)
{
  ModuleDisplayWidget*                  widget;
  QList<QString>                        elements;
  QString                               fullname;
  QPoint                                pos;
  QString                               action;
  ModuleMimeData*                       mimeData;
  
  mimeData = (ModuleMimeData*)InEvent->mimeData();

  if ( NULL == mimeData ) {
    return;
  }

  if ( ! mimeData->hasText() ) {
    return;
  }

  fullname = mimeData->text();
  elements = fullname.split("/");
  action = elements[0];
  if ( action == "ModuleMove" ) {
    pos = InEvent->position().toPoint();
    widget = mimeData->GetWidget();
    widget->move(SnapToGrid(pos));
    InEvent->accept();
  }
}

/*****************************************************************************!
 * Function : dropEvent
 *****************************************************************************/
void
ProjectDisplayBodyWindow::dropEvent
(QDropEvent* InEvent)
{
  ModuleDisplayWidget*                  widget;
  QList<QString>                        elements;
  QString                               fullname;
  QPoint                                pos;
  QPoint                                p;
  QString                               action;
  ModuleMimeData*                       mimeData;
  Module*                               module;
  
  mimeData = (ModuleMimeData*)InEvent->mimeData();

  if ( NULL == mimeData ) {
    return;
  }

  if ( ! mimeData->hasText() ) {
    return;
  }

  module = mimeData->GetModule();
  fullname = mimeData->text();
  elements = fullname.split("/");
  action = elements[0];
  if ( action == "ModuleMove" ) {
    pos = InEvent->position().toPoint();
    widget = mimeData->GetWidget();
    p = SnapToGrid(pos);
    module->SetPosition(p);
    widget->move(p);
    InEvent->acceptProposedAction();
  }
}

/*****************************************************************************!
 * Function : mouseMoveEvent
 *****************************************************************************/
void
ProjectDisplayBodyWindow::mouseMoveEvent
(QMouseEvent* InEvent)
{
  (void)InEvent;
}

/*****************************************************************************!
 * Function : mousePressEvent
 *****************************************************************************/
void
ProjectDisplayBodyWindow::mousePressEvent
(QMouseEvent* InEvent)
{
  QPoint                        p;

  p = InEvent->position().toPoint();
  mousePressPoint = p;
  if ( InEvent->button() == Qt::RightButton ) {
    menu->popup(mapToGlobal(p));
  }
}

/*****************************************************************************!
 * Function : SlotNewModule
 *****************************************************************************/
void
ProjectDisplayBodyWindow::SlotNewModule(void)
{
  ModuleCreate("New Module");
}

/*****************************************************************************!
 * Function : CreateMenu
 *****************************************************************************/
void
ProjectDisplayBodyWindow::CreateMenu(void)
{
  menu = new QMenu();
  menu->addAction(ActionNewModule);
}

/*****************************************************************************!
 * Function : ModuleCreate
 *****************************************************************************/
void
ProjectDisplayBodyWindow::ModuleCreate
(QString InName)
{
  Module*                               module;
  ModuleDisplayWidget*                  displayWidget;
  QString                               id;
  
  module = Module::Create(project, InName);
  id = module->GetIDString();
  module->CreateDisplay(SnapToGrid(mousePressPoint), InName);
  displayWidget = module->GetDisplay();
  connect(displayWidget, SIGNAL(SignalOpenModule(Module*)),
          this, SLOT(SlotOpenModule(Module*)));
  displayWidget->setParent(this);
  displayWidget->show();
}

/*****************************************************************************!
 * Function : SlotProjectOpened
 *****************************************************************************/
void
ProjectDisplayBodyWindow::SlotProjectOpened
(Project* InProject)
{
  int                                   n;
  QString                               s;

  project = InProject;
  n = project->GetModuleCount();

  for ( int i = 0 ; i < n ; i++ ) {
    Module* module = project->GetModuleByIndex(i);
    s = module->GetIDString();
    ModuleDisplayWidget* display = module->GetDisplay();
    if ( display ) {
      connect(display, SIGNAL(SignalOpenModule(Module*)),
              this, SLOT(SlotOpenModule(Module*)));
      display->setParent(this);
      display->show();
    }
  }
}

/*****************************************************************************!
 * Function : SlotOpenModule
 *****************************************************************************/
void
ProjectDisplayBodyWindow::SlotOpenModule
(Module* InModule)
{
  emit SignalOpenModule(InModule);
}
