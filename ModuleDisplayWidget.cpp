/*****************************************************************************
 * FILE NAME    : ModuleDisplayWidget.cpp
 * DATE         : December 13 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Vertiv Company
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QSvgWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ModuleDisplayWidget.h"
#include "Trace.h"
#include "Module.h"
#include "ModuleMimeData.h"
#include "Project.h"

/*****************************************************************************!
 * Function : ModuleDisplayWidget
 *****************************************************************************/
ModuleDisplayWidget::ModuleDisplayWidget
(Module* InModule, QString InName) : SaffronComponentDisplayWidget(InName)
{
  QString                               si, si2;

  displayData = new SaffronComponentDisplayData();
  displayData->SetSize(QSize(100, 30));
  si2 = displayData->GetSVGSizeString();
  
  si = displayData->GetSVGFillString();

  QString st = QString("<svg xmlns=\"http://www.w3.org/2000/svg\">\n"
                       "  <defs>\n" + si + 
                       "  </defs>\n\n"
                       "  <rect " + si2 + " rx=\"10\" fill=\"url(#moduleGradient)\" stroke=\"#400\" />\n"
                       "</svg>\n");
  load(st.toLatin1());
  name = InName;
  module = InModule;
  initialize();
  resize(MODULE_DISPLAY_WIDGET_WIDTH, MODULE_DISPLAY_WIDGET_HEIGHT);
}

/*****************************************************************************!
 * Function : ModuleDisplayWidget
 *****************************************************************************/
ModuleDisplayWidget::ModuleDisplayWidget
(class Module* InModule, QString InName, SaffronComponentDisplayData* InData,
 QPoint InPoint, QSize InSize) : SaffronComponentDisplayWidget(InName)
{
  QString                               si;
  QString                               si2;

  resize(InSize);
  move(InPoint);
  
  displayData = InData;
  displayData->SetSize(InSize);
  displayData->SetPosition(InPoint);
  si2 = displayData->GetSVGSizeString();
  si = displayData->GetSVGFillString();

  QString st = QString("<svg xmlns=\"http://www.w3.org/2000/svg\">\n"
                       "  <defs>\n" + si + 
                       "  </defs>\n\n"
                       "  <rect " + si2 + " rx=\"10\" fill=\"url(#moduleGradient)\" stroke=\"#400\" />\n"
                       "</svg>\n");
  load(st.toLatin1());
  name = InModule->GetName()->ToString();
  module = InModule;
  initialize();
}

/*****************************************************************************!
 * Function : ~ModuleDisplayWidget
 *****************************************************************************/
ModuleDisplayWidget::~ModuleDisplayWidget
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleDisplayWidget::initialize()
{
  setCursor(Qt::PointingHandCursor);
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
  menu = new QMenu();
  
  ActionRenameModule = new QAction("Rename Module", this);
  connect(ActionRenameModule, SIGNAL(triggered()), this, SLOT(SlotRenameModule()));
  menu->addAction(ActionRenameModule);
  ActionOpenModule = new QAction("Open Module", this);
  connect(ActionOpenModule, SIGNAL(triggered()), this, SLOT(SlotOpenModule()));
  menu->addAction(ActionOpenModule);
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleDisplayWidget::CreateSubWindows()
{
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleDisplayWidget::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : mousePressEvent
 *****************************************************************************/
void
ModuleDisplayWidget::mousePressEvent
(QMouseEvent *InEvent)
{
  QPoint                                p;
  QPixmap                               iconPixmap(1, 1);

  iconPixmap.fill(QColor(0, 0, 0, 0));
  if (InEvent->button() == Qt::LeftButton ) {
    QDrag *drag = new QDrag(this);
    ModuleMimeData *mimeData = new ModuleMimeData(this, module);
    
    mimeData->setText(QString("ModuleMove/Module/Module"));
    drag->setMimeData(mimeData);
    drag->setPixmap(iconPixmap);
    Qt::DropAction dropAction = drag->exec();
    (void)dropAction;
  } else if ( InEvent->button() == Qt::RightButton ) {
    p = InEvent->position().toPoint();
    menu->popup(mapToGlobal(p));
  }
}

/*****************************************************************************!
 * Function : SlotRenameModule
 *****************************************************************************/
void
ModuleDisplayWidget::SlotRenameModule(void)
{
  int                                   n;
  nameLabel->hide();
  nameEdit->show();
  nameEdit->setFocus();
  n = module->GetName()->ToString().length();
  nameEdit->setSelection(0, n);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
ModuleDisplayWidget::CreateConnections(void)
{
  connect(nameEdit, SIGNAL(editingFinished()), this, SLOT(SlotNameEditFinished()));
  connect(nameEdit, SIGNAL(textChanged(const QString&)),
          this,     SLOT(SlotNameChanged(const QString&)));
}

/*****************************************************************************!
 * Function : SlotNameEditFinished
 *****************************************************************************/
void
ModuleDisplayWidget::SlotNameEditFinished(void)
{
  QString                               s;
  
  nameLabel->show();
  nameEdit->hide();
  s = nameEdit->text();
  nameLabel->setText(s);
  module->SetName(s);
}

/*****************************************************************************!
 * Function : SlotNameChanged
 *****************************************************************************/
void
ModuleDisplayWidget::SlotNameChanged
(const QString& InName)
{
  (void)InName;
}

/*****************************************************************************!
 * Function : SlotOpenModule
 *****************************************************************************/
void
ModuleDisplayWidget::SlotOpenModule(void)
{
  emit SignalOpenModule(module);
}
