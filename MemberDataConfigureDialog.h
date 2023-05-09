/*****************************************************************************
 * FILE NAME    : MemberDataConfigureDialog.h
 * DATE         : February 05 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _memberdataconfiguredialog_h_
#define _memberdataconfiguredialog_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QAction>
#include <QGroupBox>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MemberData.h"
#include "SaffronComponentColorConfigWindow.h"
#include "MemberDataMemberEdit.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MEMBER_DATA_CONFIGURE_DIALOG_WIDTH      440
#define MEMBER_DATA_CONFIGURE_DIALOG_HEIGHT     620

/*****************************************************************************!
 * Exported Class : MemberDataConfigureDialog
 *****************************************************************************/
class MemberDataConfigureDialog : public QDialog
{
  Q_OBJECT;

 //! Constructors
 public :
  MemberDataConfigureDialog     (MemberData* InMemberData);

 //! Destructor
 public :
  ~MemberDataConfigureDialog    ();

 //! Public Methods
 public :
  SaffronComponentFill*         GetFill                 ();
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          Initialize              (void);
  void                          CreateConnections       (void);
  void                          CreateSubWindows        (void);
  QStringList                   comboBoxDataType_add_items (void);
  int                           CreateMemberDataSection ();
  void                          SectionsResize          (QString InText);
  
 //! Private Data
 private :
  SaffronComponentColorConfigWindow*     colorWindow;
  QPushButton*                  OKButton;
  QPushButton*                  CancelButton;
  QGroupBox*                    memberDataSection;            
  MemberData*                   memberData;
  MemberDataMemberEdit*         memberDataEdit;
  
#if 0
  QLabel*                       labelDataName;
  QLabel*                       labelDataType;
  QLabel*                       labelIndirectionLevel;
  QLabel*                       labelInitialValue;
  QLabel*                       labelArrayDimensions;
  QLabel*                       labelConstant;
  QLabel*                       labelBackground;

  QLineEdit*                    lineEditDataName;
  QLineEdit*                    lineEditInitialValue;
  QLineEdit*                    lineEditIndirectionLevel;
  QLineEdit*                    lineEditArrayDimensions;
  
  QComboBox*                    comboBoxDataType;
  QCheckBox*                    checkBoxConstant;
  QPushButton*                  buttonBackground;
#endif
  
 //! Public Slots
 public slots :
  void                          SlotOKButtonPressed     ();
  void                          SlotCancelButtonPressed ();
  void                          slotcomboBoxDataType_selected_item (int selected_index);
  void                          SlotbuttonBackgroundPushed (void);
  void                          SlotComboBoxDataTypeTextChanged (QString InText);

 //! Public Signals
 signals :

 //! Public Actions
 public :
  QAction*                      ActionbuttonBackgroundPushed;

};

#endif /* _memberdataconfiguredialog_h_*/
