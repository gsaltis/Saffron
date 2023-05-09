/*****************************************************************************
 * FILE NAME    : FramesDisplayWindow.h
 * DATE         : November 21 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _framesdisplaywindow_h_
#define _framesdisplaywindow_h_

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
#define FRAMES_DISPLAY_WINDOW_X         200
#define FRAMES_DISPLAY_WINDOW_Y         200
#define FRAMES_DISPLAY_WINDOW_WIDTH     200
#define FRAMES_DISPLAY_WINDOW_HEIGHT    200

/*****************************************************************************!
 * Exported Class : FramesDisplayWindow
 *****************************************************************************/
class FramesDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  FramesDisplayWindow           ();

 //! Destructor
 public :
  ~FramesDisplayWindow          ();

 //! Public Methods
 public :

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

 //! Private Data
 private :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _framesdisplaywindow_h_*/
