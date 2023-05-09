/*****************************************************************************
 * FILE NAME    : SaffronFrameWindow.h
 * DATE         : November 16 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffronframewindow_h_
#define _saffronframewindow_h_

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
#define SAFFRON_FRAME_WINDOW_X          200
#define SAFFRON_FRAME_WINDOW_Y          200
#define SAFFRON_FRAME_WINDOW_WIDTH      200
#define SAFFRON_FRAME_WINDOW_HEIGHT     200

/*****************************************************************************!
 * Exported Class : SaffronFrameWindow
 *****************************************************************************/
class SaffronFrameWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronFrameWindow            ();

 //! Destructor
 public :
  ~SaffronFrameWindow           ();

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

#endif /* _saffronframewindow_h_*/
