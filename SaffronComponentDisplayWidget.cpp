/*****************************************************************************
 * FILE NAME    : SaffronComponentDisplayWidget.cpp
 * DATE         : December 24 2022
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
#include "SaffronComponentDisplayWidget.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : SaffronComponentDisplayWidget
 *****************************************************************************/
SaffronComponentDisplayWidget::SaffronComponentDisplayWidget
(QString InName) : QSvgWidget()
{
  name = InName;
  initialize();
}

/*****************************************************************************!
 * Function : ~SaffronComponentDisplayWidget
 *****************************************************************************/
SaffronComponentDisplayWidget::~SaffronComponentDisplayWidget
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SaffronComponentDisplayWidget::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : SetName
 *****************************************************************************/
void
SaffronComponentDisplayWidget::SetName
(QString InName)
{
  if ( nameLabel ) {
    nameLabel->setText(InName);
  }
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SaffronComponentDisplayWidget::CreateSubWindows()
{
  //! Create label
  nameLabel = new QLabel();
  nameLabel->setParent(this);
  nameLabel->move(0, 0);
  nameLabel->resize(100, 20);
  nameLabel->setText(name);
  nameLabel->setAlignment(Qt::AlignCenter);
  nameLabel->setFont(QFont("Segoe UI", 12, QFont::Normal));
  nameLabel->setMouseTracking(true);
  
  //! Create label
  nameEdit = new QLineEdit();
  nameEdit->setParent(this);
  nameEdit->move(0, 0);
  nameEdit->resize(130, 30);
  nameEdit->setText(name);
  nameEdit->setAlignment(Qt::AlignCenter);
  nameEdit->setFont(QFont("Segoe UI", 12, QFont::Normal));
  nameEdit->hide();
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SaffronComponentDisplayWidget::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : GetDisplayData
 *****************************************************************************/
SaffronComponentDisplayData*
SaffronComponentDisplayWidget::GetDisplayData()
{
  return displayData;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SaffronComponentDisplayWidget::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  if ( nameLabel ) {
    nameLabel->resize(width, height);
  }
}

/*****************************************************************************!
 * Function : CreateJSON
 *****************************************************************************/
void
SaffronComponentDisplayWidget::CreateJSON
(QJsonObject& InObject)
{
  if ( displayData ) {
    displayData->CreateJSON(InObject);
  }
}

/*****************************************************************************!
 * Function : FromJSON
 *****************************************************************************/
void
SaffronComponentDisplayWidget::FromJSON
(QJsonObject& InObject, QString InTag)
{
  if ( displayData ) {
    displayData->FromJSON(InObject, InTag);
  }
}

/*****************************************************************************!
 * Function : SetSize
 *****************************************************************************/
void
SaffronComponentDisplayWidget::SetSize
(QSize InSize)
{
  displayData->SetSize(InSize);
}

/*****************************************************************************!
 * Function : GetSize
 *****************************************************************************/
QSize
SaffronComponentDisplayWidget::GetSize
()
{
  return displayData->GetSize();
}

/*****************************************************************************!
 * Function : ReplaceDisplayData
 *****************************************************************************/
void
SaffronComponentDisplayWidget::ReplaceDisplayData
(SaffronComponentDisplayData* InDisplayData)
{
  if ( NULL == InDisplayData ) {
    return;
  }

  delete displayData;
  displayData = InDisplayData;
}
