/*****************************************************************************
 * FILE NAME    : ProjectDisplayWindow.cpp
 * DATE         : November 24 2022
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
#include "ProjectDisplayWindow.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : ProjectDisplayWindow
 *****************************************************************************/
ProjectDisplayWindow::ProjectDisplayWindow
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(0, 140, 128)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ProjectDisplayWindow
 *****************************************************************************/
ProjectDisplayWindow::~ProjectDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ProjectDisplayWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ProjectDisplayWindow::CreateSubWindows()
{
  windowHeader = new SaffronWindowHeader();  
  windowHeader->setParent(this);
  projectWindow = new ProjectDisplayBodyWindow();
  projectWindow->setParent(this);
}

/*****************************************************************************!
 * Function : CreateConnections 
 *****************************************************************************/
void
ProjectDisplayWindow::CreateConnections
()
{
  connect(this, SIGNAL(SignalProjectOpened(Project*)),
          projectWindow, SLOT(SlotProjectOpened(Project*)));
  connect(projectWindow, SIGNAL(SignalOpenModule(Module*)),
          this, SLOT(SlotOpenModule(Module*)));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ProjectDisplayWindow::InitializeSubWindows()
{
  windowHeader = NULL;  
  projectWindow = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ProjectDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   projectWindowHeight;
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();

  projectWindowHeight = height - SAFFRON_WINDOW_HEADER_HEIGHT;
  if ( windowHeader ) {
    windowHeader->move(0, 0);
    windowHeader->resize(width, SAFFRON_WINDOW_HEADER_HEIGHT);
  }
  if ( projectWindow ) {
    projectWindow->move(0, SAFFRON_WINDOW_HEADER_HEIGHT);
    projectWindow->resize(width, projectWindowHeight);
  }
}

/*****************************************************************************!
 * Function : SlotProjectCreated
 *****************************************************************************/
void
ProjectDisplayWindow::SlotProjectCreated
(QString InProjectName)
{
  windowHeader->SetTitle(InProjectName);
}

/*****************************************************************************!
 * Function : SlotProjectOpened
 *****************************************************************************/
void
ProjectDisplayWindow::SlotProjectOpened
(Project* InProject)
{
  emit SignalProjectOpened(InProject);
  windowHeader->SetTitle(InProject->GetName()->ToString() + " : " + InProject->GetIDString());
}

/*****************************************************************************!
 * Function : SlotOpenModule
 *****************************************************************************/
void
ProjectDisplayWindow::SlotOpenModule
(Module* InModule)
{
  emit SignalOpenModule(InModule);
}
