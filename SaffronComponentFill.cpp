/*****************************************************************************
 * FILE NAME    : SaffronComponentFill.cpp
 * DATE         : December 17 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
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
#include "SaffronComponentFill.h"

/*****************************************************************************!
 * Function : SaffronComponentFill
 *****************************************************************************/
SaffronComponentFill::SaffronComponentFill
(QString InName, int InRotation) : QWidget()
{
  SetRotation(InRotation);
  SetName(InName);
}

/*****************************************************************************!
 * Function : ~SaffronComponentFill
 *****************************************************************************/
SaffronComponentFill::~SaffronComponentFill
()
{
}

/*****************************************************************************!
 * Function : SetRotation
 *****************************************************************************/
void
SaffronComponentFill::SetRotation
(int InRotation)
{
  rotation = InRotation;
}

/*****************************************************************************!
 * Function : SetName
 *****************************************************************************/
void
SaffronComponentFill::SetName
(QString InName)
{
  name = InName;
}

/*****************************************************************************!
 * Function : GetName
 *****************************************************************************/
QString
SaffronComponentFill::GetName
()
{
  return name;
}

/*****************************************************************************!
 * Function : GetRotation
 *****************************************************************************/
int
SaffronComponentFill::GetRotation(void)
{
  return rotation;
}

/*****************************************************************************!
 * Function : FromJSON
 *****************************************************************************/
void
SaffronComponentFill::FromJSON
(QJsonObject& InObject)
{
  name = InObject["name"].toString();
  rotation = InObject["rotation"].toInt();
}

/*****************************************************************************!
 * Function : CreateJSON
 *****************************************************************************/
void
SaffronComponentFill::CreateJSON
(QJsonObject& InObject)
{
  InObject["name"] = name;
  InObject["rotation"] = rotation;
}

