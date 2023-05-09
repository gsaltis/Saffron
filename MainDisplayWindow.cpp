/*****************************************************************************
 * FILE NAME    : MainDisplayWindow.cpp
 * DATE         : November 15 2022
 * PROJECT      : Saffron
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
#include "MainDisplayWindow.h"
#include "Trace.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/
#define WINDOW_MARGIN_HORIZONTAL                0
#define WINDOW_MARGIN_VERTICAL                  0
#define MESSAGE_BAR_HEIGHT                      25

/*****************************************************************************!
 * Function : MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::MainDisplayWindow
() : QWidget()
{
  QPalette                              pal;

  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(32, 32, 32)));
  setPalette(pal);
  setAutoFillBackground(true);

  Initialize();
}

/*****************************************************************************!
 * Function : ~MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::~MainDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
MainDisplayWindow::Initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainDisplayWindow::InitializeSubWindows()
{
  mainSaffronWindow = NULL;
  saffronToolBar = NULL;
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainDisplayWindow::CreateSubWindows()
{
  mainSaffronWindow = new MainSaffronWindowContainer();  
  mainSaffronWindow->setParent(this);
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   mainSaffronWindowX;
  int                                   mainSaffronWindowY;
  int                                   mainSaffronWindowWidth;
  int                                   mainSaffronWindowHeight;
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();

  mainSaffronWindowHeight = height;
  mainSaffronWindowWidth  = width;
  mainSaffronWindowY = WINDOW_MARGIN_VERTICAL;
  mainSaffronWindowX = WINDOW_MARGIN_HORIZONTAL;
  
  if ( mainSaffronWindow ) {
    mainSaffronWindow->move(mainSaffronWindowX, mainSaffronWindowY);
    mainSaffronWindow->resize(mainSaffronWindowWidth, mainSaffronWindowHeight); 
  }
}

/*****************************************************************************!
 * Function : SlotProjectCreated
 *****************************************************************************/
void
MainDisplayWindow::SlotProjectCreated
(QString InProjectName)
{
  emit SignalProjectCreated(InProjectName);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MainDisplayWindow::CreateConnections(void)
{
  connect(this,
          SIGNAL(SignalProjectCreated(QString)),
          mainSaffronWindow,
          SLOT(SlotProjectCreated(QString)));

  connect(this,
          SIGNAL(SignalProjectOpened(Project*)),
          mainSaffronWindow,
          SLOT(SlotProjectOpened(Project*)));

  connect(mainSaffronWindow,
          SIGNAL(SignalMemberDataEnter(MemberData*)),
          this,
          SLOT(SlotMemberDataEnter(MemberData*)));
  connect(mainSaffronWindow,
          SIGNAL(SignalMemberDataLeave(MemberData*)),
          this,
          SLOT(SlotMemberDataLeave(MemberData*)));
}

/*****************************************************************************!
 * Function : SlotProjectOpened
 *****************************************************************************/
void
MainDisplayWindow::SlotProjectOpened
(Project* InProject)
{
  emit SignalProjectOpened(InProject);
}

/*****************************************************************************!
 * Function : SlotMemberDataEnter
 *****************************************************************************/
void
MainDisplayWindow::SlotMemberDataEnter
(MemberData* InMemberData)
{
  emit SignalMemberDataEnter(InMemberData);
}

/*****************************************************************************!
 * Function : SlotMemberDataLeave
 *****************************************************************************/
void
MainDisplayWindow::SlotMemberDataLeave
(MemberData* InMemberData)
{
  emit SignalMemberDataLeave(InMemberData);
}
