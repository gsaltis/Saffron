/*****************************************************************************
 * FILE NAME    : SaffronComponent.cpp
 * DATE         : November 29 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QRandomGenerator64>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronComponent.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : SaffronComponent
 *****************************************************************************/
SaffronComponent::SaffronComponent
() : QWidget()
{
  Initialize();
  SetID();
}

/*****************************************************************************!
 * Function : ~SaffronComponent
 *****************************************************************************/
SaffronComponent::~SaffronComponent
()
{
  if ( name ) {
    delete name;
  }
}

/*****************************************************************************!
 * Function : SetName
 *****************************************************************************/
void
SaffronComponent::SetName
(DataName* InName)
{
  name = InName;
}

/*****************************************************************************!
 * Function : SetName
 *****************************************************************************/
void
SaffronComponent::SetName
(QString InName)
{
  name = new DataName(InName);
}

/*****************************************************************************!
 * Function : SetParent
 *****************************************************************************/
void
SaffronComponent::SetParent
(class SaffronComponent* InParent)
{
  if ( NULL == InParent ) {
    return;
  }
  componentParent = InParent;
}

/*****************************************************************************!
 * Function : SetID
 *****************************************************************************/
void
SaffronComponent::SetID(void)
{
  id = QRandomGenerator64::global()->generate() & std::numeric_limits<qint64>::max();
}

/*****************************************************************************!
 * Function : GetName
 *****************************************************************************/
DataName*
SaffronComponent::GetName(void)
{
  return name;
}

/*****************************************************************************!
 * Function : GetParent
 *****************************************************************************/
SaffronComponent*
SaffronComponent::GetParent
()
{
  return componentParent;
}

/*****************************************************************************!
 * Function : GetIDString
 *****************************************************************************/
QString
SaffronComponent::GetIDString(void)
{
  uint64_t                              idt;
  QString                               idString;
  char                                  s[3];
  
  idt = id;

  for ( int i = 0 ; i < 8; i++ ) {
    uint16_t                            n;

    if ( i > 0 ) {
      idString += QString(":");
    }    
    n = (uint16_t)(idt & 0xFF);
    idt >>= 8;
    sprintf(s, "%02X", n);
    idString = idString + QString(s);
  }
  return idString;
}

/*****************************************************************************!
 * Function : CreateIDConfigFile
 *****************************************************************************/
void
SaffronComponent::CreateIDConfigFile
(QJsonObject& InObject)
{
  QJsonObject                           idObject;
  
  idObject["id"] = GetIDString();
  idObject["name"] = name ? name->ToString() : QString("None");
  InObject["id"] = idObject;
}


/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
SaffronComponent::Initialize(void)
{
  name = NULL;
  componentParent = NULL;
  id = 0;
}

/*****************************************************************************!
 * Function : FromJSON
 *****************************************************************************/
void
SaffronComponent::FromJSON
(QJsonObject& InObject)
{
  QString                               idString;
  SetName(InObject["name"].toString());
  idString = InObject["id"].toString();

  id = IdFromString(idString);
}

/*****************************************************************************!
 * Function : IdFromString
 *****************************************************************************/
uint64_t
SaffronComponent::IdFromString
(QString InString)
{
  bool                                  ok;
  QStringList                           parts = InString.split(":");
  uint64_t                              returnID = 0;
  uint64_t                              n;

  for ( int i = parts.count() - 1; i >= 0; i-- ) {
    QString                             part = parts[i];
    n = part.toLongLong(&ok, 16);
    returnID <<= 8;
    returnID += n;
  }
  return returnID;
}
