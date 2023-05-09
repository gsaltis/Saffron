/*****************************************************************************
 * FILE NAME    : Module.cpp
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
#include <QDir>
#include <QJsonObject>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "Module.h"
#include "main.h"
#include "Project.h"
#include "Trace.h"
#include "SaffronJSON.h"

/*****************************************************************************!
 * Function : Module
 *****************************************************************************/
Module::Module
() : SaffronComponent()
{
  Initialize();
}

/*****************************************************************************!
 * Function : Module
 *****************************************************************************/
Module::Module
(Project* InProject) : SaffronComponent()
{
  Initialize();
  SetParent(InProject);
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
Module::Initialize
()
{
  isOpened = false;
  displayData = NULL;
  displayWidget = NULL;
  background = QColor(208, 208, 208);
}

/*****************************************************************************!
 * Function : ~Module
 *****************************************************************************/
Module::~Module
()
{
}

/*****************************************************************************!
 * Function : FindMethod
 *****************************************************************************/
MemberMethod*
Module::FindMethod
(QString InMethodName)
{
  for ( QList<MemberMethod*>::iterator i ; i != methods.end(); i++ ) {
    if ( (*i)->GetName() == InMethodName ) {
      return (*i);
    }
  }
  return NULL;
}
  
/*****************************************************************************!
 * Function : GetTypeName
 *****************************************************************************/
QString
Module::GetTypeName
()
{
  return "Module";
}

/*****************************************************************************!
 * Function : Create
 *****************************************************************************/
Module*
Module::Create
(Project* InProjectParent, QString InName)
{
  Module*                               module;

  module = new Module(InProjectParent);
  module->setParent(InProjectParent);
  module->SetName(InName);
  module->SaveNew();

  return module;
}

/*****************************************************************************!
 * Function : CreateDisplay
 *****************************************************************************/
void
Module::CreateDisplay
(QString InName)
{
  CreateDisplay(0, 0, InName);
}

/*****************************************************************************!
 * Function : CreateDisplay
 *****************************************************************************/
void
Module::CreateDisplay
(QPoint InPos, QString InName)
{
  CreateDisplay(InPos.x(), InPos.y(), InName);
}

/*****************************************************************************!
 * Function : CreateDisplay
 *****************************************************************************/
void
Module::CreateDisplay
(int InX, int InY, QString InName)
{
  projectPosition = QPoint(InX, InY);
  displayWidget = new ModuleDisplayWidget(this, InName);
  displayData = displayWidget->GetDisplayData();
  displayWidget->move(InX, InY);
  SaveConfig();
}

/*****************************************************************************!
 * Function : GetDisplay 
 *****************************************************************************/
ModuleDisplayWidget*
Module::GetDisplay()
{
  return displayWidget;
}

/*****************************************************************************!
 * Function : SaveNew
 *****************************************************************************/
void
Module::SaveNew(void)
{
  QString                               configFilename;
  QDir                                  dir;
  QString                               projectPath;
  Project*                              p;
  QString                               s2;

  s2 = GetIDString();
  s2 = s2.replace(":", "-");
  p = (Project*)GetParent();
  projectPath = p->GetProjectPath() + s2;
  dir.mkdir(projectPath);
  configFilename = projectPath + QString("/config.json");
  CreateConfigFile(configFilename);
}

/*****************************************************************************!
 * Function : SaveConfig
 *****************************************************************************/
void
Module::SaveConfig
()
{
  QString                               configFilename;
  QString                               projectPath;
  Project*                              p;
  QString                               s2;

  s2 = GetIDString();
  s2 = s2.replace(":", "-");
  p = (Project*)GetParent();
  projectPath = p->GetProjectPath() + s2;
  configFilename = projectPath + QString("/config.json");
  RemoveConfigFile(configFilename);
  CreateConfigFile(configFilename);
}

/*****************************************************************************!
 * Function : CreateConfigFile
 *****************************************************************************/
void
Module::CreateConfigFile
(QString InConfigFilename)
{
  QString                               s;
  QByteArray                            jsonByteArray;
  QJsonDocument                         jsonDoc;
  QJsonObject                           topObject;
  QJsonObject                           posObj;
  QJsonObject                           sizeObj;
  int                                   x, y, width, height;
  
  QFile file(InConfigFilename);
  if ( ! file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate) ) {
    return;
  }

  topObject = jsonDoc.object();
  CreateIDConfigFile(topObject);

  x = 0;
  y = 0;
  width = 0;
  height = 0;
  if ( displayWidget ) {
    x = displayWidget->pos().x();
    y = displayWidget->pos().y();
    width = displayWidget->size().width();
    height = displayWidget->size().height();
  }
  posObj["x"] = x;
  posObj["y"] = y;
  sizeObj["width"] = width;
  sizeObj["height"] = height;
  
  topObject["pos"] = posObj;
  topObject["size"] = sizeObj;
 
  if ( displayData ) {
    displayData->CreateJSON(topObject);
  }
  jsonDoc.setObject(topObject);
  jsonByteArray = jsonDoc.toJson();
  s = QString(jsonByteArray);
  file.write(jsonByteArray);
  file.close();
}

/*****************************************************************************!
 * Function : Open
 *****************************************************************************/
void
Module::Open
(QString InDirectoryName)
{
  QString                               fullFilename;
  QDir                                  dir(InDirectoryName);

  dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
  QFileInfoList dirs = dir.entryInfoList();
  for ( int i = 0 ; i < dirs.size(); i++ ) {
    QFileInfo fileInfo = dirs.at(i);
    QString filename = fileInfo.fileName();
    if ( filename == "config.json") {
      fullFilename = InDirectoryName + "/" + filename;
      OpenConfigFile(fullFilename);
    }
  }
}

/*****************************************************************************!
 * Function : OpenConfigFile
 *****************************************************************************/
void
Module::OpenConfigFile
(QString InFullFilename)
{
  QJsonParseError                       jsonError;
  QString                               s;
  QJsonValue                            idVal;
  QJsonObject                           idObj;
  QJsonObject                           docObject;
  QJsonDocument                         jsonDoc;
  QByteArray                            bytes;
  
  QFile                                 file(InFullFilename);

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

  idObj = idVal.toObject();
  if ( idObj.isEmpty() ) {
    return;
  }

  displayData = new SaffronComponentDisplayData();
  displayData->FromJSON(docObject, "display");
  FromJSON(idObj);
  widgetPos = SaffronJSON::ReadPoint(docObject, "pos");
  widgetSize = SaffronJSON::ReadSize(docObject, "size");
  displayWidget = new ModuleDisplayWidget(this, GetName()->ToString(), displayData, widgetPos, widgetSize);
}

/*****************************************************************************!
 * Function : SetPosition
 *****************************************************************************/
void
Module::SetPosition
(QPoint InPosition)
{
  Project*                              p;
  QString                               projectPath;
  QString                               configFilename;
  QDir                                  dir;
  QString                               s2;
  
  s2 = GetIDString();
  s2 = s2.replace(":", "-");
  widgetPos = InPosition;
  displayData->SetPosition(InPosition);
  p = (Project*)GetParent();
  projectPath = p->GetProjectPath() + s2;
  configFilename = projectPath + QString("/config.json");
  CreateConfigFile(configFilename);
}

/*****************************************************************************!
 * Function : SetName
 *****************************************************************************/
void
Module::SetName
(QString InName)
{
  SaffronComponent::SetName(InName);
  SaveConfig();
}

/*****************************************************************************!
 * Function : GetFullConfigFilename
 *****************************************************************************/
QString
Module::GetFullConfigFilename
()
{
  Project*                              p;
  QString                               projectPath;
  QString                               configFilename;
  QString                               s2;
  
  s2 = GetIDString();
  s2 = s2.replace(":", "-");
  p = (Project*)GetParent();
  projectPath = p->GetProjectPath() + s2;
  configFilename = projectPath + QString("/config.json");
  return configFilename;
}

/*****************************************************************************!
 * Function : GetBackgroundBrush
 *****************************************************************************/
QBrush
Module::GetBackgroundBrush(QSize InSize)
{
  QLinearGradient                       grad(0, 0, 0, InSize.height());
  grad.setColorAt(0, QColor(background.darker(200)));
  grad.setColorAt(1, QColor(background));
  return QBrush(grad);
}

/*****************************************************************************!
 * Function : AddDataElement
 *****************************************************************************/
void
Module::AddDataElement
(MemberData* InData)
{
  if ( NULL == InData ) {
    return;
  }
  
  properties << InData;
}

/*****************************************************************************!
 * Function : GetPath
 *****************************************************************************/
QString
Module::GetPath(void)
{
  QString                               s2;
  Project*                              p;
  QString                               projectPath;
  
  s2 = GetIDString();
  s2 = s2.replace(":", "-");
  p = (Project*)GetParent();
  projectPath = p->GetProjectPath() + s2;

  return projectPath;
}

/*****************************************************************************!
 * Function : OpenDataElements
 *****************************************************************************/
void
Module::OpenDataElements
(QString InDirectoryName)
{
  QString                               fullFileName;
  QString                               path;
  QDir                                  dir(InDirectoryName);
  MemberData*                           member;
  int                                   n;

  dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
  QFileInfoList dirs = dir.entryInfoList();
  n = dirs.size();
  for ( int i = 0 ; i < n; i++ ) {
    QFileInfo fileInfo = dirs.at(i);
    QString filename = fileInfo.fileName();
    path = GetPath();
    fullFileName = path + QString("/") + filename + QString("/config.json");
    member = new MemberData(this);
    member->ReadConfig(fullFileName);
    // member->CreateDisplay(QString(""));
    properties << member;
  }
  isOpened = true;
}

/*****************************************************************************!
 * Function : GetDataCount
 *****************************************************************************/
int
Module::GetDataCount
()
{
  return properties.count();
}

/*****************************************************************************!
 * Function : GetDataByIndex
 *****************************************************************************/
MemberData*
Module::GetDataByIndex
(int InIndex)
{
  if ( InIndex >= properties.count() ) {
    return NULL;
  }

  return properties[InIndex];
}

/*****************************************************************************!
 * Function : MemberDataDelete
 *****************************************************************************/
void
Module::MemberDataDelete
(MemberData* InMemberData)
{
  QString                               configFilename;
  properties.removeOne(InMemberData);
  InMemberData->RemoveStorage();
  delete InMemberData;
}

/*****************************************************************************!
 * Function : RemoveStorage
 *****************************************************************************/
void
Module::RemoveStorage
(void)
{
  QString                               pathName;
  
  pathName = GetPath();
  QDir d(pathName);
  if ( ! d.removeRecursively() ) {
  }
}

/*****************************************************************************!
 * Function : GetIsOpened
 *****************************************************************************/
bool
Module::GetIsOpened(void)
{
  return isOpened;  
}

/*****************************************************************************!
 * Function : SetIsOpened
 *****************************************************************************/
void
Module::SetIsOpened
(bool InIsOpened)
{
  isOpened = InIsOpened;  
}

/*****************************************************************************!
 * Function : RemoveConfigFile
 *****************************************************************************/
void
Module::RemoveConfigFile
(QString InConfigFileName)
{
  QDir                                  d;
  d.remove(InConfigFileName);
}
