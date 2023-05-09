/*****************************************************************************
 * FILE NAME    : SaffronJSON.cpp
 * DATE         : December 21 2022
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
#include "SaffronJSON.h"

/*****************************************************************************!
 * Function : SaffronJSON
 *****************************************************************************/
SaffronJSON::SaffronJSON
() : QWidget()
{
}

/*****************************************************************************!
 * Function : ~SaffronJSON
 *****************************************************************************/
SaffronJSON::~SaffronJSON
()
{
}

/*****************************************************************************!
 * Function : ReadPoint
 *****************************************************************************/
QPoint
SaffronJSON::ReadPoint
(QJsonObject& InObject, QString InName)
{
  int                           x, y;
  QJsonValue                    pointVal;
  QJsonObject                   pointObj;
  pointVal = InObject[InName];
  if ( ! pointVal.isObject() ) {
    return QPoint(0, 0);
  }
  pointObj = pointVal.toObject();
  if ( pointObj.isEmpty() ) {
    return QPoint(0, 0);
  }

  x = pointObj["x"].toInt();
  y = pointObj["y"].toInt();
  return QPoint(x, y);
}

/*****************************************************************************!
 * Function : ReadSize
 *****************************************************************************/
QSize
SaffronJSON::ReadSize
(QJsonObject& InObject, QString InName)
{
  int                           width, height;
  QJsonValue                    sizeVal;
  QJsonObject                   sizeObj;
  
  sizeVal = InObject[InName];
  if ( ! sizeVal.isObject() ) {
    return QSize(0, 0);
  }
  sizeObj = sizeVal.toObject();
  if ( sizeObj.isEmpty() ) {
    return QSize(0, 0);
  }

  height = sizeObj["height"].toInt();
  width = sizeObj["width"].toInt();

  return QSize(width, height);
}

/*****************************************************************************!
 * Function : ReadColor
 *****************************************************************************/
QColor
SaffronJSON::ReadColor
(QJsonObject& InObject, QString InName)
{
  int                           red, blue, green, alpha;
  QJsonObject                   colorObj;
  
  colorObj = InObject[InName].toObject();
  if ( colorObj.isEmpty() ) {
    return QColor();
  }

  red = colorObj["red"].toInt();
  green = colorObj["green"].toInt();
  blue = colorObj["blue"].toInt();
  alpha = colorObj["alpha"].toInt();

  return QColor(red, green, blue, alpha);
}
