/*****************************************************************************
 * FILE NAME    : SaffronDisplayWindow.cpp
 * DATE         : December 30 2022
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
#include "SaffronDisplayWindow.h"

/*****************************************************************************!
 * Function : SaffronDisplayWindow
 *****************************************************************************/
SaffronDisplayWindow::SaffronDisplayWindow
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~SaffronDisplayWindow
 *****************************************************************************/
SaffronDisplayWindow::~SaffronDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SaffronDisplayWindow::initialize()
{
  useGrid = true;
  displayGrid = false;
  gridSize = 10;
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SaffronDisplayWindow::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SaffronDisplayWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SaffronDisplayWindow::resizeEvent
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

/*****************************************************************************!
 * Function : SlotSetUseGrid
 *****************************************************************************/
void
SaffronDisplayWindow::SlotSetUseGrid
(bool InUseGrid)
{
  useGrid = InUseGrid;
}

/*****************************************************************************!
 * Function : SlotDisplayGrid
 *****************************************************************************/
void
SaffronDisplayWindow::SlotDisplayGrid
(bool InDisplayGrid)
{
  displayGrid = InDisplayGrid;
  repaint();
}

/*****************************************************************************!
 * Function : SnapToGrid
 *****************************************************************************/
QPoint
SaffronDisplayWindow::SnapToGrid
(QPoint InPoint)
{
  int                                   y1;
  int                                   x1;
  int                                   x;
  int                                   y;
  if ( ! useGrid ) {
    return QPoint(InPoint);
  }

  x = InPoint.x();
  y = InPoint.y();

  x1 = x / gridSize;
  y1 = y / gridSize;

  x1 *= gridSize;
  y1 *= gridSize;

  return QPoint(x1, y1);
}

