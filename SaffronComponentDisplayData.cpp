/*****************************************************************************
 * FILE NAME    : SaffronComponentDisplayData.cpp
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
#include "SaffronComponentDisplayData.h"
#include "SaffronComponentFillSolid.h"
#include "SaffronComponentFillGradient.h"
#include "SaffronComponentFillGradientStop.h"
#include "SaffronJSON.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : SaffronComponentDisplayData
 *****************************************************************************/
SaffronComponentDisplayData::SaffronComponentDisplayData
() : QWidget()
{
  SaffronComponentFillGradientStop*             stop;
  SaffronComponentFillGradient*                 grad;
  
  grad = new SaffronComponentFillGradient("moduleGradient", 90.0);
  stop = new SaffronComponentFillGradientStop(0, QColor("#880000"));
  grad->AddStop(stop);
  stop = new SaffronComponentFillGradientStop(1, QColor("#ff8080"), .4);
  grad->AddStop(stop);

  background = grad;
}

/*****************************************************************************!
 * Function : SaffronComponentDisplayData
 *****************************************************************************/
SaffronComponentDisplayData::SaffronComponentDisplayData
(DataType::DataTypeType InType) : QWidget()
{
  background = DataType::GetFillByType(InType);
}

/*****************************************************************************!
 * Function : SaffronComponentDisplayData
 *****************************************************************************/
SaffronComponentDisplayData::SaffronComponentDisplayData
(SaffronComponentFill* InBackground) : QWidget()
{
  background = InBackground;
}

/*****************************************************************************!
 * Function : SaffronComponentDisplayData
 *****************************************************************************/
SaffronComponentDisplayData::SaffronComponentDisplayData
(QJsonObject& InObject, QString InName) : QWidget()
{
  FromJSON(InObject, InName);
}

/*****************************************************************************!
 * Function : ~SaffronComponentDisplayData
 *****************************************************************************/
SaffronComponentDisplayData::~SaffronComponentDisplayData
()
{
  delete background;
}

/*****************************************************************************!
 * Function : SetPosition
 *****************************************************************************/
void
SaffronComponentDisplayData::SetPosition
(QPoint InPoint)
{
  position = InPoint;
}

/*****************************************************************************!
 * Function : SetSize
 *****************************************************************************/
void
SaffronComponentDisplayData::SetSize
(QSize InSize)
{
  componentSize = InSize;
}

/*****************************************************************************!
 * Function : GetSVGSizeString
 *****************************************************************************/
QString
SaffronComponentDisplayData::GetSVGSizeString(void)
{
  QString                               st;

  st = QString("width= \"%1\" height=\"%2\"").arg(componentSize.width()).arg(componentSize.height());
  return st;
}

/*****************************************************************************!
 * Function : GetSVGFillString
 *****************************************************************************/
QString
SaffronComponentDisplayData::GetSVGFillString(void)
{
  QString                               svgString;

  svgString = background->GetSVGString();
  return svgString;
}

/*****************************************************************************!
 * Function : GetSVGFillString
 *****************************************************************************/
QString
SaffronComponentDisplayData::GetSVGFillString
(QString InFillName)
{
  QString                               svgString;

  svgString = background->GetSVGString(InFillName);
  return svgString;
}

/*****************************************************************************!
 * Function : CreateJSON
 *****************************************************************************/
void
SaffronComponentDisplayData::CreateJSON
(QJsonObject& InObject)
{
  QJsonObject                           s;
  QJsonObject                           pos;
  QJsonObject                           si;
  QJsonObject                           ba;

  pos["x"] = position.x();
  pos["y"] = position.y();

  si["width"] = componentSize.width();
  si["height"] = componentSize.height();

  background->CreateJSON(ba);
  
  s["pos"] = pos;
  s["size"] = si;
  s["fill"] = ba;

  InObject["display"] = s;
}

/*****************************************************************************!
 * Function : FromJSON
 *****************************************************************************/
void
SaffronComponentDisplayData::FromJSON
(QJsonObject& InObject, QString InName)
{
  QJsonObject                           displayObj;
  QJsonValue                            displayVal;
  QJsonObject                           fillObj;
  QString                               fillType;
  QJsonObject                           posObj;
  QJsonObject                           sizeObj;

  displayVal = InObject[InName];
  displayObj = displayVal.toObject();
  if ( displayObj.isEmpty() ) {
    return;
  }

  position = SaffronJSON::ReadPoint(displayObj, "pos");
  componentSize = SaffronJSON::ReadSize(displayObj, "size");
  move(position);
  resize(componentSize);
  fillObj = displayObj["fill"].toObject();
  if ( fillObj.isEmpty() ) {
    return;
  }

  fillType = fillObj["type"].toString();
  if ( fillType != "gradient" && fillType != "solid" ) {
    return;
  }
  if ( fillType == "gradient" ) {
    background = new SaffronComponentFillGradient("moduleGradient", 0);
    background->FromJSON(fillObj);
    auto st = background->GetSVGString("moduleGradient");
    return;
  }
  background = new SaffronComponentFillSolid("moduleGradient", 0);
  background->FromJSON(fillObj);
}

/*****************************************************************************!
 * Function : GetPosition
 *****************************************************************************/
QPoint
SaffronComponentDisplayData::GetPosition(void)
{
  return position;
}

/*****************************************************************************!
 * Function : GetFill
 *****************************************************************************/
SaffronComponentFill*
SaffronComponentDisplayData::GetFill
()
{
  return background;
}

/*****************************************************************************!
 * Function : ReplaceFill
 *****************************************************************************/
void
SaffronComponentDisplayData::ReplaceFill
(SaffronComponentFill* InFill)
{
  if ( background ) {
    delete background;
  }
  background = InFill;
}

/*****************************************************************************!
 * Function : GetSize
 *****************************************************************************/
QSize
SaffronComponentDisplayData::GetSize
()
{
  return componentSize;
}

/*****************************************************************************!
 * Function : Copy
 *****************************************************************************/
SaffronComponentDisplayData*
SaffronComponentDisplayData::Copy
()
{
  SaffronComponentDisplayData*          data;

  data = new SaffronComponentDisplayData();
  data->SetPosition(position);
  data->SetSize(componentSize);
  data->background = background->Copy();

  return data;
}
