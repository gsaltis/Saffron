/*****************************************************************************
 * FILE NAME    : SaffronToolBarWindow.h
 * DATE         : November 24 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffrontoolbarwindow_h_
#define _saffrontoolbarwindow_h_

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
#include "SaffronToolBarButtonSet.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SAFFRON_TOOL_BAR_WINDOW_X       200
#define SAFFRON_TOOL_BAR_WINDOW_Y       200
#define SAFFRON_TOOL_BAR_WINDOW_WIDTH   200
#define SAFFRON_TOOL_BAR_WINDOW_HEIGHT  25

/*****************************************************************************!
 * Exported Class : SaffronToolBarWindow
 *****************************************************************************/
class SaffronToolBarWindow : public QFrame
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronToolBarWindow          ();

 //! Destructor
 public :
  ~SaffronToolBarWindow         ();

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
  void                          paintEvent              (QPaintEvent* InEvent);

 //! Private Data
 private :
  QHash<QString, SaffronToolBarButtonSet*>      buttonSets;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffrontoolbarwindow_h_*/
