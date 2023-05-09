/*****************************************************************************
 * FILE NAME    : SaffronComponentResizeWindow.cpp
 * DATE         : February 26 2023
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
#include "SaffronComponentResizeWindow.h"
#include "trace.h"
#include "MemberDataResizeMimeData.h"

/*****************************************************************************!
 * Function : SaffronComponentResizeWindow
 *****************************************************************************/
SaffronComponentResizeWindow::SaffronComponentResizeWindow
() : SaffronDisplayWindow()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(192, 192, 255, 64)));
  setAcceptDrops(true);
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~SaffronComponentResizeWindow
 *****************************************************************************/
SaffronComponentResizeWindow::~SaffronComponentResizeWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SaffronComponentResizeWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SaffronComponentResizeWindow::CreateSubWindows()
{
  resizeHandle = new SaffronComponentResizeHandle(this, NULL);
  resizeHandle->move(100, 100);

  resizeFrame = new QFrame(this);
  resizeFrame->setFrameShape(QFrame::Panel);
  resizeFrame->setFrameShadow(QFrame::Raised);
  resizeFrame->move(100, 100);
  resizeFrame->resize(10, 10);
  
  auto pal = resizeHandle->palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(0, 0, 0, 128)));
  resizeHandle->setPalette(pal);
  resizeHandle->setAutoFillBackground(true);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SaffronComponentResizeWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SaffronComponentResizeWindow::resizeEvent
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
 * Function : SetMemberData
 *****************************************************************************/
void
SaffronComponentResizeWindow::SetMemberData
(MemberData* InMemberData)
{
  MemberDataDisplayWidget*              widget;
  QPoint                                p, p2;
  QSize                                 s, s2;
  
  memberData = InMemberData;

  widget = memberData->GetDisplay();

  p = widget->pos();
  s = widget->size();
  p2 = p;
  s2 = resizeHandle->size();
  p2 += QPoint(s.width() - s2.width() / 2, s.height() - s2.height() / 2);
  resizeHandle->SetMemberData(InMemberData);
  resizeHandle->move(p2);
  resizeFrame->move(p);
  resizeFrame->resize(s);
  
}

/*****************************************************************************!
 * Function : keyPressEvent 
 *****************************************************************************/
void
SaffronComponentResizeWindow::keyPressEvent
(QKeyEvent* InEvent)
{
  int                                   key;
  Qt::KeyboardModifiers                 mods;

  key = InEvent->key();
  mods = InEvent->modifiers();

  (void)key;
  (void)mods;
  if ( mods == 0 ) {
    if ( key == Qt::Key_Escape ) {
      AbortResize();
    }
  }
}

/*****************************************************************************!
 * Function : dragEnterEvent
 *****************************************************************************/
void
SaffronComponentResizeWindow::dragEnterEvent
(QDragEnterEvent *InEvent)
{
  InEvent->acceptProposedAction();
}

/*****************************************************************************!
 * Function : dropEvent
 *****************************************************************************/
void
SaffronComponentResizeWindow::dropEvent
(QDropEvent *InEvent)
{
  FinishResize();
  (void)InEvent;
}

/*****************************************************************************!
 * Function : dragMoveEvent
 *****************************************************************************/
void
SaffronComponentResizeWindow::dragMoveEvent
(QDragMoveEvent* InEvent)
{
  QPoint                                p, p2;
  QList<QString>                        elements;
  QString                               fullname;
  QPoint                                pos;
  QString                               action;
  MemberDataResizeMimeData*             mimeData;
  int                                   width, height;
  MemberDataDisplayWidget*              displayWidget;
  
  mimeData = (MemberDataResizeMimeData*)InEvent->mimeData();

  if ( NULL == mimeData ) {
    return;
  }

  if ( ! mimeData->hasText() ) {
    return;
  }

  displayWidget = memberData->GetDisplay();
  fullname = mimeData->text();
  elements = fullname.split("/");
  action = elements[0];
  if ( action == "MemberDataResize" ) {
    pos = InEvent->position().toPoint();
    p = SnapToGrid(pos);
    resizeHandle->move(p);
    p2 = resizeFrame->pos();
    width = p.x() - p2.x();
    height = p.y() - p2.y();
    if ( width > 0 && height > 0 ) {
      resizeFrame->resize(width, height);
      displayWidget->resize(width, height);
    }
    
    InEvent->accept();
  }
}

/*****************************************************************************!
 * Function : mousePressEvent
 *****************************************************************************/
void
SaffronComponentResizeWindow::mousePressEvent
(QMouseEvent* InEvent)
{
  (void)InEvent;
}

/*****************************************************************************!
 * Function : mouseMoveEvent
 *****************************************************************************/
void
SaffronComponentResizeWindow::mouseMoveEvent
(QMouseEvent* InEvent)
{
  (void)InEvent;
}


/*****************************************************************************!
 * Function : AbortResize
 *****************************************************************************/
void
SaffronComponentResizeWindow::AbortResize(void)
{
  hide();
}

/*****************************************************************************!
 * Function : FinishResize
 *****************************************************************************/
void
SaffronComponentResizeWindow::FinishResize(void)
{
  memberData->SetSize(resizeFrame->size());
  memberData->SaveConfigFile();
  hide();
}
