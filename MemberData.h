/*****************************************************************************
 * FILE NAME    : MemberData.h
 * DATE         : November 18 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Vertiv Company
 *****************************************************************************/
#ifndef _memberdata_h_
#define _memberdata_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "DataType.h"
#include "DataName.h"
#include "SaffronComponent.h"
#include "SaffronComponentDisplayData.h"
#include "MemberDataDisplayWidget.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : MemberData
 *****************************************************************************/
class MemberData : public SaffronComponent
{
  Q_OBJECT;

 //! Constructors
 public :
  MemberData                    ();
  MemberData                    (class Module* InModule);

 //! Destructor
 public :
  ~MemberData                   ();

 //! Public Methods
 public :
  virtual QString               GetTypeName             (void);
  static class MemberData*      Create                  (class Module* InModule, QString InName, QString InDataType);
  void                          CreateDisplay           (QString InName);
  void                          CreateDisplay           (QPoint InPos, QString InName);
  void                          CreateDisplay           (QPoint InPos, QString InName, DataType::DataTypeType InType);
  void                          CreateDisplay           (int InX, int InY, QString InName);
  void                          CreateDisplay           (int InX, int InY, QString InName, DataType::DataTypeType InType);
  void                          CreateDisplay           (int InX, int InY, QString InName, QSize InSize, SaffronComponentDisplayData* InDisplayData);
  void                          CreateDisplay           (QPoint InPos, QString InName, QSize InSize, SaffronComponentDisplayData* InDisplayData);
  void                          SetDataType             (DataType* InType);
  MemberDataDisplayWidget*      GetDisplay              ();
  void                          SetPosition             (QPoint InLocation);
  void                          CreateConfigFile        (QString InConfigFilename);
  void                          SaveNew                 ();
  void                          ReadConfig              (QString InConfigFilename);
  void                          SaveConfigFile          ();
  DataType*                     GetDataType             ();
  QString                       GetInitialValue         (void);
  void                          SetInitialValue         (QString InInitialValue);
  int                           GetIndirectionLevel     (void);
  void                          SetIndirectionLevel     (int InIndirectionLevel);
  int                           GetArrayDimensions      (void);
  void                          SetArrayDimensions      (int InArrayDimensions);
  bool                          GetIsConstant           (void);
  void                          SetIsConstant           (bool InIsConstant);
  void                          SetDisplayName          (QString InName);
  void                          RemoveStorage           ();
  void                          ClearDisplayWidget      ();
  void                          ChangeDataType          (DataType::DataTypeType InType);
  void                          SetSize                 (QSize InSize);
  class MemberData*             Copy                    (void);
  QSize                         GetSize                 (void);
  void                          ChangeName              (QString InName) ;
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          Initialize              (void);

 //! Private Data
 private :
  DataType*                     type;
  MemberDataDisplayWidget*      displayWidget;
  QString                       initialValue;
  int                           indirectionLevel;
  int                           arrayDimensions;
  bool                          isConstant;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _memberdata_h_*/
