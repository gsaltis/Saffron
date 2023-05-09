/*****************************************************************************
 * FILE NAME    : SaffronComponentFillGradient.cpp
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
#include "SaffronComponentFillGradient.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : SaffronComponentFillGradient
 *****************************************************************************/
SaffronComponentFillGradient::SaffronComponentFillGradient
(QString InName, int InPosition) : SaffronComponentFill(InName, InPosition)
{
}

/*****************************************************************************!
 * Function : SaffronComponentFillGradient
 *****************************************************************************/
SaffronComponentFillGradient::SaffronComponentFillGradient
() : SaffronComponentFill("None")
{
}

/*****************************************************************************!
 * Function : ~SaffronComponentFillGradient
 *****************************************************************************/
SaffronComponentFillGradient::~SaffronComponentFillGradient
()
{
  int                                   i;
  int                                   n;

  n = stops.count();

  for ( i = 0 ; i < n ; i++ ) {
    SaffronComponentFillGradientStop*   stop;

    stop = stops[i];
    delete stop;
  }
}

/*****************************************************************************!
 * Function : AddStop
 *****************************************************************************/
void
SaffronComponentFillGradient::AddStop
(SaffronComponentFillGradientStop* InStop)
{
  if ( NULL == InStop ) {
    return;
  }
  stops << InStop;
}

/*****************************************************************************!
 * Function : GetBrush
 *****************************************************************************/
QBrush
SaffronComponentFillGradient::GetBrush
(void)
{
  return QBrush();
}

/*****************************************************************************!
 * Function : GetType
 *****************************************************************************/
QString
SaffronComponentFillGradient::GetType(void)
{
  return "gradient";
}

/*****************************************************************************!
 * Function : GetSVGString
 *****************************************************************************/
QString
SaffronComponentFillGradient::GetSVGString
(void)
{
  return GetSVGString(GetName());
}

/*****************************************************************************!
 * Function : GetSVGString
 *****************************************************************************/
QString
SaffronComponentFillGradient::GetSVGString
(QString InFillName)
{
  QString                               st, st1;

  st = QString("<linearGradient id=\"%1\" gradientTransform=\"rotate(%2)\">\n")
    .arg(InFillName)
    .arg(GetRotation());
  for ( int i = 0 ; i < stops.count(); i++ ) {
    st1 = stops[i]->GetSVGString();
    st += st1 + QString("\n");
  }
  st += QString("</linearGradient>\n");
  return st;
}

/*****************************************************************************!
 * Function : CreateJSON
 *****************************************************************************/
void
SaffronComponentFillGradient::CreateJSON
(QJsonObject& InObject)
{
  QJsonObject                           obj;
  QJsonArray                            ar;

  InObject["type"] = GetType();

  ar = QJsonArray();

  for ( int i = 0 ; i < stops.count(); i++ ) {
    SaffronComponentFillGradientStop*   stop;
    QJsonObject                         ob;

    stop = stops[i];
    stop->CreateJSON(ob);

    QJsonValue                          val(ob);
    ar.push_back(val);
  }
  InObject["stops"] = ar;
  SaffronComponentFill::CreateJSON(InObject);
}

/*****************************************************************************!
 * Function : FromJSON
 *****************************************************************************/
void
SaffronComponentFillGradient::FromJSON
(QJsonObject& InObject)
{
  QJsonValue                            st;
  QJsonObject                           st1;
  SaffronComponentFillGradientStop*     stop;
  QJsonArray                            stopsArray;

  stopsArray = InObject["stops"].toArray();

  for ( QJsonArray::iterator i = stopsArray.begin() ; i != stopsArray.end(); i++ ) {
    stop = new SaffronComponentFillGradientStop();
    st = *i;
    st1 = st.toObject();
    stop->FromJSON(st1);
    stops << stop;
  }
  SaffronComponentFill::FromJSON(InObject);
}

/*****************************************************************************!
 * Function : GetStopCount
 *****************************************************************************/
int
SaffronComponentFillGradient::GetStopCount
()
{
  return stops.count();
}

/*****************************************************************************!
 * Function : GetStopByIndex
 *****************************************************************************/
SaffronComponentFillGradientStop*
SaffronComponentFillGradient::GetStopByIndex
(int InIndex)
{
  int                                   n = stops.count();

  if ( InIndex >= n ) {
    return NULL;
  }

  if ( InIndex < 0 ) {
    return NULL;
  }

  return stops[InIndex];
}

/*****************************************************************************!
 * Function : Copy
 *****************************************************************************/
class SaffronComponentFill*
SaffronComponentFillGradient::Copy
()
{
  SaffronComponentFillGradientStop*     newStop;
  SaffronComponentFillGradientStop*     stop;
  int                                   n;
  SaffronComponentFillGradient*         gradient;
  
  if ( GetType() != "gradient" ) {
    return NULL;
  }

  
  gradient  = new SaffronComponentFillGradient(GetName(),
                                               GetRotation());

  n = GetStopCount();

  for ( int i = 0; i < n ; i++ ) {
    stop = GetStopByIndex(i);
    newStop = stop->Copy();
    gradient->AddStop(newStop);
  }
  
  return gradient;
}

