/*****************************************************************************
 * FILE NAME    : SaffronComponentFillSolid.cpp
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
#include "SaffronComponentFillSolid.h"
#include "SaffronJSON.h"

/*****************************************************************************!
 * Function : SaffronComponentFillSolid
 *****************************************************************************/
SaffronComponentFillSolid::SaffronComponentFillSolid
(QString InName, int InPosition) : SaffronComponentFill(InName, InPosition)
{
}

/*****************************************************************************!
 * Function : ~SaffronComponentFillSolid
 *****************************************************************************/
SaffronComponentFillSolid::~SaffronComponentFillSolid
()
{
}

/*****************************************************************************!
 * Function : GetBrush
 *****************************************************************************/
QBrush
SaffronComponentFillSolid::GetBrush
(void)
{
  return QBrush();
}

/*****************************************************************************!
 * Function : SetColor
 *****************************************************************************/
void
SaffronComponentFillSolid::SetColor
(QColor InColor)
{
  color = InColor;
}

/*****************************************************************************!
 * Function : GetType
 *****************************************************************************/
QString
SaffronComponentFillSolid::GetType
()
{
  return "solid";
}

/*****************************************************************************!
 * 
 *****************************************************************************/
QString
SaffronComponentFillSolid::GetSVGString
(void)
{

  return QString();
}

/*****************************************************************************!
 * 
 *****************************************************************************/
QString
SaffronComponentFillSolid::GetSVGString
(QString InFillName)
{
  (void)InFillName;
  return QString();
}

/*****************************************************************************!
 * Function : CreateJSON
 *****************************************************************************/
void
SaffronComponentFillSolid::CreateJSON
(QJsonObject& InObject)
{
  QJsonObject                           solid;
  QJsonObject                           c;
  
  InObject["type"] = GetType();

  c["red"] = color.red();
  c["blue"] = color.blue();
  c["green"] = color.green();
  c["alpha"] = color.alpha();

  solid["color"] = c;
  InObject["solid"] = solid;  
}

/*****************************************************************************!
 * Function : FromJSON
 *****************************************************************************/
void
SaffronComponentFillSolid::FromJSON
(QJsonObject& InObject)
{
  QJsonObject                           solidObj;

  solidObj = InObject["solid"].toObject();
  if ( solidObj.isEmpty() ) {
    return;
  }

  color = SaffronJSON::ReadColor(solidObj, "color");
}

/*****************************************************************************!
 * Function : Copy
 *****************************************************************************/
class SaffronComponentFill*
SaffronComponentFillSolid::Copy
()
{
  SaffronComponentFillSolid*                    fill;

  fill = new SaffronComponentFillSolid(GetName(), GetRotation());
  fill->SetColor(QColor(color));
  return fill;
}

