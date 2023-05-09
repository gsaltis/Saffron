/*****************************************************************************
 * FILE NAME    : MemberMethodFrameStack.h
 * DATE         : November 21 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _membermethodframestack_h_
#define _membermethodframestack_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MemberMethodFrame.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : MemberMethodFrameStack
 *****************************************************************************/
class MemberMethodFrameStack : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MemberMethodFrameStack        ();

 //! Destructor
 public :
  ~MemberMethodFrameStack       ();

 //! Public Methods
 public :
  int                           GetFrameCount           (void);

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
  QList<MemberMethodFrame*>             frames;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _membermethodframestack_h_*/
