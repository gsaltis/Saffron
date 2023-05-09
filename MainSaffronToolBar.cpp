/*****************************************************************************
 * FILE NAME    : MainSaffronToolBar.cpp
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
#include "MainSaffronToolBar.h"

/*****************************************************************************!
 * Function : MainSaffronToolBar
 *****************************************************************************/
MainSaffronToolBar::MainSaffronToolBar
() : QToolBar()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~MainSaffronToolBar
 *****************************************************************************/
MainSaffronToolBar::~MainSaffronToolBar
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainSaffronToolBar::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainSaffronToolBar::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainSaffronToolBar::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainSaffronToolBar::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
}
