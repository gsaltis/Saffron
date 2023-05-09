/*****************************************************************************
 * FILE NAME    : SaffronToolBarButtonSet.h
 * DATE         : November 25 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffrontoolbarbuttonset_h_
#define _saffrontoolbarbuttonset_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronToolBarButtonWindow.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : SaffronToolBarButtonSet
 *****************************************************************************/
class SaffronToolBarButtonSet : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronToolBarButtonSet       ();

 //! Destructor
 public :
  ~SaffronToolBarButtonSet      ();

 //! Public Methods
 public :
  void                          AddButton               (SaffronToolBarButtonWindow* InButton);

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
  QList<SaffronToolBarButtonWindow*>    buttons;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffrontoolbarbuttonset_h_*/
