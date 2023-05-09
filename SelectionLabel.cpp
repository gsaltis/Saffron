/*****************************************************************************
 * FILE NAME    : SelectionLabel.cpp
 * DATE         : December 05 2022
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
#include "SelectionLabel.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : SelectionLabel
 *****************************************************************************/
SelectionLabel::SelectionLabel
() : QLabel()
{
  QPalette pal;
  setMouseTracking(true);
  pal = palette();
  currentBrush = QBrush(QColor(224, 224, 224, 0));
  pal.setBrush(QPalette::Window, currentBrush);
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~SelectionLabel
 *****************************************************************************/
SelectionLabel::~SelectionLabel
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SelectionLabel::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SelectionLabel::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SelectionLabel::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SelectionLabel::resizeEvent
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
 * Function : mousePressEvent
 *****************************************************************************/
void
SelectionLabel::mousePressEvent
(QMouseEvent* InEvent)
{
  emit SignalSelected();
  (void)InEvent;
}

/*****************************************************************************!
 * Function : leaveEvent
 *****************************************************************************/
void
SelectionLabel::leaveEvent
(QEvent* InEvent)
{
  (void)InEvent;
  emit SignalHoverOff();
}

/*****************************************************************************!
 * Function : enterEvent
 *****************************************************************************/
void
SelectionLabel::enterEvent
(QEnterEvent* InEvent)
{
  (void)InEvent;  
  emit SignalHoverOn();
}

/*****************************************************************************!
 * Function : SlotHoverOn
 *****************************************************************************/
void
SelectionLabel::SlotHoverOn(void)
{
}

/*****************************************************************************!
 * Function : SlotHoverOff
 *****************************************************************************/
void
SelectionLabel::SlotHoverOff(void)
{
}

/*****************************************************************************!
 * Function : SlotSelect
 *****************************************************************************/
void
SelectionLabel::SlotSelect(void)
{

}

/*****************************************************************************!
 * Function : SlotDeSelect
 *****************************************************************************/
void
SelectionLabel::SlotDeSelect(void)
{

  
}
