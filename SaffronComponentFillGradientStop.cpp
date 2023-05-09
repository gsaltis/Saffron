/*****************************************************************************
 * FILE NAME    : SaffronComponentFillGradientStop.cpp
 * DATE         : December 19 2022
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
#include "SaffronComponentFillGradientStop.h"
#include "SaffronJSON.h"
#include "trace.h"

/*****************************************************************************!
 * Function : SaffronComponentFillGradientStop
 *****************************************************************************/
SaffronComponentFillGradientStop::SaffronComponentFillGradientStop
(qreal InPosition, QColor InColor, qreal InOpacity) : QWidget()
{
  SetPosition(InPosition);
  SetColor(InColor);
  SetOpacity(InOpacity);
}

/*****************************************************************************!
 * Function : SaffronComponentFillGradientStop
 *****************************************************************************/
SaffronComponentFillGradientStop::SaffronComponentFillGradientStop
()
{
  position = 0;
  color = QColor(255, 255, 255);
  opacity = 1;
}

/*****************************************************************************!
 * Function : ~SaffronComponentFillGradientStop
 *****************************************************************************/
SaffronComponentFillGradientStop::~SaffronComponentFillGradientStop
()
{
}

/*****************************************************************************!
 * Function : SetPosition
 *****************************************************************************/
void
SaffronComponentFillGradientStop::SetPosition
(qreal InPosition)
{
  position = InPosition;
}

/*****************************************************************************!
 * Function : SetColor
 *****************************************************************************/
void
SaffronComponentFillGradientStop::SetColor
(QColor InColor)
{
  color = InColor;
}

/*****************************************************************************!
 * Function : SetOpacity
 *****************************************************************************/
void
SaffronComponentFillGradientStop::SetOpacity
(qreal InOpacity)
{
  opacity = InOpacity;
}

/*****************************************************************************!
 * Function : GetSVGString
 *****************************************************************************/
QString
SaffronComponentFillGradientStop::GetSVGString
()
{
  QString                               s;

  s = QString("<stop offset=\"%1\" stop-color=\"#%2%3%4\" stop-opacity=\"%5\"/>")
    .arg(position)
    .arg(color.red(), 2, 16, QLatin1Char('0'))
    .arg(color.green(), 2, 16, QLatin1Char('0'))
    .arg(color.blue(), 2, 16, QLatin1Char('0'))
    .arg(opacity);
  return s;
}

/*****************************************************************************!
 * Function : TOJSONObject
 *****************************************************************************/
QJsonObject
SaffronComponentFillGradientStop::TOJSONObject
(void)
{
  QJsonObject                           object = QJsonObject();

  return object;
}

/*****************************************************************************!
 * Function : CreateJSON
 *****************************************************************************/
void
SaffronComponentFillGradientStop::CreateJSON
(QJsonObject&                           InObject)
{
  QJsonObject                           col;
  
  InObject["position"] = position;
  InObject["opacity"]  = opacity;

  col = QJsonObject();
  col["red"] = color.red();
  col["green"] = color.green();
  col["blue"] = color.blue();
  col["alpha"] = color.alpha();

  InObject["color"] = col;
}

/*****************************************************************************!
 * Function : FromJSON
 *****************************************************************************/
void
SaffronComponentFillGradientStop::FromJSON
(QJsonObject& InObject)
{
  position = (qreal)InObject["position"].toDouble();
  opacity  = (qreal)InObject["opacity"].toDouble();
  color = SaffronJSON::ReadColor(InObject, "color");
}

/*****************************************************************************!
 * Function : GetColor
 *****************************************************************************/
QColor
SaffronComponentFillGradientStop::GetColor
()
{
  return color;
}

/*****************************************************************************!
 * Function : SaffronComponentFillGradientStop
 *****************************************************************************/
SaffronComponentFillGradientStop*
SaffronComponentFillGradientStop::Copy
()
{
  return new SaffronComponentFillGradientStop(GetPosition(),
                                              GetColor(),
                                              GetOpacity());
}

/*****************************************************************************!
 * Function : GetOpacity
 *****************************************************************************/
qreal
SaffronComponentFillGradientStop::GetOpacity(void)
{
  return opacity;
}

/*****************************************************************************!
 * Function : GetPosition
 *****************************************************************************/
qreal
SaffronComponentFillGradientStop::GetPosition(void)
{
  return position;
}
