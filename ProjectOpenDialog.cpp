/*****************************************************************************
 * FILE NAME    : ProjectOpenDialog.cpp
 * DATE         : December 02 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Vertiv Company
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
#include "ProjectOpenDialog.h"
#include "SystemConfig.h"
#include "ProjectInfoList.h"
#include "Trace.h"
#include "main.h"

/*****************************************************************************!
 * Function : ProjectOpenDialog
 *****************************************************************************/
ProjectOpenDialog::ProjectOpenDialog
() : QDialog()
{
  initialize();
}

/*****************************************************************************!
 * Function : ~ProjectOpenDialog
 *****************************************************************************/
ProjectOpenDialog::~ProjectOpenDialog
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ProjectOpenDialog::initialize(void)
{
  projects.Read(mainSystemConfig->GetProjectsBasePath());  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateConnectiona
 *****************************************************************************/
void
ProjectOpenDialog::CreateConnections
()
{
  ActionCancelButtonPushed = new QAction("CancelButtonPushed", this);
  connect(ActionCancelButtonPushed, SIGNAL(triggered()), this, SLOT(SlotCancelButtonPushed()));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ProjectOpenDialog::CreateSubWindows(void)
{
  int                                   y;

  y = 10;  

  //! Create the CancelButton button
  CancelButton = new QPushButton();
  CancelButton->setParent(this);
  CancelButton->setText("Cancel");
  CancelButton->move(10, y);
  CancelButton->resize(50,20);
  connect(CancelButton, SIGNAL(pressed()), this, SLOT(SlotCancelButtonPushed()));

  InfoTable = new ProjectOpenDialogFrame(&projects);
  InfoTable->setParent(this);
  InfoTable->move(10, 40);
  InfoTable->resize(100, 100);
  connect(InfoTable, SIGNAL(SignalSelected(QString)), this, SLOT(SlotSelected(QString)));
}

/*****************************************************************************!
 * Function : SlotCancelButtonPushed
 *****************************************************************************/
void
ProjectOpenDialog::SlotCancelButtonPushed(void)
{
  reject();
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ProjectOpenDialog::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   infoTableWidth;
  int                                   infoTableY;
  int                                   infoTableHeight;
  int                                   cancelButtonX;
  int                                   buttonY;
  int                                   buttonHeight;
  QSize                                 size;  
  int                                   height;
  int                                   width;
  int                                   cancelButtonWidth;
  
  size = InEvent->size();
  height = size.height();
  width = size.width();
  cancelButtonWidth = CancelButton->size().width();
  buttonHeight = CancelButton->size().height();
  cancelButtonX = width - (5 + cancelButtonWidth);
  buttonY = height - ( buttonHeight + 5 );

  CancelButton->move(cancelButtonX, buttonY);
  infoTableY = InfoTable->pos().y();
  infoTableHeight = buttonY - (10 + infoTableY);
  infoTableWidth  = width - 20;
  InfoTable->resize(infoTableWidth, infoTableHeight);
  connect(InfoTable, SIGNAL(SignalSelected(QString)), this, SLOT(SlotSelected(QString)));
}

/*****************************************************************************!
 * Function : SlotSelected
 *****************************************************************************/
void
ProjectOpenDialog::SlotSelected
(QString InInfoName)
{
  infoName = InInfoName;
  accept();
}

/*****************************************************************************!
 * Function : GetInfoName
 *****************************************************************************/
QString
ProjectOpenDialog::GetInfoName(void)
{
  return infoName;
}
