/*****************************************************************************
 * FILE NAME    : MemberDataMemberEdit.cpp
 * DATE         : March 20 2023
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
#include "MemberDataMemberEdit.h"
#include "Trace.h"
#include "Project.h"

/*****************************************************************************!
 * Function : MemberDataMemberEdit
 *****************************************************************************/
MemberDataMemberEdit::MemberDataMemberEdit
(MemberData* InMemberData) : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255, 0)));
  setPalette(pal);
  setAutoFillBackground(true);
  memberData = InMemberData;
  initialize();
}

/*****************************************************************************!
 * Function : ~MemberDataMemberEdit
 *****************************************************************************/
MemberDataMemberEdit::~MemberDataMemberEdit
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MemberDataMemberEdit::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MemberDataMemberEdit::CreateSubWindows()
{
  QStringList                           dataTypeStrings;
  
  formLayout = new QFormLayout(this);

  nameEdit              = new QLineEdit();
  typeSelection         = new QComboBox();
  initialValue          = new QLineEdit();
  indirectionLevel      = new QLineEdit();
  arrayDimensions       = new QLineEdit();
  isConstant            = new QCheckBox();
  userTypeComboBox      = NULL;
  
  connect(typeSelection,
          SIGNAL(currentTextChanged(QString)),
          this,
          SLOT(SlotTypeTextChanged(QString)));
  AddRow("Data Name", nameEdit);
  AddRow("DataType", typeSelection);
  AddRow("Initial Value", initialValue);
  AddRow("Indirection Level", indirectionLevel);
  AddRow("Array Dimensions", arrayDimensions);
  AddRow("Constant", isConstant);

  if ( memberData ) {
    nameEdit->setText(memberData->GetName()->ToString());
    dataTypeStrings = DataType::GetTypeNames();
    dataTypeStrings << "User";
    typeSelection->addItems(dataTypeStrings);
    typeSelection->setCurrentText(memberData->GetDataType()->GetTypeString());
    initialValue->setText(memberData->GetInitialValue());
    indirectionLevel->setText(QString("%1").arg(memberData->GetIndirectionLevel()));
    arrayDimensions->setText(QString("%1").arg(memberData->GetArrayDimensions()));
    isConstant->setChecked(memberData->GetIsConstant());
  }
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MemberDataMemberEdit::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MemberDataMemberEdit::resizeEvent
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
 * Function : CreateLabel
 *****************************************************************************/
QLabel*
MemberDataMemberEdit::CreateLabel
(QString InText)
{
  QLabel*                               label;  
  label = new QLabel(InText + QString(" : "));
  label->setMinimumWidth(120);
  label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
  return label;
}

/*****************************************************************************!
 * Function : AddRow
 *****************************************************************************/
void
MemberDataMemberEdit::AddRow
(QString InLabelText, QWidget* InWidget)
{
  formLayout->addRow(CreateLabel(InLabelText), InWidget);  
}

/*****************************************************************************!
 * Function : InsertRow
 *****************************************************************************/
void
MemberDataMemberEdit::InsertRow
(int InRow, QString InLabelText, QWidget* InWidget)
{
  formLayout->insertRow(InRow, CreateLabel(InLabelText), InWidget);  
}

/*****************************************************************************!
 * Function : RemoveRow
 *****************************************************************************/
void
MemberDataMemberEdit::RemoveRow
(int InRow)
{
  formLayout->removeRow(InRow);  
}

/*****************************************************************************!
 * Function : SlotTypeTextChanged
 *****************************************************************************/
void
MemberDataMemberEdit::SlotTypeTextChanged
(QString InString)
{
  int                                   h;
  Project*                              project;
  Module*                               module;
  
  if ( InString == "User" ) {
    userTypeComboBox = new QComboBox();

    module = (Module*)memberData->GetParent();
    project = (Project*)module->GetParent();
    
    userTypeComboBox->addItems(project->GetModuleNames());
    InsertRow(2, "User Type", userTypeComboBox);

    h = size().height();
    h += 20;
    resize(size().width(), h);
    return;
  }
  if ( userTypeComboBox ) {
    RemoveRow(2);
    userTypeComboBox = NULL;
    h = size().height();
    h -= 20;
    resize(size().width(), h);
  }
}
/*****************************************************************************!
 * Function : SetMember
 *****************************************************************************/
void
MemberDataMemberEdit::SetMember
()
{
  QString                               st;
  
  memberData->SetInitialValue(initialValue->text());
  memberData->ChangeName(nameEdit->text());
  memberData->SetIndirectionLevel(indirectionLevel->text().toInt());
  memberData->SetArrayDimensions(arrayDimensions->text().toInt());
  memberData->SetIsConstant(isConstant->checkState() == Qt::Checked);
  st = typeSelection->currentText();
  memberData->GetDataType()->SetType(DataType::FromString(st));
  if ( st == "User" ) {
    memberData->GetDataType()->SetUserTypeName(userTypeComboBox->currentText());
  }
}
