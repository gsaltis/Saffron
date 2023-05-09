/*****************************************************************************
 * FILE NAME    : SaffronToolBarButtonWindow.cpp
 * DATE         : November 25 2022
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
#include "SaffronToolBarButtonWindow.h"

/*****************************************************************************!
 * Function : SaffronToolBarButtonWindow
 *****************************************************************************/
SaffronToolBarButtonWindow::SaffronToolBarButtonWindow
() : QPushButton()
{
  Initialize();
}

/*****************************************************************************!
 * Function : SaffronToolBarButtonWindow
 *****************************************************************************/
SaffronToolBarButtonWindow::SaffronToolBarButtonWindow
(QString InName, QString InImageName)
{
  Initialize();
  name = QString(InName);
  imageName = QString(InImageName);
}

/*****************************************************************************!
 * Function : ~SaffronToolBarButtonWindow
 *****************************************************************************/
SaffronToolBarButtonWindow::~SaffronToolBarButtonWindow
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
SaffronToolBarButtonWindow::Initialize()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);

  name = QString();
  imageName = QString();
  
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SaffronToolBarButtonWindow::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SaffronToolBarButtonWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SaffronToolBarButtonWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
}
