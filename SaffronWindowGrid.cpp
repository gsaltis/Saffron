/*****************************************************************************
 * FILE NAME    : SaffronWindowGrid.cpp
 * DATE         : February 15 2023
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
#include "SaffronWindowGrid.h"

/*****************************************************************************!
 * Function : SaffronWindowGrid
 *****************************************************************************/
SaffronWindowGrid::SaffronWindowGrid
(int InRowCount, int InColumnCount) : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
  rowCount = InRowCount;
  columnCount = InColumnCount;
}

/*****************************************************************************!
 * Function : ~SaffronWindowGrid
 *****************************************************************************/
SaffronWindowGrid::~SaffronWindowGrid
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SaffronWindowGrid::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SaffronWindowGrid::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SaffronWindowGrid::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SaffronWindowGrid::resizeEvent
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
 * Function : AddWidget
 *****************************************************************************/
void
SaffronWindowGrid::AddWidget
(QWidget* InWidget, int InRow, int InColumn)
{
  (void)InWidget;
  if ( rowCount <= InRow || columnCount <= InColumn ) {
    return;
  }
  auto postion = InColumn * InRow + InColumn;
  (void)postion;
  (void)InWidget;
}

/*****************************************************************************!
 * Function : MaximizeWidget
 *****************************************************************************/
void
SaffronWindowGrid::MaximizeWidget
(QWidget* InWidget)
{
  (void)InWidget;
}

/*****************************************************************************!
 * Function : ChangeWidgetSize
 *****************************************************************************/
void
SaffronWindowGrid::ChangeWidgetSize
(QWidget* InWidget, int InMaximized)
{
  (void)InMaximized;
  (void)InWidget;
}


