/*****************************************************************************
 * FILE NAME    : MainSaffronWindowContainer.cpp
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
#include "MainSaffronWindowContainer.h"
#include "Trace.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/
#define WINDOW_MARGIN_HORIZONTAL        0
#define WINDOW_MARGIN_VERTICAL          0

/*****************************************************************************!
 * Function : MainSaffronWindowContainer
 *****************************************************************************/
MainSaffronWindowContainer::MainSaffronWindowContainer
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(128, 128, 128)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~MainSaffronWindowContainer
 *****************************************************************************/
MainSaffronWindowContainer::~MainSaffronWindowContainer
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainSaffronWindowContainer::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainSaffronWindowContainer::CreateSubWindows()
{
  mainSaffronWindow = new MainSaffronWindow();  
  mainSaffronWindow->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainSaffronWindowContainer::InitializeSubWindows()
{
  mainSaffronWindow = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainSaffronWindowContainer::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  if ( mainSaffronWindow ) {
    mainSaffronWindow->move(WINDOW_MARGIN_HORIZONTAL, WINDOW_MARGIN_VERTICAL);
    mainSaffronWindow->resize(width - (WINDOW_MARGIN_HORIZONTAL * 2),
                              height - (WINDOW_MARGIN_VERTICAL * 2));
  }
}

/*****************************************************************************!
 * Function : SlotProjectCreated
 *****************************************************************************/
void
MainSaffronWindowContainer::SlotProjectCreated
(QString InProjectName)
{
  emit SignalProjectCreated(InProjectName);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MainSaffronWindowContainer::CreateConnections(void)
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
MainSaffronWindowContainer::SlotProjectOpened
(Project* InProject)
{
  emit SignalProjectOpened(InProject);
}

/*****************************************************************************!
 * Function : SlotMemberDataEnter
 *****************************************************************************/
void
MainSaffronWindowContainer::SlotMemberDataEnter
(MemberData* InMemberData)
{
  emit SignalMemberDataEnter(InMemberData);
}

/*****************************************************************************!
 * Function : SlotMemberDataLeave
 *****************************************************************************/
void
MainSaffronWindowContainer::SlotMemberDataLeave
(MemberData* InMemberData)
{
  emit SignalMemberDataLeave(InMemberData);
}
