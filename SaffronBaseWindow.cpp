/*****************************************************************************
 * FILE NAME    : SaffronBaseWindow.cpp
 * DATE         : November 15 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QPropertyAnimation>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronBaseWindow.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : SaffronBaseWindow
 *****************************************************************************/
SaffronBaseWindow::SaffronBaseWindow
() : QFrame()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(176, 176, 176)));
  setPalette(pal);
  setAutoFillBackground(true);
  setFrameShadow(QFrame::Raised);
  setFrameShape(QFrame::Panel);
  setLineWidth(1);
  initialize();
}

/*****************************************************************************!
 * Function : ~SaffronBaseWindow
 *****************************************************************************/
SaffronBaseWindow::~SaffronBaseWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SaffronBaseWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SaffronBaseWindow::CreateSubWindows()
{
  moduleWindows <<  new ModuleDisplayBaseWindow();  
  moduleWindows[0]->setParent(this);
  moduleWindows[0]->hide();
  connect(moduleWindows[0],
          SIGNAL(SignalModuleWindowSplit(ModuleDisplayWindow*)),
          this,
          SLOT(SlotModuleWindowSplit(ModuleDisplayWindow*)));
  framesWindow = new FramesDisplayWindow();
  framesWindow->setParent(this);
  framesWindow->hide();

  projectWindow = new ProjectDisplayWindow();
  projectWindow->setParent(this);
  projectWindow->hide();
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SaffronBaseWindow::InitializeSubWindows()
{
  framesWindow = NULL;
  projectWindow = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SaffronBaseWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  
  if ( moduleWindows.count() > 0 ) {
    moduleWindows[0]->move(10, 10);
    moduleWindows[0]->resize(width - 20, height-20);
  }
  if ( framesWindow ) {
    framesWindow->move(0, 0);
    framesWindow->resize(width, height);
  }
  if ( projectWindow ) {
    projectWindow->move(0, 0);
    projectWindow->resize(width, height);
  }
}

/*****************************************************************************!
 * Function : SlotProjectCreated
 *****************************************************************************/
void
SaffronBaseWindow::SlotProjectCreated
(QString InProjectName)
{
  emit SignalProjectCreated(InProjectName);
  WindowsHide();
  projectWindow->show();
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
SaffronBaseWindow::CreateConnections(void)
{
  connect(this,
          SIGNAL(SignalProjectCreated(QString)),
          projectWindow,
          SLOT(SlotProjectCreated(QString)));

  connect(this,
          SIGNAL(SignalProjectOpened(Project*)),
          projectWindow,
          SLOT(SlotProjectOpened(Project*)));

  connect(projectWindow,
          SIGNAL(SignalOpenModule(Module*)),
          this,
          SLOT(SlotOpenModule(Module*)));

  connect(moduleWindows[0],
          SIGNAL(SignalDataTypeChanged(QString)),
          this,
          SLOT(SlotDataNameChanged(QString)));

  connect(moduleWindows[0],
          SIGNAL(SignalCloseWindow()),
          this,
          SLOT(SlotCloseModuleWindow()));

  connect(this,
          SIGNAL(SignalProjectOpened(Project*)),
          moduleWindows[0],
          SLOT(SlotProjectOpened(Project*)));
  
  connect(moduleWindows[0],
          SIGNAL(SignalMemberDataLeave(MemberData*)),
          this,
          SLOT(SlotMemberDataLeave(MemberData*)));

  connect(moduleWindows[0],
          SIGNAL(SignalMemberDataEnter(MemberData*)),
          this,
          SLOT(SlotMemberDataEnter(MemberData*)));
}

/*****************************************************************************!
 * Function : WindowsHide
 *****************************************************************************/
void
SaffronBaseWindow::WindowsHide(void)
{
  moduleWindows[0]->hide();
  framesWindow->hide();
  projectWindow->hide();
}

/*****************************************************************************!
 * Function : SlotProjectOpened
 *****************************************************************************/
void
SaffronBaseWindow::SlotProjectOpened
(Project* InProject)
{
  emit SignalProjectOpened(InProject);
  WindowsHide();
  projectWindow->show();
}

/*****************************************************************************!
 * Function : SlotOpenModule
 *****************************************************************************/
void
SaffronBaseWindow::SlotOpenModule
(Module* InModule)
{
  QSize                                 startSize;
  QSize                                 newSize;
  QSize                                 s = size();
  int                                   width;
  int                                   height;
  QPropertyAnimation*                   animation;
  
  WindowsHide();
  moduleWindows[0]->resize(QSize(0, 0));

  s = size();
  width = s.width() - 20;
  height = s.height() - 20;

  newSize = QSize(width, height);
  startSize = QSize(0, 0);
  
  moduleWindows[0]->show();

  animation = new QPropertyAnimation(moduleWindows[0], "size");
  animation->setDuration(250);
  animation->setStartValue(startSize);
  animation->setEndValue(newSize);
  animation->start();
  
  if ( ! InModule->GetIsOpened() ) {
    InModule->OpenDataElements(InModule->GetPath());
  }
  moduleWindows[0]->SetModule(InModule);
}

/*****************************************************************************!
 * Function : SlotModuleClose
 *****************************************************************************/
void
SaffronBaseWindow::SlotModuleClose(void)
{
  QPropertyAnimation*                           animation;
  QSize                                         endSize;
  QSize                                         startSize;

  startSize = moduleWindows[0]->size();
  endSize = QSize(0, 0);
  
  animation = new QPropertyAnimation(moduleWindows[0], "size");
  animation->setDuration(250);
  animation->setStartValue(startSize);
  animation->setEndValue(endSize);
  connect(animation, SIGNAL(finished()), this, SLOT(SlotModuleWindowClosed()));
  animation->start();
}

/*****************************************************************************!
 * Function : SlotModuleWindowClosed
 *****************************************************************************/
void
SaffronBaseWindow::SlotModuleWindowClosed
()
{
  WindowsHide();
  projectWindow->show();
}

/*****************************************************************************!
 * Function : SlotDataNameChanged
 *****************************************************************************/
void
SaffronBaseWindow::SlotDataNameChanged
(QString InDataTypeName)
{
  (void)InDataTypeName;
}

/*****************************************************************************!
 * Function : SlotCloseModuleWindow
 *****************************************************************************/
void
SaffronBaseWindow::SlotCloseModuleWindow(void)
{
  SlotModuleClose();
}

/*****************************************************************************!
 * Function : SlotModuleWindowSplit
 *****************************************************************************/
void
SaffronBaseWindow::SlotModuleWindowSplit
(ModuleDisplayWindow* InWindow)
{
  auto*              m = (ModuleDisplayBaseWindow*)NULL;
  auto*              foundWindow = (ModuleDisplayBaseWindow*) NULL;
  
  for ( auto i = moduleWindows.begin(); i != moduleWindows.end(); i++ ) {
    m = *i;
    if ( m->GetModuleWindow() == InWindow ) {
      foundWindow = m;
      break;
    }
  }
  if ( foundWindow ) {
    auto s = foundWindow->size();
    auto w = s.width();
    auto w2 = w / 2;
    foundWindow->resize(w2, s.height());
  }
}

/*****************************************************************************!
 * Function : SlotMemberDataEnter
 *****************************************************************************/
void
SaffronBaseWindow::SlotMemberDataEnter
(MemberData* InMemberData)
{
  emit SignalMemberDataEnter(InMemberData);
}

/*****************************************************************************!
 * Function : SlotMemberDataLeave
 *****************************************************************************/
void
SaffronBaseWindow::SlotMemberDataLeave
(MemberData* InMemberData)
{
  emit SignalMemberDataLeave(InMemberData);
}
