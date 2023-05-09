/*****************************************************************************
 * FILE NAME    : SaffronToolBarWindow.cpp
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
#include "SaffronToolBarWindow.h"

/*****************************************************************************!
 * Function : SaffronToolBarWindow
 *****************************************************************************/
SaffronToolBarWindow::SaffronToolBarWindow
() : QFrame()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(224, 224, 224)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~SaffronToolBarWindow
 *****************************************************************************/
SaffronToolBarWindow::~SaffronToolBarWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SaffronToolBarWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SaffronToolBarWindow::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SaffronToolBarWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SaffronToolBarWindow::resizeEvent
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
 * Function : paintEvent
 *****************************************************************************/
void
SaffronToolBarWindow::paintEvent
(QPaintEvent* InEvent)
{
  QPen                                  darkPen;
  QPen                                  lightPen;
  QPainter                              painter(this);
  QRect                                 r;
    
  r = InEvent->rect();
  
  lightPen = QPen(QBrush(QColor(192, 192, 192)), 1);
  darkPen = QPen(QBrush(QColor(64, 64, 64)), 1);
  
  painter.setPen(lightPen);
  painter.drawLine(1, 1, r.right(), 1);
  painter.drawLine(r.right(), 1, r.right(), r.bottom());

  painter.setPen(darkPen);
  painter.drawLine(1, r.bottom(), r.right(), r.bottom());
  painter.drawLine(1, 1, 1, r.bottom());
}
