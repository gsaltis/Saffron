/*****************************************************************************
 * FILE NAME    : SaffronSelectWindow.cpp
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
#include "SaffronSelectWindow.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : SaffronSelectWindow
 *****************************************************************************/
SaffronSelectWindow::SaffronSelectWindow
() : QFrame()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(176,176,176)));
  setPalette(pal);
  setMaximumWidth(SAFFRON_SELECT_WINDOW_WIDTH);
  setAutoFillBackground(true);
  setFrameShadow(QFrame::Raised);
  setFrameShape(QFrame::Panel);
  setLineWidth(1);
  initialize();
}

/*****************************************************************************!
 * Function : ~SaffronSelectWindow
 *****************************************************************************/
SaffronSelectWindow::~SaffronSelectWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SaffronSelectWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SaffronSelectWindow::CreateSubWindows()
{
  moduleSelect = new ModuleSelectWindow();  
  moduleSelect->hide();
  moduleSelect->setParent(this);

  moduleSelect->AddElement(new ModuleSelectElement("NewModule", "Module", "New Module"));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SaffronSelectWindow::InitializeSubWindows()
{
  moduleSelect = NULL;  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SaffronSelectWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   moduleSelectHeight;
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  moduleSelectHeight = height;

  if ( moduleSelect ) {
    moduleSelect->move(0, 0);
    moduleSelect->resize(width, moduleSelectHeight);
  }
}

/*****************************************************************************!
 * Function : SlotProjectOpened
 *****************************************************************************/
void
SaffronSelectWindow::SlotProjectOpened
(Project* InProject)
{
  emit SignalProjectOpened(InProject);
  moduleSelect->show();
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
SaffronSelectWindow::CreateConnections(void)
{
  connect(this, SIGNAL(SignalProjectOpened(Project*)),
          moduleSelect, SLOT(SlotProjectOpened(Project*)));
}
