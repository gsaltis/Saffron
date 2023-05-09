/*****************************************************************************
 * FILE NAME    : SaffronComponentResizeWindow.h
 * DATE         : February 26 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffroncomponentresizewindow_h_
#define _saffroncomponentresizewindow_h_

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
#include "SaffronComponentResizeHandle.h"
#include "SaffronDisplayWindow.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SAFFRON_COMPONENT_RESIZE_WINDOW_X 200
#define SAFFRON_COMPONENT_RESIZE_WINDOW_Y 200
#define SAFFRON_COMPONENT_RESIZE_WINDOW_WIDTH 200
#define SAFFRON_COMPONENT_RESIZE_WINDOW_HEIGHT 200

/*****************************************************************************!
 * Exported Class : SaffronComponentResizeWindow
 *****************************************************************************/
class SaffronComponentResizeWindow : public SaffronDisplayWindow
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronComponentResizeWindow  ();

 //! Destructor
 public :
  ~SaffronComponentResizeWindow ();

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
  void                          keyPressEvent           (QKeyEvent* InEvent);
  void                          dragEnterEvent          (QDragEnterEvent *event) override;
  void                          dropEvent               (QDropEvent *event) override;
  void                          dragMoveEvent           (QDragMoveEvent* InEvent) override;
  void                          mousePressEvent         (QMouseEvent* InEvent);
  void                          mouseMoveEvent          (QMouseEvent* InEvent);
  void                          AbortResize             (void);
  void                          FinishResize            (void);

 //! Private Data
 private :
  SaffronComponentResizeHandle* resizeHandle;
  QFrame*                       resizeFrame;
  MemberData*                   memberData;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffroncomponentresizewindow_h_*/
