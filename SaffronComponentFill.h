/*****************************************************************************
 * FILE NAME    : SaffronComponentFill.h
 * DATE         : December 17 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffroncomponentfill_h_
#define _saffroncomponentfill_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QJsonDocument>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : SaffronComponentFill
 *****************************************************************************/
class SaffronComponentFill : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronComponentFill          (QString InName, int InRotation = 0); 

 //! Destructor
 public :
  ~SaffronComponentFill         ();

 //! Public Methods
 public :
  virtual QBrush                GetBrush                (void) = 0;
  virtual QString               GetType                 (void) = 0;
  virtual QString               GetSVGString            (void) = 0;
  virtual QString               GetSVGString            (QString InFillName) = 0;
  void                          SetRotation             (int InRotation);
  void                          SetName                 (QString InName);
  QString                       GetName                 (void);
  int                           GetRotation             (void);
  virtual void                  CreateJSON              (QJsonObject& InObject) = 0;
  virtual void                  FromJSON                (QJsonObject& InObject) = 0;
  virtual class SaffronComponentFill*
  Copy                    () = 0;
  
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
  int                           rotation;
  QString                       name;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffroncomponentfill_h_*/
