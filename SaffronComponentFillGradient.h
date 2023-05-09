/*****************************************************************************
 * FILE NAME    : SaffronComponentFillGradient.h
 * DATE         : December 17 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffroncomponentfillgradient_h_
#define _saffroncomponentfillgradient_h_

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
#include "SaffronComponentFillGradientStop.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : SaffronComponentFillGradient
 *****************************************************************************/
class SaffronComponentFillGradient : public SaffronComponentFill
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronComponentFillGradient          (QString InName, int InPosition = 0);
  SaffronComponentFillGradient          ();
  
 //! Destructor
 public :
  ~SaffronComponentFillGradient         ();

 //! Public Methods
 public :
  void                          AddStop                 (SaffronComponentFillGradientStop* InStop);
  virtual QBrush                GetBrush                (void);
  virtual QString               GetType                 (void);
  virtual QString               GetSVGString            (void);
  virtual QString               GetSVGString            (QString InFillName);
  virtual void                  CreateJSON              (QJsonObject& InObject);
  virtual void                  FromJSON                (QJsonObject& InObject);
  virtual class SaffronComponentFill*  Copy             ();
  int                           GetStopCount            ();
  SaffronComponentFillGradientStop*     GetStopByIndex  (int InIndex);
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :

 //! Private Data
 private :
  QList<SaffronComponentFillGradientStop*>      stops;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffroncomponentfillgradient_h_*/
