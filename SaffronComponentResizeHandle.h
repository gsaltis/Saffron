/*****************************************************************************
 * FILE NAME    : SaffronComponentResizeHandle.h
 * DATE         : December 23 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffroncomponentresizehandle_h_
#define _saffroncomponentresizehandle_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QFrame>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MemberData.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SAFFRON_COMPONENT_RESIZE_HANDLE_X 200
#define SAFFRON_COMPONENT_RESIZE_HANDLE_Y 200
#define SAFFRON_COMPONENT_RESIZE_HANDLE_WIDTH 12
#define SAFFRON_COMPONENT_RESIZE_HANDLE_HEIGHT 12c

/*****************************************************************************!
 * Exported Class : SaffronComponentResizeHandle
 *****************************************************************************/
class SaffronComponentResizeHandle : public QFrame
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronComponentResizeHandle  (QWidget* InParent, MemberData* InMemberData);

 //! Destructor
 public :
  ~SaffronComponentResizeHandle ();

 //! Public Methods
 public :
  void                          SetMemberData           (MemberData* InMemberData);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  void                          mousePressEvent         (QMouseEvent* InEvent);
  
 //! Private Data
 private :
  MemberData*                   memberData;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffroncomponentresizehandle_h_*/
