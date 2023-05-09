/*****************************************************************************
 * FILE NAME    : MemberDataConfigureDialog.cpp
 * DATE         : February 05 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QDialog>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MemberDataConfigureDialog.h"
#include "trace.h"

#define MEMBER_DATA_CONFIG_MEMBER_SECTION_BASE_HEIGHT   210
#define MEMBER_DATA_CONFIG_MEMBER_SECTION_EXTEND_HEIGHT 240
#define MEMBER_DATA_CONFIG_COLOR_BASE_Y                 (MEMBER_DATA_CONFIG_MEMBER_SECTION_BASE_HEIGHT + 10)
#define MEMBER_DATA_CONFIG_COLOR_EXTENDED_Y             (MEMBER_DATA_CONFIG_MEMBER_SECTION_EXTEND_HEIGHT + 10)

/*****************************************************************************!
 * Function : MemberDataConfigureDialog
 *****************************************************************************/
MemberDataConfigureDialog::MemberDataConfigureDialog
(MemberData* InMemberData) : QDialog()
{
  memberData = InMemberData;
  Initialize();
  setWindowTitle("Member Data Configure");
}

/*****************************************************************************!
 * Function : ~MemberDataConfigureDialog
 *****************************************************************************/
MemberDataConfigureDialog::~MemberDataConfigureDialog
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
MemberDataConfigureDialog::Initialize(void)
{
  CreateSubWindows();  
  CreateConnections();
  resize(MEMBER_DATA_CONFIGURE_DIALOG_WIDTH, MEMBER_DATA_CONFIGURE_DIALOG_HEIGHT);
  ActionbuttonBackgroundPushed = new QAction("buttonBackgroundPushed", this);
  connect(ActionbuttonBackgroundPushed,
          SIGNAL(triggered()),
          this,
          SLOT(SlotbuttonBackgroundPushed()));
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MemberDataConfigureDialog::CreateConnections(void)
{
  connect(OKButton, SIGNAL(pressed()), this, SLOT(SlotOKButtonPressed()));  
  connect(CancelButton, SIGNAL(pressed()), this, SLOT(SlotCancelButtonPressed()));
}


/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MemberDataConfigureDialog::CreateSubWindows(void)
{
  QString                               dataTypeString;
  int                                   okButtonX;
  int                                   buttonY;
  int                                   cancelButtonWidth;
  int                                   okButtonWidth;
  int                                   buttonHeight;
  int                                   buttonGap;
  int                                   cancelButtonX;
  MemberDataDisplayWidget*              displayWidget;
  SaffronComponentDisplayData*          displayData;
  SaffronComponentFill*                 backgroundFill;
  
  displayWidget = memberData->GetDisplay();
  displayData = displayWidget->GetDisplayData();
  backgroundFill = displayData->GetFill();
  
  memberDataSection = new QGroupBox(this);
  memberDataSection->move(30, 10);
  memberDataSection->resize(380, MEMBER_DATA_CONFIG_MEMBER_SECTION_BASE_HEIGHT);
  memberDataSection->setTitle("Member Data");
  CreateMemberDataSection();
  colorWindow = new SaffronComponentColorConfigWindow(backgroundFill);
  colorWindow->setParent(this);
  colorWindow->move(20, MEMBER_DATA_CONFIG_COLOR_BASE_Y);

  okButtonWidth = 60;
  cancelButtonWidth = 60;
  buttonGap = 10;
  buttonHeight = 20;
  okButtonX = MEMBER_DATA_CONFIGURE_DIALOG_WIDTH - (okButtonWidth + cancelButtonWidth + (2 * buttonGap));
  cancelButtonX = MEMBER_DATA_CONFIGURE_DIALOG_WIDTH - (cancelButtonWidth + buttonGap);
  buttonY = MEMBER_DATA_CONFIGURE_DIALOG_HEIGHT - (buttonGap + buttonHeight);

  OKButton = new QPushButton();
  OKButton->setParent(this);
  OKButton->setText("OK");
  OKButton->move(okButtonX, buttonY);
  OKButton->resize(okButtonWidth, buttonHeight);
  
  CancelButton = new QPushButton();
  CancelButton->setParent(this);
  CancelButton->setText("Cancel");
  CancelButton->move(cancelButtonX, buttonY);
  CancelButton->resize(cancelButtonWidth, buttonHeight);
  dataTypeString = DataType::ToString(memberData->GetDataType()->GetType());
  SectionsResize(dataTypeString);
}

/*****************************************************************************!
 * Function : CreateMemberDataSection
 *****************************************************************************/
int
MemberDataConfigureDialog::CreateMemberDataSection
()
{
  int                                   y;
  memberDataEdit = new MemberDataMemberEdit(memberData);
  memberDataEdit->setParent(memberDataSection);
  memberDataEdit->resize(340, 180);
  memberDataEdit->move(10, 10);
  y = 140;
  return y;
}

/*****************************************************************************!
 * Function : SlotOKButtonPressed
 *****************************************************************************/
void
MemberDataConfigureDialog::SlotOKButtonPressed()
{
  memberDataEdit->SetMember();
  accept();
}

/*****************************************************************************!
 * Function : SlotCancelButtonPressed
 *****************************************************************************/
void
MemberDataConfigureDialog::SlotCancelButtonPressed()
{
  reject();
}

/*****************************************************************************!
 * Function : comboBoxDataType_add_items
 *****************************************************************************/
QStringList
MemberDataConfigureDialog::comboBoxDataType_add_items(void)
{
  QStringList                           typeNames;
  typeNames =  DataType::GetTypeNames();
  typeNames << "User";
  return typeNames;
}

/*****************************************************************************!
 * Function : slotcomboBoxDataType_selected_item
 *****************************************************************************/
void
MemberDataConfigureDialog::slotcomboBoxDataType_selected_item
(int in_selected_index)
{
  (void)in_selected_index;  
}

/*****************************************************************************!
 * Function : SlotbuttonBackgroundPushed
 *****************************************************************************/
void
MemberDataConfigureDialog::SlotbuttonBackgroundPushed(void)
{
  
}
/*****************************************************************************!
 * Function : GetFill
 *****************************************************************************/
SaffronComponentFill*
MemberDataConfigureDialog::GetFill
()
{
  return colorWindow->GetFill();
}

/*****************************************************************************!
 * Function : SlotComboBoxDataTypeTextChanged
 *****************************************************************************/
void
MemberDataConfigureDialog::SlotComboBoxDataTypeTextChanged
(QString InText)
{
  SectionsResize(InText);
}

/*****************************************************************************!
 * Function : SectionsResize
 *****************************************************************************/
void
MemberDataConfigureDialog::SectionsResize
(QString InText)
{
  int                                   y;
  int                                   h;
  
  h = MEMBER_DATA_CONFIG_MEMBER_SECTION_BASE_HEIGHT;
  y = MEMBER_DATA_CONFIG_COLOR_BASE_Y;

  if ( InText == "User" ) {
    h = MEMBER_DATA_CONFIG_MEMBER_SECTION_EXTEND_HEIGHT;
    y = MEMBER_DATA_CONFIG_COLOR_EXTENDED_Y;
  }
  colorWindow->move(colorWindow->pos().x(), y);
  memberDataSection->resize(memberDataSection->width(), h);
}
