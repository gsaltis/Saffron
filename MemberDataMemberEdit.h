/*****************************************************************************
 * FILE NAME    : MemberDataMemberEdit.h
 * DATE         : March 20 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _memberdatamemberedit_h_
#define _memberdatamemberedit_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MemberData.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MEMBER_DATA_MEMBER_EDIT_X       200
#define MEMBER_DATA_MEMBER_EDIT_Y       200
#define MEMBER_DATA_MEMBER_EDIT_WIDTH   200
#define MEMBER_DATA_MEMBER_EDIT_HEIGHT  200

/*****************************************************************************!
 * Exported Class : MemberDataMemberEdit
 *****************************************************************************/
class MemberDataMemberEdit : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MemberDataMemberEdit          (MemberData* InMemberData);

 //! Destructor
 public :
  ~MemberDataMemberEdit         ();

 //! Public Methods
 public :
  void                          SetMember               ();

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  QLabel*                       CreateLabel             (QString InText);
  void                          AddRow                  (QString InLabelText, QWidget* InWidget);
  void                          InsertRow               (int InRow, QString InLabelText, QWidget* InWidget);
  void                          RemoveRow               (int InRow);
  
 //! Private Data
 private :
  QFormLayout*                  formLayout;
  QLineEdit*                    nameEdit;
  QComboBox*                    typeSelection;
  QLineEdit*                    initialValue;
  QLineEdit*                    indirectionLevel;
  QLineEdit*                    arrayDimensions;
  QCheckBox*                    isConstant;
  MemberData*                   memberData;
  QComboBox*                    userTypeComboBox;
  
 //! Public Slots
 public slots :
  void                          SlotTypeTextChanged     (QString InString);

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _memberdatamemberedit_h_*/
