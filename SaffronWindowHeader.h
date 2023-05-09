/*****************************************************************************
 * FILE NAME    : SaffronWindowHeader.h
 * DATE         : December 01 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffronwindowheader_h_
#define _saffronwindowheader_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SAFFRON_WINDOW_HEADER_X         200
#define SAFFRON_WINDOW_HEADER_Y         200
#define SAFFRON_WINDOW_HEADER_WIDTH     200
#define SAFFRON_WINDOW_HEADER_HEIGHT    30

/*****************************************************************************!
 * Exported Class : SaffronWindowHeader
 *****************************************************************************/
class SaffronWindowHeader : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronWindowHeader           ();

 //! Destructor
 public :
  ~SaffronWindowHeader          ();

 //! Public Methods
 public :
  void                          SetTitle                (QString InTitle);

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
  void                          paintEvent              (QPaintEvent* InEvent);

 //! Private Data
 private :
  QLabel*                       titleLabel;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffronwindowheader_h_*/
