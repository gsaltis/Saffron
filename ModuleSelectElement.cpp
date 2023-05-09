/*****************************************************************************
 * FILE NAME    : ModuleSelectElement.cpp
 * DATE         : December 09 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Vertiv Company
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ModuleSelectElement.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : ModuleSelectElement
 *****************************************************************************/
ModuleSelectElement::ModuleSelectElement
(QString InName, QString InType, QString InLabel) : QFrame()
{
  name = InName;
  type = InType;
  label= InLabel;
  initialize();
}

/*****************************************************************************!
 * Function : ~ModuleSelectElement
 *****************************************************************************/
ModuleSelectElement::~ModuleSelectElement
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleSelectElement::initialize()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  setCursor(Qt::PointingHandCursor);
  InitializeSubWindows();
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleSelectElement::CreateSubWindows()
{
  //! Create label
  this->resize(100, MODULE_SELECT_ELEMENT_HEIGHT);
  nameLabel = new QLabel();
  nameLabel->setParent(this);
  nameLabel->move(0, 0);
  nameLabel->resize(100, MODULE_SELECT_ELEMENT_HEIGHT);
  nameLabel->setText(label);
  nameLabel->setAlignment(Qt::AlignCenter);
  nameLabel->setFont(QFont("Segoe UI", 10, QFont::Bold));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleSelectElement::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ModuleSelectElement::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;

  size = InEvent->size();
  width = size.width();

  nameLabel->resize(width, MODULE_SELECT_ELEMENT_HEIGHT);
  (void)width;
}

/*****************************************************************************!
 * Function : paintEvent
 *****************************************************************************/
void
ModuleSelectElement::paintEvent
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
 * Function : mousePressEvent
 *****************************************************************************/
void
ModuleSelectElement::mousePressEvent
(QMouseEvent *event)
{
  QPixmap                       iconPixmap(":/images/NewModule.png");
  if (event->button() == Qt::LeftButton
      && nameLabel->geometry().contains(event->pos())) {
    
    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    
    mimeData->setText(type + QString("/") + name + QString("/") + label);
    drag->setMimeData(mimeData);
    drag->setPixmap(iconPixmap);
    
    Qt::DropAction dropAction = drag->exec();
    (void)dropAction;
  }
}
