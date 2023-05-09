/*****************************************************************************
 * FILE NAME    : ModuleSelectWindow.cpp
 * DATE         : November 21 2022
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
#include "ModuleSelectWindow.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : ModuleSelectWindow
 *****************************************************************************/
ModuleSelectWindow::ModuleSelectWindow
() : QWidget()
{
  QPalette                              pal;
  QLinearGradient                       grad;

  grad.setColorAt(0, QColor(160, 160, 160));
  grad.setColorAt(1, QColor(240, 240, 240));
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(grad));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ModuleSelectWindow
 *****************************************************************************/
ModuleSelectWindow::~ModuleSelectWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleSelectWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleSelectWindow::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleSelectWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ModuleSelectWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   n;
  int                                   h;
  QSize                                 size;  
  int                                   width;
  ModuleSelectElement*                  element;

  size = InEvent->size();
  width = size.width();
  n = elements.count();
  for ( int i = 0 ; i < n; i++ ) {
    element = elements[i];
    h = element->size().height();
    element->resize(width-2, h);
  }
}

/*****************************************************************************!
 * Function : paintEvent
 *****************************************************************************/
void
ModuleSelectWindow::paintEvent
(QPaintEvent* InEvent)
{
  QPainter                              painter(this);
  QSize                                 s = size();
  QLinearGradient                       grad(QPoint(0, 0), QPoint(0, s.height()));
  QBrush                                brush;
  QPen                                  pen;
  
  grad.setColorAt(0, QColor(160, 160, 160));
  grad.setColorAt(1, QColor(240, 240, 240));

  pen = QPen(QColor(0, 0, 0, 0));
  brush = QBrush(grad);

  painter.setBrush(brush);
  painter.setPen(pen);
  painter.drawRect(InEvent->rect());
}

/*****************************************************************************!
 * Function : AddElement
 *****************************************************************************/
void
ModuleSelectWindow::AddElement
(ModuleSelectElement* InElement)
{
  int                                   w;
  int                                   h;
  int                                   y;
  if ( NULL == InElement ) {
    return;
  }
  h = InElement->size().height();
  y = FindLastElementY();
  if ( elements.count() > 0 ) {
    y += h;
  }
  w = size().width();
  InElement->setParent(this);
  InElement->move(0, y);

  elements << InElement;
  InElement->resize(w-5, h);
}

/*****************************************************************************!
 * Function : FindLastElementY
 *****************************************************************************/
int
ModuleSelectWindow::FindLastElementY(void)
{
  int                                   n;
  int                                   lastY;
  int                                   y;
  ModuleSelectElement*                  element;
  
  lastY = 0;
  n = elements.count();
  
  for ( int i = 0 ; i < n; i++ ) {
    element = elements[i];
    y = element->pos().y();
    if ( lastY < y ) {
      lastY = y;
    }
  }
  return lastY;
}

/*****************************************************************************!
 * Function : SlotProjectOpened
 *****************************************************************************/
void
ModuleSelectWindow::SlotProjectOpened
(Project* InProject)
{
  (void)InProject;
}

