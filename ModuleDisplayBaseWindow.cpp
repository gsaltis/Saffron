/*****************************************************************************
 * FILE NAME    : ModuleDisplayBaseWindow.cpp
 * DATE         : January 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
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
#include "ModuleDisplayBaseWindow.h"
#include "Module.h"
#include "main.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : ModuleDisplayBaseWindow
 *****************************************************************************/
ModuleDisplayBaseWindow::ModuleDisplayBaseWindow
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(160, 160, 160)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ModuleDisplayBaseWindow
 *****************************************************************************/
ModuleDisplayBaseWindow::~ModuleDisplayBaseWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleDisplayBaseWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleDisplayBaseWindow::CreateSubWindows()
{
  moduleDisplayWindow = new ModuleDisplayWindow();  
  moduleDisplayWindow->setParent(this);
  moduleDisplayWindow->move(0, SAFFRON_WINDOW_HEADER_HEIGHT);

  moduleMemberDataResizeWindow = new SaffronComponentResizeWindow();
  moduleMemberDataResizeWindow->setParent(this);
  moduleMemberDataResizeWindow->move(0, SAFFRON_WINDOW_HEADER_HEIGHT);
  moduleMemberDataResizeWindow->hide();
  
  header = new SaffronWindowHeader();
  header->setParent(this);
  header->move(0, 0);

  controlBar = new ModuleControlBarWindow();
  controlBar->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleDisplayBaseWindow::InitializeSubWindows()
{
  moduleDisplayWindow = NULL;
  moduleMemberDataResizeWindow = NULL;
  header = NULL;
  controlBar = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ModuleDisplayBaseWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;
  int                                   controlBarW, controlBarH;
  int                                   controlBarX, controlBarY;
  int                                   headerX, headerY, headerW, headerH;
  int                                   displayX, displayY, displayW, displayH;

  size = InEvent->size();
  width = size.width();
  height = size.height();

  headerX = 0;
  headerY = 0;
  headerW = width;
  headerH = SAFFRON_WINDOW_HEADER_HEIGHT;
  
  controlBarX = 0;
  controlBarW = width;
  controlBarH = MODULE_CONTROL_BAR_WINDOW_HEIGHT;
  controlBarY = height - MODULE_CONTROL_BAR_WINDOW_HEIGHT;

  displayX = 0;
  displayY = headerH + WINDOW_GAP_Y;
  displayW = width;
  displayH = height - (headerH + controlBarH + (WINDOW_GAP_Y * 2));

  if ( moduleDisplayWindow ) {
    moduleDisplayWindow->move(displayX, displayY);
    moduleDisplayWindow->resize(displayW, displayH);
  }
  if ( moduleDisplayWindow ) {
    moduleMemberDataResizeWindow->move(displayX, displayY);
    moduleMemberDataResizeWindow->resize(displayW, displayH);
  }
  if ( header ) {
    header->move(headerX, headerY);
    header->resize(headerW, headerH);
  }
  if ( controlBar ) {
    controlBar->move(controlBarX, controlBarY);
    controlBar->resize(controlBarW, controlBarH);
  }
}

/*****************************************************************************!
 * Function : SetModule
 *****************************************************************************/
void
ModuleDisplayBaseWindow::SetModule
(Module* InModule)
{
  moduleDisplayWindow->SetModule(InModule);
  module = InModule;
  header->SetTitle(module->GetName()->ToString() + " : " + module->GetIDString());
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
ModuleDisplayBaseWindow::CreateConnections(void)
{
  connect(controlBar,
          SIGNAL(SignalDataTypeChanged(QString)),
          this,
          SLOT(SlotDataTypeChanged(QString)));

  connect(controlBar,
          SIGNAL(SignalUserDataTypeChanged(QString)),
          this,
          SLOT(SlotUserDataTypeChanged(QString)));

  connect(this,
          SIGNAL(SignalProjectOpened(Project*)),
          controlBar,
          SLOT(SlotProjectOpened(Project*)));
  
  connect(this,
          SIGNAL(SignalDataTypeChanged(QString)),
          moduleDisplayWindow,
          SLOT(SlotDataTypeChanged(QString)));

  connect(moduleDisplayWindow,
          SIGNAL(SignalCloseModuleDisplayWindow()),
          this,
          SLOT(SlotCloseModuleDisplayWindow()));
  connect(moduleDisplayWindow,
          SIGNAL(SignalModuleWindowSplit(ModuleDisplayWindow*)),
          this,
          SLOT(SlotModuleWindowSplit(ModuleDisplayWindow*)));
  connect(moduleDisplayWindow,
          SIGNAL(SignalMemberDataResize(MemberData*)),
          this,
          SLOT(SlotMemberDataResize(MemberData*)));
  connect(moduleDisplayWindow,
          SIGNAL(SignalMemberDataEnter(MemberData*)),
          this,
          SLOT(SlotMemberDataEnter(MemberData*)));

  connect(moduleDisplayWindow,
          SIGNAL(SignalMemberDataLeave(MemberData*)),
          this,
          SLOT(SlotMemberDataLeave(MemberData*)));
}

/*****************************************************************************!
 * Function : SlotDataTypeChanged
 *****************************************************************************/
void
ModuleDisplayBaseWindow::SlotDataTypeChanged
(QString InDataTypeName)
{
  emit SignalDataTypeChanged(InDataTypeName);
}

/*****************************************************************************!
 * Function : SlotCloseModuleDisplayWindow
 *****************************************************************************/
void
ModuleDisplayBaseWindow::SlotCloseModuleDisplayWindow(void)
{
  emit SignalCloseWindow();
}

/*****************************************************************************!
 * Function : SlotModuleWindowSplit
 *****************************************************************************/
void
ModuleDisplayBaseWindow::SlotModuleWindowSplit
(ModuleDisplayWindow* InModuleWindow)
{
  emit(SignalModuleWindowSplit(InModuleWindow));
}

/*****************************************************************************!
 * Function : GetModuleWindow
 *****************************************************************************/
ModuleDisplayWindow*
ModuleDisplayBaseWindow::GetModuleWindow(void)
{
  return moduleDisplayWindow;
}

/*****************************************************************************!
 * Function : SlotMemberDataResize
 *****************************************************************************/
void
ModuleDisplayBaseWindow::SlotMemberDataResize
(MemberData* InMemberData)
{
  moduleMemberDataResizeWindow->SetMemberData(InMemberData);
  moduleMemberDataResizeWindow->show();
}

/*****************************************************************************!
 * Function : SlotMemberDataLeave
 *****************************************************************************/
void
ModuleDisplayBaseWindow::SlotMemberDataLeave
(MemberData* InMemberData)
{
  emit SignalMemberDataLeave(InMemberData);
}

/*****************************************************************************!
 * Function : SlotMemberDataEnter
 *****************************************************************************/
void
ModuleDisplayBaseWindow::SlotMemberDataEnter
(MemberData* InMemberData)
{
  emit SignalMemberDataEnter(InMemberData);  
}

/*****************************************************************************!
 * Function : SlotProjectOpened 
 *****************************************************************************/
void
ModuleDisplayBaseWindow::SlotProjectOpened
(Project* InProject)
{
  project = InProject;
  emit SignalProjectOpened(InProject);
}

/*****************************************************************************!
 * Function : SlotUserDataTypeChanged
 *****************************************************************************/
void
ModuleDisplayBaseWindow::SlotUserDataTypeChanged
(QString InUserDataTypeName)
{
  (void)InUserDataTypeName;
}
