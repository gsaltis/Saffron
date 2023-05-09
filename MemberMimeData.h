/*****************************************************************************
 * FILE NAME    : MemberMimeData.h
 * DATE         : December 31 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _membermimedata_h_
#define _membermimedata_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QMimeData>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MEMBER_MIME_DATA_X              200
#define MEMBER_MIME_DATA_Y              200
#define MEMBER_MIME_DATA_WIDTH          200
#define MEMBER_MIME_DATA_HEIGHT         200

/*****************************************************************************!
 * Exported Class : MemberMimeData
 *****************************************************************************/
class MemberMimeData : public QMimeData
{
  Q_OBJECT;

 //! Constructors
 public :
  MemberMimeData
  (class MemberDataDisplayWidget* InWidget, class MemberData* InMemberData);

 //! Destructor
 public :
  ~MemberMimeData
  ();

 //! Public Methods
 public :
  class MemberDataDisplayWidget*
  GetWidget
  ();
  
  class MemberData*
  GetMemberData
  (void);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void
  initialize
  ();

 //! Private Data
 private :
  class MemberDataDisplayWidget*        widget;
  class MemberData*                     memberData;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _membermimedata_h_*/
