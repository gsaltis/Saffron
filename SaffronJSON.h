/*****************************************************************************
 * FILE NAME    : SaffronJSON.h
 * DATE         : December 21 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Vertiv Company
 *****************************************************************************/
#ifndef _saffronjson_h_
#define _saffronjson_h_

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
 * Exported Class : SaffronJSON
 *****************************************************************************/
class SaffronJSON : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronJSON                   ();

 //! Destructor
 public :
  ~SaffronJSON                  ();

 //! Public Methods
 public :
  static QPoint
  ReadPoint
  (QJsonObject& InObject, QString InName);

  static QSize
  ReadSize
  (QJsonObject& InObject, QString InName);

  static QColor
  ReadColor
  (QJsonObject& InObject, QString InName);

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

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffronjson_h_*/
