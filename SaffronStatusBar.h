/*****************************************************************************
 * FILE NAME    : SaffronStatusBar.h
 * DATE         : December 27 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffronstatusbar_h_
#define _saffronstatusbar_h_

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
#define SAFFRON_STATUS_BAR_X            200
#define SAFFRON_STATUS_BAR_Y            200
#define SAFFRON_STATUS_BAR_WIDTH        200
#define SAFFRON_STATUS_BAR_HEIGHT       20

/*****************************************************************************!
 * Exported Class : SaffronStatusBar
 *****************************************************************************/
class SaffronStatusBar : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronStatusBar              ();

 //! Destructor
 public :
  ~SaffronStatusBar             ();

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

#endif /* _saffronstatusbar_h_*/
