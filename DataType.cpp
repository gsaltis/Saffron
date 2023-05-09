/*****************************************************************************
 * FILE NAME    : DataType.cpp
 * DATE         : November 18 2022
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
#include "DataType.h"
#include "Trace.h"

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
QHash<DataType::DataTypeType, SaffronComponentFill*>
DataTypesFill;

/*****************************************************************************!
 * Function : DataType
 *****************************************************************************/
DataType::DataType
() : QWidget()
{
  type = DataTypeNone;
}

/*****************************************************************************!
 * Function : DataType
 *****************************************************************************/
DataType::DataType
(QString InString) : QWidget()
{
  type = FromString(InString);
}

/*****************************************************************************!
 * Function : DataType
 *****************************************************************************/
DataType::DataType
(DataType::DataTypeType InType) : QWidget()
{
  type = InType;
}

/*****************************************************************************!
 * Function : ~DataType
 *****************************************************************************/
DataType::~DataType
()
{
}

/*****************************************************************************!
 * Function : GetType
 *****************************************************************************/
DataType::DataTypeType
DataType::GetType
(void)
{
  return type;
}

/*****************************************************************************!
 * Function : GetTypeString
 *****************************************************************************/
QString
DataType::GetTypeString
(void)
{
  return ToString(type);
}

/*****************************************************************************!
 * Function : FromString
 *****************************************************************************/
DataType::DataTypeType
DataType::FromString
(QString InString)
{
  if ( InString == "" ) {
    return DataTypeNone;
  }
  
  if ( InString == "Int8" ) {
    return DataTypeInt8;
  }
  
  if ( InString == "Int16" ) {
    return DataTypeInt16;
  }
  
  if ( InString == "Int32" ) {
    return DataTypeInt32;
  }

  if ( InString == "Int64" ) {
    return DataTypeInt64;
  }
  
  if ( InString == "Float16" ) {
    return DataTypeFloat16;
  }
  
  if ( InString == "Float32" ) {
    return DataTypeFloat32;
  }
  
  if ( InString == "Float64" ) {
    return DataTypeFloat64;
  }
  
  if ( InString == "Char8" ) {
    return DataTypeChar8;
  }
  
  if ( InString == "Char16" ) {
    return DataTypeChar16;
  }
  
  if ( InString == "String8" ) {
    return DataTypeString8;
  }
  
  if ( InString == "String16" ) {
    return DataTypeString16;
  }
  
  if ( InString == "Boolean" ) {
    return DataTypeBoolean;
  }
  
  if ( InString == "User" ) {
    return DataTypeUser;
  }
  return DataTypeNone;
}  

/*****************************************************************************!
 * Function : FromString
 *****************************************************************************/
QStringList
DataType::GetTypeNames
()
{
  QStringList                           names;
  names << 
    "Int8" << "Int16" << "Int32" << "Int64" <<
    "Float16" << "Float32" << "Float64" << "Char8" <<
    "Char16" << "String8" << "String16" << "Boolean";
  return names;
}

/*****************************************************************************!
 * Function : ToString
 *****************************************************************************/
QString
DataType::ToString
(DataType::DataTypeType InType)
{
  switch (InType) {
    case DataTypeNone :
      return "None";
      
    case DataTypeInt8 :
      return "Int8";
      
    case DataTypeInt16 :
      return "Int16";
      
    case DataTypeInt32 :
      return "Int32";
      
    case DataTypeInt64 :
      return "Int64";
      
    case DataTypeFloat16 :
      return "Float16";
      
    case DataTypeFloat32 :
      return "Float32";
      
    case DataTypeFloat64 :
      return "Float64";
      
    case DataTypeChar8 :
      return "Char8";
      
    case DataTypeChar16 :
      return "Char16";
      
    case DataTypeString8 :
      return "String8";
      
    case DataTypeString16 :
      return "String16";
      
    case DataTypeBoolean :
      return "Boolean";
      
    case DataTypeUser :
      return "User";
      
  }
  return "None";
}

/*****************************************************************************!
 * Function : ReadFromJSON
 *****************************************************************************/
void
DataType::ReadFromJSON
(QJsonObject& InObject)
{
  QJsonValue                            userTypeValue;
  QJsonValue                            dataTypeValue;
  QJsonValue                            typeValue;
  QJsonObject                           dataTypeObject;
  QString                               st;
  
  dataTypeValue = InObject["dataElement"];
  if ( ! dataTypeValue.isObject() ) {
    return;
  }

  dataTypeObject = dataTypeValue.toObject();
  if ( dataTypeObject.isEmpty() ) {
    return;
  }

  typeValue = dataTypeObject["type"];
  if ( ! typeValue.isString() ) {
    return;
  }

  if ( typeValue == "User" ) {
    userTypeValue = dataTypeObject["usertype"];
    if ( userTypeValue.isString() ) {
      userTypeName = userTypeValue.toString();
    }
  }
  st = typeValue.toString();
  type = FromString(st);
}

/*****************************************************************************!
 * Function : WriteToJSON
 *****************************************************************************/
void
DataType::WriteToJSON
(QJsonObject& InObject)
{
  QJsonObject                           jsonDataElement;
  QString                               st;

  st =GetTypeString();
  jsonDataElement["type"] = st;
  if ( st == "User" ) {
    jsonDataElement["usertype"] = userTypeName;
  }
  InObject["dataElement"] = jsonDataElement;
}

/*****************************************************************************!
 * Function : GetFillByType
 *****************************************************************************/
SaffronComponentFill*
DataType::GetFillByType
(QString InDataTypeName)
{
  return GetFillByType(DataType::FromString(InDataTypeName));
}

/*****************************************************************************!
 * Function : GetFillByType
 *****************************************************************************/
SaffronComponentFill*
DataType::GetFillByType
(DataType::DataTypeType InDataType)
{
  if ( InDataType == DataTypeNone ) {
    return NULL;
  }
  SaffronComponentFill* fill = DataTypesFill[InDataType];
  return fill;
}

/*****************************************************************************!
 * Function : DataTypeFillFromJSON
 *****************************************************************************/
void
DataType::DataTypeFillFromJSON
(QJsonArray* InObject)
{
  QJsonObject                           fillObj;
  QJsonValue                            typeNameVal;
  QString                               typeName;
  SaffronComponentFillGradient*         grad;
  QString                               st;
  
  if ( InObject->empty() ) {
    return;
  }

  for ( QJsonArray::iterator i = InObject->begin(); i != InObject->end() ; i++ ) {
    QJsonValue                          value;
    QJsonObject                         obj;
    
    value = *i;
    obj = value.toObject();
    if ( obj.empty() ) {
      continue;
    }
    typeNameVal = obj["name"];
    typeName = typeNameVal.toString();
    if ( typeName == "none" ) {
      continue;
    }
    fillObj = obj["fill"].toObject();
    grad = new SaffronComponentFillGradient("moduleGradient", 90);
    grad->FromJSON(fillObj);
    st = grad->GetSVGString();
    DataTypesFill[DataType::FromString(typeName)] = grad;
  }
}

/*****************************************************************************!
 * Function : SetType
 *****************************************************************************/
void
DataType::SetType
(DataTypeType InType)
{
  type = InType;
}

/*****************************************************************************!
 * Function : GetUserTypeName
 *****************************************************************************/
QString
DataType::GetUserTypeName(void)
{
  return userTypeName;  
}

/*****************************************************************************!
 * Function : SetUserTypeName
 *****************************************************************************/
void
DataType::SetUserTypeName
(QString InUserTypeName)
{
  userTypeName = InUserTypeName;  
}
