/*****************************************************************************
 * FILE NAME    : ProjectOpenDialogFrame.cpp
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
#include "ProjectOpenDialogFrame.h"
#include "ProjectOpenDialogElement.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : ProjectOpenDialogFrame
 *****************************************************************************/
ProjectOpenDialogFrame::ProjectOpenDialogFrame
(ProjectInfoList* InInfoList) : QFrame()
{
  QPalette pal;
  pal = palette();

  projectInfoList = InInfoList;
  pal.setBrush(QPalette::Window, QBrush(QColor(128, 128, 128)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ProjectOpenDialogFrame
 *****************************************************************************/
ProjectOpenDialogFrame::~ProjectOpenDialogFrame
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ProjectOpenDialogFrame::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ProjectOpenDialogFrame::CreateSubWindows()
{
  ProjectOpenDialogElement*             infoEntry;
  int                                   y;
  int                                   i, n;

  y = 0;
  n = projectInfoList->GetCount();
  for ( i = 0 ; i < n ; i++ ) {
    ProjectInfo*                        info;

    info = projectInfoList->GetInfoByIndex(i);
    infoEntry = new ProjectOpenDialogElement(info, i + 1);
    infoEntry->setParent(this);
    infoEntry->move(0, y);
    infoEntry->resize(100, PROJECT_OPEN_DIALOG_ELEMENT_HEIGHT);
    y += PROJECT_OPEN_DIALOG_ELEMENT_HEIGHT;
    connect(infoEntry, SIGNAL(SignalSelected(QString)),
            this, SLOT(SlotElementSelected(QString)));
    Entries << infoEntry;
  }
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ProjectOpenDialogFrame::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ProjectOpenDialogFrame::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   i, n;
  ProjectOpenDialogElement*             infoEntry;
  
  size = InEvent->size();
  width = size.width();

  n = Entries.count();
  for ( i = 0; i < n ; i++ ) {
    infoEntry = Entries[i];
    infoEntry->resize(width, PROJECT_OPEN_DIALOG_ELEMENT_HEIGHT);
  }
  (void)width;
}

/*****************************************************************************!
 * Function : paintEvent
 *****************************************************************************/
void
ProjectOpenDialogFrame::paintEvent
(QPaintEvent* InEvent)
{
  QPainter                              painter(this);
  QSize                                 s = size();
  QLinearGradient                       grad(QPoint(0, 0), QPoint(0, s.height()));
  QBrush                                brush;
  QPen                                  pen;
  
  grad.setColorAt(0, QColor(224, 224, 224));
  grad.setColorAt(1, QColor(224, 224, 224));

  brush = QBrush(grad);

  pen.setColor(QColor(0, 0, 0, 0));
  painter.setBrush(brush);
  painter.setPen(pen);

  painter.drawRect(InEvent->rect());
}

/*****************************************************************************!
 * Function : SlotElementSelected
 *****************************************************************************/
void
ProjectOpenDialogFrame::SlotElementSelected
(QString InInfoName)
{
  emit(SignalSelected(InInfoName));
}
