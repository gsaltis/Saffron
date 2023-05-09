/*****************************************************************************
 * FILE NAME    : MemberData.cpp
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
#include "MemberData.h"
#include "Module.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : MemberData
 *****************************************************************************/
MemberData::MemberData
() : SaffronComponent()
{
  Initialize();
}

/*****************************************************************************!
 * Function : MemberData
 *****************************************************************************/
MemberData::MemberData
(Module* InModule) : SaffronComponent()
{
  Initialize();
  SetParent(InModule);
}

/*****************************************************************************!
 * Function : ~MemberData
 *****************************************************************************/
MemberData::~MemberData
()
{
  delete type;
  delete displayWidget;
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
MemberData::Initialize(void)
{
  type = NULL;
  displayWidget = NULL;
  isConstant = false;
  initialValue = QString("");
  indirectionLevel = 0;
  arrayDimensions = 0;
}

/*****************************************************************************!
 * Function : GetTypeName
 *****************************************************************************/
QString
MemberData::GetTypeName
()
{
  return "Data";
}

/*****************************************************************************!
 * Function : Create
 *****************************************************************************/
MemberData*
MemberData::Create
(Module* InModule, QString InName, QString InDataType)
{
  MemberData*                           member;

  member = new MemberData(InModule);
  member->SetName(InName);
  member->SetDataType(new DataType(InDataType));
  InModule->AddDataElement(member);
  return member;
}

/*****************************************************************************!
 * Function : CreateDisplay
 *****************************************************************************/
void
MemberData::CreateDisplay
(QString InName)
{
  CreateDisplay(0, 0, InName);
}

/*****************************************************************************!
 * Function : CreateDisplay
 *****************************************************************************/
void
MemberData::CreateDisplay
(int InX, int InY, QString InName)
{
  displayWidget = new MemberDataDisplayWidget(this, InName);
  displayWidget->SetPosition(QPoint(InX, InY));
  displayWidget->move(InX, InY);
  displayWidget->resize(MEMBER_DATA_DISPLAY_WIDGET_WIDTH,
                        MEMBER_DATA_DISPLAY_WIDGET_HEIGHT);

}

/*****************************************************************************!
 * Function : CreateDisplay
 *****************************************************************************/
void
MemberData::CreateDisplay
(int InX, int InY, QString InName, DataType::DataTypeType InType)
{
  displayWidget = new MemberDataDisplayWidget(this, InName, InType);
  displayWidget->SetPosition(QPoint(InX, InY));
  displayWidget->move(InX, InY);
  displayWidget->resize(MEMBER_DATA_DISPLAY_WIDGET_WIDTH,
                        MEMBER_DATA_DISPLAY_WIDGET_HEIGHT);
}

/*****************************************************************************!
 * Function : CreateDisplay
 *****************************************************************************/
void
MemberData::CreateDisplay
(int InX, int InY, QString InName, QSize InSize, SaffronComponentDisplayData* InDisplayData)
{
  CreateDisplay(QPoint(InX, InY), InName, InSize, InDisplayData);
}

/*****************************************************************************!
 * Function : CreateDisplay
 *****************************************************************************/
void
MemberData::CreateDisplay
(QPoint InPoint, QString InName, QSize InSize, SaffronComponentDisplayData* InDisplayData)
{
  displayWidget = new MemberDataDisplayWidget(this, InName, InSize, InDisplayData);
  displayWidget->SetPosition(InPoint);
  displayWidget->move(InPoint);
  displayWidget->resize(MEMBER_DATA_DISPLAY_WIDGET_WIDTH,
                        MEMBER_DATA_DISPLAY_WIDGET_HEIGHT);
}

/*****************************************************************************!
 * Function : SetDisplayName
 *****************************************************************************/
void
MemberData::SetDisplayName
(QString InName)
{
  if ( NULL == displayWidget ) {
    return;
  }
  displayWidget->SetName(InName);
}

/*****************************************************************************!
 * Function : CreateDisplay
 *****************************************************************************/
void
MemberData::CreateDisplay
(QPoint InPos, QString InName)
{
  CreateDisplay(InPos.x(), InPos.y(), InName);
}

/*****************************************************************************!
 * Function : CreateDisplay
 *****************************************************************************/
void
MemberData::CreateDisplay
(QPoint InPos, QString InName, DataType::DataTypeType InType)
{
  CreateDisplay(InPos.x(), InPos.y(), InName, InType);
}

/*****************************************************************************!
 * Function : GetDisplay
 *****************************************************************************/
MemberDataDisplayWidget*
MemberData::GetDisplay
()
{
  return displayWidget;
}

/*****************************************************************************!
 * Function : SetDataType
 *****************************************************************************/
void
MemberData::SetDataType
(DataType* InDataType)
{
  type = InDataType;
}

/*****************************************************************************!
 * Function : SetPosition
 *****************************************************************************/
void
MemberData::SetPosition
(QPoint InLocation)
{
  if ( displayWidget ) {
    displayWidget->SetPosition(InLocation);
  }
}

/*****************************************************************************!
 * Function : SaveNew
 *****************************************************************************/
void
MemberData::SaveNew()
{
  QString                               configFilename;
  QDir                                  dir;
  QString                               modulePath;
  Module*                               m;
  QString                               s2;

  s2 = GetIDString();
  s2 = s2.replace(":", "-");
  m = (Module*)GetParent();
  modulePath = m->GetPath() + QString("/") + s2;
  dir.mkdir(modulePath);
  configFilename = modulePath + QString("/config.json");
  CreateConfigFile(configFilename);
}

/*****************************************************************************!
 * Function : CreateConfigFile
 *****************************************************************************/
void
MemberData::CreateConfigFile
(QString InConfigFilename)
{
  QString                               s;
  QByteArray                            jsonByteArray;
  QJsonDocument                         jsonDoc;
  QJsonObject                           jsonDataElement;
  QJsonObject                           topObject;
  
  QFile file(InConfigFilename);
  if ( ! file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate) ) {
    return;
  }

  topObject = jsonDoc.object();
  CreateIDConfigFile(topObject);

  type->WriteToJSON(topObject);
  if ( displayWidget ) {
    displayWidget->CreateJSON(topObject);
  }
  jsonDoc.setObject(topObject);
  jsonByteArray = jsonDoc.toJson();
  s = QString(jsonByteArray);
  file.write(jsonByteArray);
  file.close();
}

/*****************************************************************************!
 * Function : SaveConfigFile
 *****************************************************************************/
void
MemberData::SaveConfigFile
()
{
  QString                               s;
  QByteArray                            jsonByteArray;
  QJsonDocument                         jsonDoc;
  QJsonObject                           jsonDataElement;
  QJsonObject                           topObject;
  Module*                               module;
  QString                               modulePath;
  QString                               idString;
  
  module = (Module*)GetParent();
  modulePath = module->GetPath();
  idString = GetIDString();
  idString = idString.replace(":", "-");
  modulePath += QString("/") + idString + QString("/config.json");

  QFile file(modulePath);
  if ( ! file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate ) ) {
    return;
  }

  topObject = jsonDoc.object();
  CreateIDConfigFile(topObject);

  type->WriteToJSON(topObject);
  if ( displayWidget ) {
    displayWidget->CreateJSON(topObject);
  }
  topObject["constant"] = isConstant;
  topObject["initialvalue"] = initialValue;
  topObject["arraydimensions"] = arrayDimensions;
  topObject["indirectionlevel"] = indirectionLevel;
  jsonDoc.setObject(topObject);
  jsonByteArray = jsonDoc.toJson();
  s = QString(jsonByteArray);
  file.write(jsonByteArray);
  file.close();
}

/*****************************************************************************!
 * Function : ReadConfig
 *****************************************************************************/
void
MemberData::ReadConfig
(QString InConfigFilename)
{
  QJsonParseError                       jsonError;
  QString                               s;
  QJsonValue                            idVal;
  QJsonValue                            dataElementValue;
  QJsonObject                           idObj;
  QJsonObject                           dataElementObject;
  QJsonObject                           docObject;
  QJsonDocument                         jsonDoc;
  QByteArray                            bytes;
  QFile                                 file(InConfigFilename);
  QString                               na;
  QJsonValue                            initialValueVal, indirectionLevelVal;
  QJsonValue                            isConstantVal, arrayDimensionsVal;
  
  if ( !file.open(QIODeviceBase::ReadOnly) ) {
    return;
  }

  bytes = file.readAll();
  if ( bytes.size() == 0 ) {
    return;
  }
  file.close();
  
  jsonDoc = QJsonDocument::fromJson(bytes, &jsonError);
  if ( jsonDoc.isEmpty() ) {
    return;
  }
  if ( ! jsonDoc.isObject() ) {
    s = jsonError.errorString();
    return;
  }

  docObject = jsonDoc.object();
  idVal = docObject["id"];
  if ( ! idVal.isObject() ) {
    return;
  }

  indirectionLevelVal = docObject["indirectionlevel"];
  arrayDimensionsVal = docObject["arraydimensions"];
  isConstantVal = docObject["constant"];
  initialValueVal = docObject["initialvalue"];

  if ( !indirectionLevelVal.isDouble() ) {
    indirectionLevel = (int)indirectionLevelVal.toDouble();
  }
  if ( arrayDimensionsVal.isDouble() ) {
    arrayDimensions = (int)arrayDimensionsVal.toDouble();
  }
  if ( ! initialValueVal.isNull() ) {
    initialValue = initialValueVal.toString();
  }
  if ( ! isConstantVal.isNull() ) {
    isConstant = isConstantVal.toBool();
  }
  
  idObj = idVal.toObject();
  if ( idObj.isEmpty() ) {
    return;
  }

  if ( type == NULL ) {
    type = new DataType();
  }
  type->ReadFromJSON(docObject);
  FromJSON(idObj);
  QString dataTypeString = DataType::ToString(type->GetType());
  displayWidget = new MemberDataDisplayWidget(this, GetName()->ToString(), docObject,
                                              "display");
  na = GetIDString();
}

/*****************************************************************************!
 * Function : GetDataType
 *****************************************************************************/
DataType*
MemberData::GetDataType
()
{
  return type;
}

/*****************************************************************************!
 * Function : GetInitialValue
 *****************************************************************************/
QString
MemberData::GetInitialValue(void)
{
  return initialValue;  
}

/*****************************************************************************!
 * Function : SetInitialValue
 *****************************************************************************/
void
MemberData::SetInitialValue
(QString InInitialValue)
{
  initialValue = InInitialValue;  
}

/*****************************************************************************!
 * Function : GetIndirectionLevel
 *****************************************************************************/
int
MemberData::GetIndirectionLevel(void)
{
  return indirectionLevel;  
}

/*****************************************************************************!
 * Function : SetIndirectionLevel
 *****************************************************************************/
void
MemberData::SetIndirectionLevel
(int InIndirectionLevel)
{
  indirectionLevel = InIndirectionLevel;  
}

/*****************************************************************************!
 * Function : GetArrayDimensions
 *****************************************************************************/
int
MemberData::GetArrayDimensions(void)
{
  return arrayDimensions;  
}

/*****************************************************************************!
 * Function : SetArrayDimensions
 *****************************************************************************/
void
MemberData::SetArrayDimensions
(int InArrayDimensions)
{
  arrayDimensions = InArrayDimensions;  
}

/*****************************************************************************!
 * Function : GetIsConstant
 *****************************************************************************/
bool
MemberData::GetIsConstant(void)
{
  return isConstant;  
}

/*****************************************************************************!
 * Function : SetIsConstant
 *****************************************************************************/
void
MemberData::SetIsConstant
(bool InIsConstant)
{
  isConstant = InIsConstant;  
}

/*****************************************************************************!
 * Function : RemoveStorage
 *****************************************************************************/
void
MemberData::RemoveStorage(void)
{
  QString                               s2;
  Module*                               m;
  QString                               memberPath;
  
  s2 = GetIDString();
  s2 = s2.replace(":", "-");
  m = (Module*)GetParent();
  memberPath = m->GetPath() + QString("/") + s2;
  QDir d(memberPath);
  d.removeRecursively();
}

/*****************************************************************************!
 * Function : ClearDisplayWidget
 *****************************************************************************/
void
MemberData::ClearDisplayWidget
()
{
  if ( displayWidget ) {
    delete displayWidget;
  }
  displayWidget = NULL;
}

/*****************************************************************************!
 * Function : ChangeDataType
 *****************************************************************************/
void
MemberData::ChangeDataType
(DataType::DataTypeType InType)
{
  type->SetType(InType);
}

/*****************************************************************************!
 * Function : SetSize
 *****************************************************************************/
void
MemberData::SetSize
(QSize InSize)
{
  if ( NULL == displayWidget ) {
    return;
  }
  displayWidget->SetSize(InSize);
}


/*****************************************************************************!
 * Function : Copy
 *****************************************************************************/
class MemberData*
MemberData::Copy(void)
{
  return NULL;
}

/*****************************************************************************!
 * Function : GetSize
 *****************************************************************************/
QSize
MemberData::GetSize(void)
{
  return displayWidget->GetSize();
}

/*****************************************************************************!
 * Function : ChangeName
 *****************************************************************************/
void
MemberData::ChangeName
(QString InName)
{
  SaffronComponent::SetName(InName);
  if ( displayWidget ) {
    displayWidget->SetName(InName);
  }
}
