/*****************************************************************************
 * FILE NAME    : ProjectOpenDialogElement.cpp
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
#include <QFrame>
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ProjectOpenDialogElement.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : ProjectOpenDialogElement
 *****************************************************************************/
ProjectOpenDialogElement::ProjectOpenDialogElement
(ProjectInfo* InInfo, int InIndex) : QFrame()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(224, 224, 224)));
  setPalette(pal);
  setAutoFillBackground(true);
  info = InInfo;
  index = InIndex;
  initialize();
}

/*****************************************************************************!
 * Function : ~ProjectOpenDialogElement
 *****************************************************************************/
ProjectOpenDialogElement::~ProjectOpenDialogElement
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ProjectOpenDialogElement::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ProjectOpenDialogElement::CreateSubWindows()
{
  SelectionLabel*                       label;

  //! Create label  
  label = new SelectionLabel();
  label->setParent(this);
  label->move(0, 0);
  label->resize(35, 25);
  label->setText(QString("%1").arg(index));
  label->setAlignment(Qt::AlignRight);
  label->setFont(QFont("Segoe UI", 10, QFont::Normal));
  connect(label, SIGNAL(SignalHoverOff()), this, SLOT(SlotHoverOff()));
  connect(label, SIGNAL(SignalHoverOn()), this, SLOT(SlotHoverOn()));
  connect(label, SIGNAL(SignalSelected()), this, SLOT(SlotSelected()));
  connect(this, SIGNAL(SignalHoverOff()), label, SLOT(SlotHoverOff()));
  connect(this, SIGNAL(SignalHoverOn()), label, SLOT(SlotHoverOn()));

  //! Create label  
  label = new SelectionLabel();
  label->setParent(this);
  label->move(45, 0);
  label->resize(100, 25);
  label->setText(info->GetName());
  label->setAlignment(Qt::AlignLeft);
  label->setFont(QFont("Segoe UI", 10, QFont::Normal));
  connect(label, SIGNAL(SignalHoverOff()), this, SLOT(SlotHoverOff()));
  connect(label, SIGNAL(SignalHoverOn()), this, SLOT(SlotHoverOn()));
  connect(label, SIGNAL(SignalSelected()), this, SLOT(SlotSelected()));
  connect(this, SIGNAL(SignalHoverOff()), label, SLOT(SlotHoverOff()));
  connect(this, SIGNAL(SignalHoverOn()), label, SLOT(SlotHoverOn()));

  //! Create label  
  label = new SelectionLabel();
  label->setParent(this);
  label->move(150, 0);
  label->resize(270, 25);
  label->setText(info->GetDescription());
  label->setAlignment(Qt::AlignLeft);
  label->setFont(QFont("Segoe UI", 10, QFont::Normal));
  connect(label, SIGNAL(SignalHoverOff()), this, SLOT(SlotHoverOff()));
  connect(label, SIGNAL(SignalHoverOn()), this, SLOT(SlotHoverOn()));
  connect(label, SIGNAL(SignalSelected()), this, SLOT(SlotSelected()));
  connect(this, SIGNAL(SignalHoverOff()), label, SLOT(SlotHoverOff()));
  connect(this, SIGNAL(SignalHoverOn()), label, SLOT(SlotHoverOn()));

  //! Create label  
  dateTimeLabel = new SelectionLabel();
  dateTimeLabel->setParent(this);
  dateTimeLabel->move(420, 0);
  dateTimeLabel->resize(160, 25);
  dateTimeLabel->setText(info->GetDateTime().toString("MMM dd yyyy  hh:mm:ss ap"));
  dateTimeLabel->setAlignment(Qt::AlignLeft);
  dateTimeLabel->setFont(QFont("Segoe UI", 10, QFont::Normal));
  connect(dateTimeLabel, SIGNAL(SignalHoverOff()), this, SLOT(SlotHoverOff()));
  connect(dateTimeLabel, SIGNAL(SignalHoverOn()), this, SLOT(SlotHoverOn()));
  connect(dateTimeLabel, SIGNAL(SignalSelected()), this, SLOT(SlotSelected()));
  connect(this, SIGNAL(SignalHoverOff()), dateTimeLabel, SLOT(SlotHoverOff()));
  connect(this, SIGNAL(SignalHoverOn()), dateTimeLabel, SLOT(SlotHoverOn()));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ProjectOpenDialogElement::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ProjectOpenDialogElement::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   dateTimeLabelX;
  int                                   dateTimeLabelHeight;
  
  size = InEvent->size();
  width = size.width();

  dateTimeLabelX = dateTimeLabel->pos().x();
  dateTimeLabelHeight = dateTimeLabel->size().height();
  dateTimeLabel->resize(width - dateTimeLabelX, dateTimeLabelHeight);
}

/*****************************************************************************!
 * Function : SlotHoverOff
 *****************************************************************************/
void
ProjectOpenDialogElement::SlotHoverOff(void)
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(224, 224, 224)));
  pal.setBrush(QPalette::WindowText, QBrush(QColor(0, 0, 0)));
  setPalette(pal);
}

/*****************************************************************************!
 * Function : SlotHoverOn
 *****************************************************************************/
void
ProjectOpenDialogElement::SlotHoverOn(void)
{ 
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(0, 0, 0)));
  pal.setBrush(QPalette::WindowText, QBrush(QColor(240, 240, 240)));
  setPalette(pal);
}


/*****************************************************************************!
 * Function : SlotSelected
 *****************************************************************************/
void
ProjectOpenDialogElement::SlotSelected(void)
{
  emit SignalSelected(info->GetName());
}

