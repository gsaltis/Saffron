/*****************************************************************************
 * FILE NAME    : MainDisplayWindow.h
 * DATE         : November 15 2022
 * PROJECT      : Saffron
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _maindisplaywindow_h_
#define _maindisplaywindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainSaffronWindowContainer.h"
#include "MainSaffronToolBar.h"
#include "Project.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : MainDisplayWindow
 *****************************************************************************/
class MainDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainDisplayWindow             ();

 //! Destructor
 public :
  ~MainDisplayWindow            ();

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
  void                          Initialize              ();
  void                          InitializeSubWindows    ();
  void                          CreateSubWindows        ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  void                          CreateConnections       (void);

 //! Private Data
 private :
  MainSaffronWindowContainer*   mainSaffronWindow;
  MainSaffronToolBar*           saffronToolBar;

 //! Public Slots
 public slots :
  void                          SlotProjectCreated      (QString InProjectName);
  void                          SlotProjectOpened       (Project* InProject);
  void                          SlotMemberDataEnter     (MemberData* InMemberData);
  void                          SlotMemberDataLeave     (MemberData* InMemberData);

 //! Public Signals
 signals :
  void                          SignalProjectCreated    (QString InProjectName);
  void                          SignalProjectOpened     (Project* InProject);
  void                          SignalMemberDataEnter   (MemberData* InMemberData);
  void                          SignalMemberDataLeave   (MemberData* InMemberData);

 //! Public Actions
 public :

};

#endif /* _maindisplaywindow_h_*/
