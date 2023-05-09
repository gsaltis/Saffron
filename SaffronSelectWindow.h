/*****************************************************************************
 * FILE NAME    : SaffronSelectWindow.h
 * DATE         : November 15 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffronselectwindow_h_
#define _saffronselectwindow_h_

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
#include "ModuleSelectWindow.h"
#include "SaffronToolBarWindow.h"
#include "Project.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SAFFRON_SELECT_WINDOW_X         200
#define SAFFRON_SELECT_WINDOW_Y         200
#define SAFFRON_SELECT_WINDOW_WIDTH     200
#define SAFFRON_SELECT_WINDOW_HEIGHT    200

/*****************************************************************************!
 * Exported Class : SaffronSelectWindow
 *****************************************************************************/
class SaffronSelectWindow : public QFrame
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronSelectWindow           ();

 //! Destructor
 public :
  ~SaffronSelectWindow          ();

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
  void                          CreateConnections       (void);

 //! Private Data
 private :
  ModuleSelectWindow*           moduleSelect;
  SaffronToolBarWindow*         toolbar;

 //! Public Slots
 public slots :
  void                          SlotProjectOpened       (Project* InProject);

 //! Public Signals
 signals :
  void                          SignalProjectOpened     (Project* InProjectx);

 //! Public Actions
 public :

};

#endif /* _saffronselectwindow_h_*/
