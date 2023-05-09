/*****************************************************************************
 * FILE NAME    : SaffronComponentResizeBoundingBox.cpp
 * DATE         : December 23 2022
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
#include "SaffronComponentResizeBoundingBox.h"

/*****************************************************************************!
 * Function : SaffronComponentResizeBoundingBox
 *****************************************************************************/
SaffronComponentResizeBoundingBox::SaffronComponentResizeBoundingBox
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
 * Function : ~SaffronComponentResizeBoundingBox
 *****************************************************************************/
SaffronComponentResizeBoundingBox::~SaffronComponentResizeBoundingBox
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SaffronComponentResizeBoundingBox::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SaffronComponentResizeBoundingBox::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SaffronComponentResizeBoundingBox::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SaffronComponentResizeBoundingBox::resizeEvent
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
