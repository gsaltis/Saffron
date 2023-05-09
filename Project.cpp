/*****************************************************************************
 * FILE NAME    : Project.cpp
 * DATE         : November 21 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "Project.h"
#include "SystemConfig.h"
#include "main.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : Project
 *****************************************************************************/
Project::Project
() : SaffronComponent()
{

}

/*****************************************************************************!
 * Function : ~Project
 *****************************************************************************/
Project::~Project
()
{
  
}

/*****************************************************************************!
 * Function : Exists
 *****************************************************************************/
bool
Project::Exists
(QString InProjectName)
{
  QString                               fullPathName;
  QDir                                  dir;
  
  if ( InProjectName.isEmpty() ) {
    return false;
  }

  fullPathName = mainSystemConfig->GetProjectsBasePath() + InProjectName;
  return dir.exists(fullPathName);
}

/*****************************************************************************!
 * Function : Create
 *****************************************************************************/
bool
Project::Create
(QString InProjectName)
{
  QString                               configFilename;
  bool                                  t;
  QString                               fullPathName;
  QDir                                  dir;
  
  if ( InProjectName.isEmpty() ) {
    return false;
  }

  fullPathName = mainSystemConfig->GetProjectsBasePath() + InProjectName;
  t = dir.mkdir(fullPathName);
  if ( ! t ) {
    return false;
  }

  SetName(InProjectName);
  configFilename = fullPathName + QString("/config.json");
  CreateConfigFile(configFilename);
  return true;
}

/*****************************************************************************!
 * Function : CreateConfigFile
 *****************************************************************************/
void
Project::CreateConfigFile
(QString InConfigFilename)
{
  QString                               s;
  QByteArray                            jsonByteArray;
  QJsonDocument                         jsonDoc;
  QJsonObject                           topObject;
  
  QFile file(InConfigFilename);
  if ( ! file.open(QIODevice::ReadWrite | QIODevice::Text) ) {
    return;
  }

  topObject = jsonDoc.object();
  CreateIDConfigFile(topObject);

  jsonDoc.setObject(topObject);
  jsonByteArray = jsonDoc.toJson();
  s = QString(jsonByteArray);
  file.write(jsonByteArray);
  file.close();
}

/*****************************************************************************!
 * Function : GetTypeName
 *****************************************************************************/
QString
Project::GetTypeName(void)
{
  return QString("Project");
}


/*****************************************************************************!
 * Function : Open
 *****************************************************************************/
bool
Project::Open(QString InProjectName)
{
  QString                               moduleDirName;
  Module*                               module;
  QString                               dirPath;

  SetName(InProjectName);

  dirPath = mainSystemConfig->GetProjectsBasePath() + GetName()->ToString() + "/";
  QDir dir(dirPath);

  dir.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
  QFileInfoList dirs = dir.entryInfoList();
  for ( int i = 0 ; i < dirs.size(); i++ ) {
    QFileInfo fileInfo = dirs.at(i);
    QString filename = fileInfo.fileName();
    moduleDirName = dirPath + filename;
    module = new Module(this);
    module->Open(moduleDirName);
    modules << module;
  }
  
  return true;
}

/*****************************************************************************!
 * Function : ModuleExists
 *****************************************************************************/
bool
Project::ModuleExists
(QString InModuleName)
{
  QString                               fullPathName;
  QDir                                  dir;

  if ( InModuleName.isEmpty() ) {
    return false;
  }

  fullPathName = mainSystemConfig->GetProjectsBasePath() + GetName()->ToString() + "/" + InModuleName;
  return dir.exists(fullPathName);
}

/*****************************************************************************!
 * Function : GetProjectPath
 *****************************************************************************/
QString
Project::GetProjectPath(void)
{
  QString                               fullPathName;
  
  fullPathName = mainSystemConfig->GetProjectsBasePath() + GetName()->ToString() + "/";
  return fullPathName;
}

/*****************************************************************************!
 * Function : GetModuleCount
 *****************************************************************************/
int
Project::GetModuleCount
()
{
  return modules.count();
}

/*****************************************************************************!
 * Function : GetModuleByIndex
 *****************************************************************************/
Module*
Project::GetModuleByIndex
(int InIndex)
{
  if ( InIndex < 0 || InIndex >= modules.count() ) {
    return NULL;
  }
  return modules[InIndex];
}

/*****************************************************************************!
 * Function : GetModuleNames
 *****************************************************************************/
QList<QString>
Project::GetModuleNames
()
{
  QList<QString>                        moduleNames;
  
  for ( auto i = modules.begin(); i != modules.end() ; i++ ) {
    auto module = *i;

    moduleNames << module->GetName()->ToString();
  }
  return moduleNames;
}
