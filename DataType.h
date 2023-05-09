/*****************************************************************************
 * FILE NAME    : DataType.h
 * DATE         : November 18 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Vertiv Company
 *****************************************************************************/
#ifndef _datatype_h_
#define _datatype_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QJsonDocument.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronComponentFill.h"
#include "SaffronComponentFillSolid.h"
#include "SaffronComponentFillGradient.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : DataType
 *****************************************************************************/
class DataType : public QWidget
{
  Q_OBJECT;

 //! Public Types
 public:
  enum DataTypeType {
    DataTypeNone,
    DataTypeInt8,
    DataTypeInt16,
    DataTypeInt32,
    DataTypeInt64,
    DataTypeFloat16,
    DataTypeFloat32,
    DataTypeFloat64,
    DataTypeChar8,    
    DataTypeChar16,
    DataTypeString8,    
    DataTypeString16,
    DataTypeBoolean,
    DataTypeUser
  };
      
 //! Constructors
 public :
  DataType                      ();
  DataType                      (QString InString);
  DataType                      (DataType::DataTypeType InType);
  
 //! Destructor
 public :
  ~DataType                     ();

 //! Public Methods
 public :
  static DataTypeType           FromString                      (QString InString);
  static QString                ToString                        (DataTypeType InType);
  static QStringList            GetTypeNames                    ();
  static SaffronComponentFill*  GetFillByType                   (DataTypeType InDataType);
  static SaffronComponentFill*  GetFillByType                   (QString InDataTypeName);
  static void                   DataTypeFillFromJSON            (QJsonArray* InObject);

  DataTypeType                  GetType                         (void);
  QString                       GetTypeString                   (void);
  void                          ReadFromJSON                    (QJsonObject& InObject);
  void                          WriteToJSON                     (QJsonObject& InObject);
  void                          SetType                         (DataTypeType InType);
  QString                       GetUserTypeName                 (void);
  void                          SetUserTypeName                 (QString InUserTypeName);
  
 //! Public Data
 public :
  DataTypeType                  type;
  
 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :

 //! Private Data
 private :
  QString                       userTypeName;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _datatype_h_*/
