/*****************************************************************************
 * FILE NAME    : MemberDataResizeMimeData.h
 * DATE         : December 31 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _memberdataresizemimedata_h_
#define _memberdataresizemimedata_h_

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

/*****************************************************************************!
 * Exported Class : MemberDataResizeMimeData
 *****************************************************************************/
class MemberDataResizeMimeData : public QMimeData
{
  Q_OBJECT;

 //! Constructors
 public :
  MemberDataResizeMimeData
  (class SaffronComponentResizeHandle* InHandle, class MemberData* InMemberData);

 //! Destructor
 public :
  ~MemberDataResizeMimeData
  ();

 //! Public Methods
 public :
  class SaffronComponentResizeHandle*
  GetResizeHandle
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
  class SaffronComponentResizeHandle*   resizeHandle;
  class MemberData*                     memberData;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _memberdataresizemimedata_h_*/
