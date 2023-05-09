/*****************************************************************************
 * FILE NAME    : ProjectCreateDialog.cpp
 * DATE         : November 26 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
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
#include "ProjectCreateDialog.h"

/*****************************************************************************!
 * Function : ProjectCreateDialog
 *****************************************************************************/
ProjectCreateDialog::ProjectCreateDialog
(QString InProjectName) : QDialog()
{
  projectName = InProjectName;
  initialize();
}

/*****************************************************************************!
 * Function : ~ProjectCreateDialog
 *****************************************************************************/
ProjectCreateDialog::~ProjectCreateDialog
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ProjectCreateDialog::initialize(void)
{
  CreateSubWindows();  
  ActionOKButtonPushed = new QAction("OKButtonPushed", this);
  connect(ActionOKButtonPushed, SIGNAL(triggered()), this, SLOT(SlotOKButtonPushed()));
  ActionCancelButtonPushed = new QAction("CancelButtonPushed", this);
  connect(ActionCancelButtonPushed, SIGNAL(triggered()), this, SLOT(SlotCancelButtonPushed()));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ProjectCreateDialog::CreateSubWindows(void)
{
  QLabel*                               label;

  //! Create the OKButton button  
  OKButton = new QPushButton();
  OKButton->setParent(this);
  OKButton->setText("Ok");
  OKButton->move(10, 10);
  OKButton->resize(40,20);
  connect(OKButton, SIGNAL(pressed()), this, SLOT(SlotOKButtonPushed()));

  //! Create the CancelButton button
  CancelButton = new QPushButton();
  CancelButton->setParent(this);
  CancelButton->setText("Cancel");
  CancelButton->move(10, 10);
  CancelButton->resize(50,20);
  connect(CancelButton, SIGNAL(pressed()), this, SLOT(SlotCancelButtonPushed()));
  
    //! Create ProjectNameEdit LineEdit
  ProjectNameEdit = new QLineEdit();
  ProjectNameEdit->setParent(this);
  ProjectNameEdit->move(110,10);
  ProjectNameEdit->resize(100,20);
  ProjectNameEdit->setFont(QFont("Segoe UI", 10, QFont::Normal));
  ProjectNameEdit->setText(projectName);
  ProjectNameEdit->setFocus();
  ProjectNameEdit->setSelection(0, -1);
  
  //! Create label
  label = new QLabel();
  label->setParent(this);
  label->move(10, 10);
  label->resize(90, 20);
  label->setText("Project Name :");
  label->setAlignment(Qt::AlignRight);
  label->setFont(QFont("Segoe UI", 10, QFont::Bold));
}

/*****************************************************************************!
 * Function : SlotOKButtonPushed
 *****************************************************************************/
void
ProjectCreateDialog::SlotOKButtonPushed(void)
{
  accept();
}

/*****************************************************************************!
 * Function : SlotCancelButtonPushed
 *****************************************************************************/
void
ProjectCreateDialog::SlotCancelButtonPushed(void)
{
  reject();
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ProjectCreateDialog::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   projectNameX;
  int                                   projectNameWidth;
  int                                   cancelButtonX;
  int                                   okButtonX;
  int                                   buttonY;
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();

  buttonY = height - 25;
  okButtonX = width - 105;
  cancelButtonX = width - 55;
  projectNameX = ProjectNameEdit->pos().x();
  projectNameWidth = width - (projectNameX + 5);
  
  OKButton->move(okButtonX, buttonY);
  CancelButton->move(cancelButtonX, buttonY);
  ProjectNameEdit->resize(projectNameWidth, ProjectNameEdit->size().height());
}

/*****************************************************************************!
 * Function : GetProjectName
 *****************************************************************************/
QString
ProjectCreateDialog::GetProjectName(void)
{
  return ProjectNameEdit->text();
}
