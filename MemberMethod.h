/*****************************************************************************
 * FILE NAME    : MemberMethod.h
 * DATE         : November 18 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Vertiv Company
 *****************************************************************************/
#ifndef _membermethod_h_
#define _membermethod_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QSvgWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MemberMethodParameter.h"
#include "MemberMethodFrame.h"
#include "MemberMethodFrameStack.h"
#include "DataName.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : MemberMethod
 *****************************************************************************/
class MemberMethod : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MemberMethod                  ();

 //! Destructor
 public :
  ~MemberMethod                 ();

 //! Public Methods
 public :
  QString                       GetName                 (void);
  int                           GetFrameCount           (void);
  int                           GetParameterCount       (void);
  MemberMethodFrame*            GetMethodFrame          (int InIndex);
  MemberMethodParameter*        GetMethodParameter      (int InIndex);
  QSvgWidget*                   GetModuleView           (void);

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
  DataName*                             name;
  QList<MemberMethodParameter*>         parameters;
  MemberMethodFrameStack*               frames;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _membermethod_h_*/
