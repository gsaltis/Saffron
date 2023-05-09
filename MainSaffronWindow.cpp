/*****************************************************************************
 * FILE NAME    : MainSaffronWindow.cpp
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

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainSaffronWindow.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : MainSaffronWindow
 *****************************************************************************/
MainSaffronWindow::MainSaffronWindow
() : QSplitter()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~MainSaffronWindow
 *****************************************************************************/
MainSaffronWindow::~MainSaffronWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainSaffronWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
  setOrientation(Qt::Horizontal);
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainSaffronWindow::CreateSubWindows()
{
  saffronBaseWindow = new SaffronBaseWindow();
  saffronSelectWindow = new SaffronSelectWindow();
  saffronSelectWindow->resize(0, size().height());
  addWidget(saffronSelectWindow);
  addWidget(saffronBaseWindow);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainSaffronWindow::InitializeSubWindows()
{
  saffronBaseWindow = NULL;
  saffronSelectWindow = NULL;
}

/*****************************************************************************!
 * Function : SlotProjectCreated
 *****************************************************************************/
void
MainSaffronWindow::SlotProjectCreated
(QString InProjectName)
{
  emit SignalProjectCreated(InProjectName);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MainSaffronWindow::CreateConnections(void)
{
  connect(this,
          SIGNAL(SignalProjectCreated(QString)),
          saffronBaseWindow,
          SLOT(SlotProjectCreated(QString)));
  
  connect(this,
          SIGNAL(SignalProjectOpened(Project*)),
          saffronBaseWindow,
          SLOT(SlotProjectOpened(Project*)));
  
  connect(this,
          SIGNAL(SignalProjectOpened(Project*)),
          saffronSelectWindow,
          SLOT(SlotProjectOpened(Project*)));

  connect(saffronBaseWindow,
          SIGNAL(SignalMemberDataLeave(MemberData*)),
          this,
          SLOT(SlotMemberDataLeave(MemberData*)));
  
  connect(saffronBaseWindow,
          SIGNAL(SignalMemberDataEnter(MemberData*)),
          this,
          SLOT(SlotMemberDataEnter(MemberData*)));
}

/*****************************************************************************!
 * Function : SlotProjectOpened
 *****************************************************************************/
void
MainSaffronWindow::SlotProjectOpened
(Project* InProject)
{
  emit SignalProjectOpened(InProject);
}

/*****************************************************************************!
 * Function : SlotMemberDataLeave
 *****************************************************************************/
void
MainSaffronWindow::SlotMemberDataLeave
(MemberData* InMemberData)
{
  SignalMemberDataLeave(InMemberData);
}

/*****************************************************************************!
 * Function : SlotMemberDataEnter
 *****************************************************************************/
void
MainSaffronWindow::SlotMemberDataEnter
(MemberData* InMemberData)
{
  SignalMemberDataEnter(InMemberData);
}
