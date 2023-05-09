/*****************************************************************************
 * FILE NAME    : ModuleControlBarWindow.cpp
 * DATE         : January 16 2023
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
#include "ModuleControlBarWindow.h"
#include "DataType.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : ModuleControlBarWindow
 *****************************************************************************/
ModuleControlBarWindow::ModuleControlBarWindow
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 0, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ModuleControlBarWindow
 *****************************************************************************/
ModuleControlBarWindow::~ModuleControlBarWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleControlBarWindow::initialize()
{
  project = NULL;
  userDataTypesSelect = NULL;
  dataTypesSelect = NULL;
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleControlBarWindow::CreateSubWindows()
{
    //! Create dataTypesSelect Combobox
  dataTypesSelect = new QComboBox();
  dataTypesSelect->setParent(this);
  dataTypesSelect->move(10,2);
  dataTypesSelect->resize(150,21);
  dataTypesSelect->addItems(dataTypesSelectAddItems());
  connect(dataTypesSelect,
          SIGNAL(currentTextChanged(QString)),
          this,
          SLOT(SlotDataTypeTextChanged(QString)));
  
    //! Create userDataTypesSelect Combobox
  userDataTypesSelect = new QComboBox();
  userDataTypesSelect->setParent(this);
  userDataTypesSelect->move(180,2);
  userDataTypesSelect->resize(150,21);
  userDataTypesSelect->addItems(userDataTypesSelect_add_items());
  userDataTypesSelect->hide();
  connect(userDataTypesSelect,
          SIGNAL(currentIndexChanged(int)),
          this,
          SLOT(slotuserDataTypesSelect_selected_item(int)));

  auto st = DataType::ToString(DataType::DataTypeInt32);
  dataTypesSelect->setCurrentText(st);
  emit SignalDataTypeChanged(st);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleControlBarWindow::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ModuleControlBarWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   height;
  QPalette                              pal;
  QBrush                                brush;

  size = InEvent->size();
  height = size.height();

  QLinearGradient                       grad(QPoint(0, 0), QPoint(0, height));
  grad.setColorAt(0, QColor(192, 192, 192));
  grad.setColorAt(1, QColor(144, 144, 144));
  brush = QBrush(grad);

  pal = palette();
  pal.setBrush(QPalette::Window, brush);
  setPalette(pal);
}

/*****************************************************************************!
 * Function : dataTypesSelect_add_items
 *****************************************************************************/
QStringList
ModuleControlBarWindow::dataTypesSelectAddItems(void)
{
  QList<QString>                        dataTypes;
  
  dataTypes = DataType::GetTypeNames();
  dataTypes << QString("User");
  return dataTypes;
}

/*****************************************************************************!
 * Function : slotdataTypesSelect_selected_item
 *****************************************************************************/
void
ModuleControlBarWindow::slotdataTypesSelectSelectedItem
(int in_selected_index)
{
  QString                               st;

  st = dataTypesSelect->currentText();
  emit SignalDataTypeChanged(st);
  (void)in_selected_index;  
}

/*****************************************************************************!
 * Function : userDataTypesSelect_add_items
 *****************************************************************************/
QStringList
ModuleControlBarWindow::userDataTypesSelect_add_items(void)
{
  QList<QString>                        names;  
  return project ? project->GetModuleNames() : names; 
}

/*****************************************************************************!
 * Function : slotuserDataTypesSelect_selected_item
 *****************************************************************************/
void
ModuleControlBarWindow::slotuserDataTypesSelect_selected_item
(int InSelectedIndex)
{
  QString                               st;
  st = userDataTypesSelect->itemText(InSelectedIndex);
  emit SignalUserDataTypeChanged(st);
}

/*****************************************************************************!
 * Function : SlotProjectOpened
 *****************************************************************************/
void
ModuleControlBarWindow::SlotProjectOpened
(Project* InProject)
{
  project = InProject;
  userDataTypesSelect->clear();
  userDataTypesSelect->addItems(project->GetModuleNames());
}

/*****************************************************************************!
 * Function : SlotDataTypeTextChanged
 *****************************************************************************/
void
ModuleControlBarWindow::SlotDataTypeTextChanged
(QString InString)
{
  if ( NULL == userDataTypesSelect ) {
    return;
  }

  if ( InString == "User" ) {
    userDataTypesSelect->show();
    auto ct = userDataTypesSelect->currentText();
    emit SignalUserDataTypeChanged(ct);
  } else {
    userDataTypesSelect->hide();
  }
  emit SignalDataTypeChanged(InString);
}

/*****************************************************************************!
 * Function : SlotUserDataTypeChanged
 *****************************************************************************/
void
ModuleControlBarWindow::SlotUserDataTypeChanged
(QString InUserDataTypeName)
{
  emit SignalUserDataTypeChanged(InUserDataTypeName);
}
