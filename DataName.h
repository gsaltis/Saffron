/*****************************************************************************
 * FILE NAME    : DataName.h
 * DATE         : November 24 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _dataname_h_
#define _dataname_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : DataName
 *****************************************************************************/
class DataName : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  DataName                      ();
  DataName                      (QString InName);
  
 //! Destructor
 public :
  ~DataName                     ();

 //! Public Methods
 public :
  QString                       ToString                (void);
  void                          FromString              (QString InName);
  bool                          IsAnonymous             (void);

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
  QString                               name;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _dataname_h_*/
