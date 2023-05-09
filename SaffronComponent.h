/*****************************************************************************
 * FILE NAME    : SaffronComponent.h
 * DATE         : November 29 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffroncomponent_h_
#define _saffroncomponent_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "DataName.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : SaffronComponent
 *****************************************************************************/
class SaffronComponent : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronComponent              ();

 //! Destructor
 public :
  ~SaffronComponent             ();

 //! Public Methods
 public :
  void                          SetName                 (DataName* InName);
  void                          SetName                 (QString InName);
  void                          SetParent               (class SaffronComponent* InParent);
  virtual QString               GetTypeName             (void) = 0;
  DataName*                     GetName                 (void);
  QString                       GetIDString             (void);
  void                          CreateIDConfigFile      (QJsonObject& InObject);
  class SaffronComponent*       GetParent               ();
  void                          FromJSON                (QJsonObject& InObject);
  uint64_t                      IdFromString            (QString InString);
  
 //! Public Data
 public :
  class SaffronComponent*       componentParent;

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          SetID                   (void);
  void                          Initialize              (void);

 //! Private Data
 private :
  DataName*                     name;
  uint64_t                      id;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffroncomponent_h_*/
