/*****************************************************************************
 * FILE NAME    : MainSaffronToolBar.h
 * DATE         : November 15 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _mainsaffrontoolbar_h_
#define _mainsaffrontoolbar_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QToolBar>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_SAFFRON_TOOL_BAR_X         10
#define MAIN_SAFFRON_TOOL_BAR_Y         10
#define MAIN_SAFFRON_TOOL_BAR_WIDTH     200
#define MAIN_SAFFRON_TOOL_BAR_HEIGHT    25

/*****************************************************************************!
 * Exported Class : MainSaffronToolBar
 *****************************************************************************/
class MainSaffronToolBar : public QToolBar
{
  Q_OBJECT;

 //! Constructors
 public :
  MainSaffronToolBar            ();

 //! Destructor
 public :
  ~MainSaffronToolBar           ();

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

#endif /* _mainsaffrontoolbar_h_*/
