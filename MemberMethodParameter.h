/*****************************************************************************
 * FILE NAME    : MemberMethodParameter.h
 * DATE         : November 18 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Vertiv Company
 *****************************************************************************/
#ifndef _membermethodparameter_h_
#define _membermethodparameter_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "DataType.h"
#include "DataName.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : MemberMethodParameter
 *****************************************************************************/
class MemberMethodParameter : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MemberMethodParameter         ();

 //! Destructor
 public :
  ~MemberMethodParameter        ();

 //! Public Methods
 public :
  QString                       GetName                 (void);
  DataType*                     GetType                 (void);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          Initialize              (void);

 //! Private Data
 private :
  DataName*                             name;
  DataType*                             type;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _membermethodparameter_h_*/
