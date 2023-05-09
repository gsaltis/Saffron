/*****************************************************************************
 * FILE NAME    : SaffronWindowHeader.cpp
 * DATE         : December 01 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QLinearGradient>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronWindowHeader.h"

/*****************************************************************************!
 * Function : SaffronWindowHeader
 *****************************************************************************/
SaffronWindowHeader::SaffronWindowHeader
() : QWidget()
{
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~SaffronWindowHeader
 *****************************************************************************/
SaffronWindowHeader::~SaffronWindowHeader
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SaffronWindowHeader::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SaffronWindowHeader::CreateSubWindows()
{

  //! Create label  
  titleLabel = new QLabel();
  titleLabel->setParent(this);
  titleLabel->move(0, 0);
  titleLabel->resize(300, SAFFRON_WINDOW_HEADER_HEIGHT);
  titleLabel->setText("");
  titleLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
  titleLabel->setFont(QFont("Segoe UI", 14, QFont::Bold));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SaffronWindowHeader::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SaffronWindowHeader::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;
  QPalette                              pal;
  QBrush                                brush;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  titleLabel->resize(width, height);

  QLinearGradient                       grad(QPoint(0, 0), QPoint(0, height));
  grad.setColorAt(0, QColor(192, 192, 192));
  grad.setColorAt(1, QColor(144, 144, 144));
  brush = QBrush(grad);

  pal = palette();
  pal.setBrush(QPalette::Window, brush);
  setPalette(pal);
}

/*****************************************************************************!
 * Function : paintEvent
 *****************************************************************************/
void
SaffronWindowHeader::paintEvent
(QPaintEvent* InEvent)
{
  QPainter                              painter(this);
  QSize                                 s = size();
  QLinearGradient                       grad(QPoint(0, 0), QPoint(0, s.height()));
  QBrush                                brush;
  QPen                                  pen;
  
  grad.setColorAt(0, QColor(192, 192, 192));
  grad.setColorAt(1, QColor(144, 144, 144));

  brush = QBrush(grad);

  pen.setColor(QColor(0, 0, 0, 0));
  painter.setBrush(brush);
  painter.setPen(pen);
  
  painter.drawRect(InEvent->rect());
}

/*****************************************************************************!
 * Function : SetTitle
 *****************************************************************************/
void
SaffronWindowHeader::SetTitle
(QString InTitle)
{
  titleLabel->setText(QString(" ") + InTitle);
}
