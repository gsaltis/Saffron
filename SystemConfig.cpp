/*****************************************************************************
 * FILE NAME    : SystemConfig.cpp
 * DATE         : November 15 2022
 * PROJECT      : Saffron
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QJsonDocument>
#include <QScreen>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SystemConfig.h"
#include "Trace.h"
#include "DataType.h"

/*****************************************************************************!
 * Static Data
 *****************************************************************************/
QString SystemConfig::SystemName = "Saffron";

/*****************************************************************************!
 * Function : SystemConfig
 *****************************************************************************/
SystemConfig::SystemConfig
() : QWidget()
{
  Initialize();
}

/*****************************************************************************!
 * Function : ~SystemConfig
 *****************************************************************************/
SystemConfig::~SystemConfig
()
{
}

/*****************************************************************************!
 * Function : Read
 * Purpose  : Read the system configuration information
 *****************************************************************************/
void
SystemConfig::Read
(QString InFilename)
{
  QJsonObject                           projectsObject;
  QJsonObject                           jsonObject;
  QJsonObject                           displayObject;
  QJsonArray                            dataTypeFills;
  QByteArray                            data;
  QJsonDocument                         json;
  QFile                                 file(InFilename);
  
  if ( ! file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
    return;
  }

  data = file.readAll();
  file.close();

  json = QJsonDocument::fromJson(data);

  if ( ! json.isObject() ) {
    return;
  }

  jsonObject = json.object();
  displayObject = jsonObject["Display"].toObject();
  ReadDisplayObject(displayObject);
  projectsObject = jsonObject["Projects"].toObject();
  ReadProjectsObject(projectsObject);
  dataTypeFills = jsonObject["DataTypeFills"].toArray();
  DataType::DataTypeFillFromJSON(&dataTypeFills);
}

/*****************************************************************************!
 * Function : ReadDisplayObject
 *****************************************************************************/
void
SystemConfig::ReadDisplayObject
(QJsonObject InDisplayObject)
{
  QSize                         screenSize;
  QString                       s;
  QScreen*                      screen;

  screen = QGuiApplication::primaryScreen();
  
  screenSize = screen->size();
  if ( InDisplayObject.isEmpty() ) {
    return;
  }

  if ( InDisplayObject.contains("x") ) {
    displayX = InDisplayObject["x"].toInt();
  }
  
  if ( InDisplayObject.contains("y") ) {
    displayY = InDisplayObject["y"].toInt();
  }
  
         
  if ( InDisplayObject.contains("width") ) {
    s = InDisplayObject["width"].toString();
    if ( s == QString("ScreenWidth") ) {
      displayWidth = screenSize.width();
    } else {                        
      displayWidth = InDisplayObject["width"].toInt();
    }
  }
  
  if ( InDisplayObject.contains("height") ) {
    s = InDisplayObject["height"].toString();
    if ( s == QString("ScreenHeight") ) {
      displayHeight = screenSize.height() - 60;
    } else {                        
      displayHeight = InDisplayObject["height"].toInt();
    }
  }
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
SystemConfig::Initialize(void)
{
  displayWidth  = 640;
  displayHeight = 480;
  displayX      = 200;
  displayY      = 200;
}

/*****************************************************************************!
 * Function : GetDisplayPos
 *****************************************************************************/
QPoint
SystemConfig::GetDisplayPos(void)
{
  return QPoint(displayX, displayY);
}

/*****************************************************************************!
 * Function : GetDisplaySize
 *****************************************************************************/
QSize
SystemConfig::GetDisplaySize(void)
{
  return QSize(displayWidth, displayHeight);
}

/*****************************************************************************!
 * Function : ReadProjectsObject
 *****************************************************************************/
void
SystemConfig::ReadProjectsObject
(QJsonObject InObject)
{
  QString                               s;
  
  if ( InObject.contains("BasePath") ) {
    s = InObject["BasePath"].toString();
    projectsBasePath = PathResolve(s);
  }
}

/*****************************************************************************!
 * Function : GetProjectsBasePath
 *****************************************************************************/
QString
SystemConfig::GetProjectsBasePath(void)
{
  return projectsBasePath;  
}

/*****************************************************************************!
 * Function : SetProjectsBasePath
 *****************************************************************************/
void
SystemConfig::SetProjectsBasePath
(QString InProjectsBasePath)
{
  projectsBasePath = InProjectsBasePath;  
}

/*****************************************************************************!
 * Function : PathResolve
 *****************************************************************************/
QString
SystemConfig::PathResolve
(QString InPathname)
{
  QChar                                 ch;
  QString                               s3;
  QString                               s;
  QString                               s1;
  int                                   size;
  int                                   start;
  int                                   end;
  int                                   i;
  int                                   n;
  QList<QString>                        elements;

  n = InPathname.size();
  for ( i = 0; i < n ; i++ ) {
    ch = InPathname[i];
    if ( ch == '$' ) {
      i++;
      if ( i == n ) {
        break;
      }
      ch = InPathname[i];
      if ( ch != '{' ) {
        break;
      }
      start = i + 1;
      end = start;
      ch = InPathname[end];
      if ( end == n ) {
        break;
      }
      while (ch != '}' ){
        end++;
        if ( end == n ) {
          break;
        }
        ch = InPathname[end];
      }
      size = end - start;
      s = InPathname.sliced(start, size);
      s1 = VariableResolve(s);
      elements << s1;
      i = end;
      continue;
    }
    for ( end = start = i; end < n ; end++ ) {
      ch = InPathname[end];
      if ( ch == '$' ) {
        size = end - start;
        s = InPathname.sliced(start, size);
        s1 = VariableResolve(s);
        elements << s1;
        i = end - 1;
        continue;
      }
    }
    size = end - start;
    s = InPathname.sliced(start, size);
    elements << s;
    i = end;
  }
  s3 = QString();
  for ( i = 0 ; i < elements.count(); i++ ) {
    s3 += elements[i];
  }
  for ( i = 0 ; i < s3.size(); i++ ) {
    if ( s3[i] == '\\' ) {
      s3[i] = '/';
    }
  }
  return s3;
}

/*****************************************************************************!
 * Function : VariableResolve
 *****************************************************************************/
QString
SystemConfig::VariableResolve
(QString InVarname)
{
  char*                                 s;
  QString                               s2;
  
  if ( InVarname == "HOME" ) {
    s = getenv("HOMEPATH");
    s2 = QString(s);
    return s2;
  }

  if ( InVarname == "APP" ) {
    return QCoreApplication::applicationDirPath();
  }

  if ( InVarname == "INSTALL" ) {
    s = getenv("SAFFRONINSTALL");
    s2 = QString(s);
    return s2;
  }
  return QString("");
}

