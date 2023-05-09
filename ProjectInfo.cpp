/*****************************************************************************
 * FILE NAME    : ProjectInfo.cpp
 * DATE         : December 02 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QJsonDocument>
#include <QJsonObject>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ProjectInfo.h"

/*****************************************************************************!
 * Function : ProjectInfo
 *****************************************************************************/
ProjectInfo::ProjectInfo
() : QWidget()
{
  Initialize();
}

/*****************************************************************************!
 * Function : ProjectInfo
 *****************************************************************************/
ProjectInfo::ProjectInfo
(QString InName, QString InDescription, QDateTime InDateTime) : QWidget()
{
  Initialize();
  name = QString(InName);
  description = QString(InDescription);
  dateTime = InDateTime;
}

/*****************************************************************************!
 * Function : ProjectInfo
 *****************************************************************************/
ProjectInfo::ProjectInfo
(QString InFilename)
{
  QByteArray                            fileContents;
  QString                               configFilename;
  QFileInfo                             fileInfo(InFilename);
  QJsonDocument                         jsonDoc;
  QJsonObject                           mainObject;
  QJsonObject                           idObject;
  
  if ( !fileInfo.exists() ) {
    return;
  }

  dateTime = fileInfo.fileTime(QFileDevice::FileModificationTime);
  configFilename = InFilename + QString("/config.json");
  QFile file(configFilename);
  if ( ! file.open(QIODeviceBase::ReadOnly) ) {
    return;
  }
  fileContents = file.readAll();
  if ( fileContents.isNull() ) {
    return;
  }
  jsonDoc = QJsonDocument::fromJson(fileContents);
  if ( jsonDoc.isEmpty() || jsonDoc.isNull() ) {
    return;
  }

  mainObject = jsonDoc.object();

  idObject = mainObject["id"].toObject();
  name = idObject["name"].toString();
    description = idObject["description"].toString();
  opened = true;
}

/*****************************************************************************!
 * Function : ~ProjectInfo
 *****************************************************************************/
ProjectInfo::~ProjectInfo
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
ProjectInfo::Initialize(void)
{
  name = QString("");
  description = QString("");
  dateTime = QDateTime::currentDateTime();
  opened = false;
}

/*****************************************************************************!
 * Function : IsOpened
 *****************************************************************************/
bool
ProjectInfo::IsOpened(void)
{
  return opened;
}

/*****************************************************************************!
 * Function : GetName
 *****************************************************************************/
QString
ProjectInfo::GetName(void)
{
  return QString(name);
}

/*****************************************************************************!
 * Function : GetDescription
 *****************************************************************************/
QString
ProjectInfo::GetDescription(void)
{
  return QString(description);
}

/*****************************************************************************!
 * Function : GetDateTime
 *****************************************************************************/
QDateTime
ProjectInfo::GetDateTime(void)
{
  return QDateTime(dateTime);
}

/*****************************************************************************!
 * Function : Exists
 *****************************************************************************/
bool
ProjectInfo::Exists
(QString InFilename)
{
  QFileInfo                             fileinfo(InFilename);

  
  if ( ! fileinfo.exists() ) {
    return false;
  }

  if ( ! fileinfo.isDir() ) {
    return false;
  }
  return true;
}
