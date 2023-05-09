/*****************************************************************************
 * FILE NAME    : SaffronComponentResizeHandle.cpp
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
#include "SaffronComponentResizeHandle.h"
#include "MemberMimeData.h"
#include "MemberDataResizeMimeData.h"

/*****************************************************************************!
 * Function : SaffronComponentResizeHandle
 *****************************************************************************/
SaffronComponentResizeHandle::SaffronComponentResizeHandle
(QWidget* InParent, MemberData* InMemberData) : QFrame(InParent)
{
  QPalette pal;

  memberData = InMemberData;  
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  setFrameShape(QFrame::Panel);
  setFrameShadow(QFrame::Raised);
  resize(10, 10);
  setCursor(Qt::PointingHandCursor);
  initialize();
}

/*****************************************************************************!
 * Function : ~SaffronComponentResizeHandle
 *****************************************************************************/
SaffronComponentResizeHandle::~SaffronComponentResizeHandle
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SaffronComponentResizeHandle::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SaffronComponentResizeHandle::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SaffronComponentResizeHandle::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SaffronComponentResizeHandle::resizeEvent
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
SaffronComponentResizeHandle::mousePressEvent
(QMouseEvent* InEvent)
{
  QPoint                                p;
  QPixmap                               iconPixmap(1, 1);

  iconPixmap.fill(QColor(0, 0, 0, 0));
  if (InEvent->button() == Qt::LeftButton ) {
    QDrag *drag = new QDrag(this);
    MemberDataResizeMimeData *mimeData = new MemberDataResizeMimeData(this, memberData);
    
    mimeData->setText(QString("MemberDataResize/MemberData/MemberData"));
    drag->setMimeData(mimeData);
    drag->setPixmap(iconPixmap);
    Qt::DropAction dropAction = drag->exec();
    (void)dropAction;
  }
}

/*****************************************************************************!
 * Function : SetMemberData
 *****************************************************************************/
void
SaffronComponentResizeHandle::SetMemberData
(MemberData* InMemberData)
{
  memberData = InMemberData;
}
