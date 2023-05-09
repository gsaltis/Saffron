/*****************************************************************************
 * FILE NAME    : ModuleCreateDialog.cpp
 * DATE         : December 09 2022
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
#include <QLineEdit>
#include <QTextEdit>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ModuleCreateDialog.h"

/*****************************************************************************!
 * Function : ModuleCreateDialog
 *****************************************************************************/
ModuleCreateDialog::ModuleCreateDialog
(QString InName, QString InDescription) : QDialog()
{
  initialize();
  name = InName;
  description = InDescription;
}

/*****************************************************************************!
 * Function : ~ModuleCreateDialog
 *****************************************************************************/
ModuleCreateDialog::~ModuleCreateDialog
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleCreateDialog::initialize(void)
{
  setWindowTitle("Module Create");
  resize(MODULE_CREATE_DIALOG_WIDTH, MODULE_CREATE_DIALOG_HEIGHT);
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
ModuleCreateDialog::CreateSubWindows(void)
{
  int                                   nameEditWidth;
  int                                   nameEditX;
  QLabel*                               label;
  int                                   y;
  int                                   labelX;
  int                                   okButtonWidth;
  int                                   cancelButtonWidth;
  int                                   okButtonX;
  int                                   cancelButtonX;
  int                                   buttonY;
  int                                   buttonHeight;
  int                                   buttonGap;
  int                                   labelWidth;
  
  buttonGap = 5;
  buttonHeight = 20;
  
  buttonY = MODULE_CREATE_DIALOG_HEIGHT - (buttonHeight + buttonGap);
  okButtonWidth = 50;
  cancelButtonWidth = 60;
  okButtonX = MODULE_CREATE_DIALOG_WIDTH - (okButtonWidth + cancelButtonWidth + (buttonGap * 2));
  cancelButtonX = okButtonX + okButtonWidth + buttonGap;
  labelWidth = 160;
  labelX = 10;
  nameEditX = labelX + labelWidth + buttonGap;
  nameEditWidth = MODULE_CREATE_DIALOG_WIDTH - (nameEditX + buttonGap);
  
  y = 10;
  //! Create label
  label = new QLabel();
  label->setParent(this);
  label->move(labelX, y);
  label->resize(labelWidth,20);
  label->setText("Module Name");
  label->setAlignment(Qt::AlignRight);
  label->setFont(QFont("Segoe UI", 10, QFont::Bold));
  
    //! Create nameEdit LineEdit
  nameEdit = new QLineEdit();
  nameEdit->setParent(this);
  nameEdit->move(nameEditX, y);
  nameEdit->resize(nameEditWidth, 20);
  nameEdit->setFont(QFont("Segoe UI", 10, QFont::Bold));
  nameEdit->setText(name);
  
  y += 25;
  
  //! Create label
  label = new QLabel();
  label->move(labelX, y);
  label->resize(labelWidth,20);
  label->setParent(this);
  label->setText("Module Description");
  label->setAlignment(Qt::AlignRight);
  label->setFont(QFont("Segoe UI", 10, QFont::Bold));

  descriptionEdit = new QTextEdit();
  descriptionEdit->setParent(this);
  descriptionEdit->move(nameEditX, y);
  descriptionEdit->resize(nameEditWidth, buttonY - (y + buttonGap));
  descriptionEdit->setFont(QFont("Segoe UI", 10, QFont::Bold));
  descriptionEdit->setText(description);
  
  //! Create the OKButton button
  OKButton = new QPushButton();
  OKButton->setParent(this);
  OKButton->setText("OK");
  OKButton->move(okButtonX, buttonY);
  OKButton->resize(okButtonWidth, buttonHeight);
  connect(OKButton, SIGNAL(pressed()), this, SLOT(SlotOKButtonPushed()));

  //! Create the CancelButton button
  CancelButton = new QPushButton();
  CancelButton->setParent(this);
  CancelButton->setText("Cancel");
  CancelButton->move(cancelButtonX, buttonY);
  CancelButton->resize(cancelButtonWidth, buttonHeight);
  connect(CancelButton, SIGNAL(pressed()), this, SLOT(SlotCancelButtonPushed()));
  
}

/*****************************************************************************!
 * Function : SlotOKButtonPushed
 *****************************************************************************/
void
ModuleCreateDialog::SlotOKButtonPushed(void)
{
  accept();
}

/*****************************************************************************!
 * Function : SlotCancelButtonPushed
 *****************************************************************************/
void
ModuleCreateDialog::SlotCancelButtonPushed(void)
{
  reject();
}
