/*****************************************************************************
 * FILE NAME    : MainSaffronWindow.h
 * DATE         : November 15 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _mainsaffronwindow_h_
#define _mainsaffronwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QSplitter>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronBaseWindow.h"
#include "SaffronSelectWindow.h"
#include "Project.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_SAFFRON_WINDOW_X           200
#define MAIN_SAFFRON_WINDOW_Y           200
#define MAIN_SAFFRON_WINDOW_WIDTH       200
#define MAIN_SAFFRON_WINDOW_HEIGHT      200

/*****************************************************************************!
 * Exported Class : MainSaffronWindow
 *****************************************************************************/
class MainSaffronWindow : public QSplitter
{
  Q_OBJECT;

 //! Constructors
 public :
  MainSaffronWindow             ();

 //! Destructor
 public :
  ~MainSaffronWindow            ();

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
  void                          CreateConnections       (void);

 //! Private Data
 private :
  SaffronBaseWindow*            saffronBaseWindow;
  SaffronSelectWindow*          saffronSelectWindow;

 //! Public Slots
 public slots :
  void                          SlotProjectCreated      (QString InProjectName);
  void                          SlotProjectOpened       (Project* InProject);
  void                          SlotMemberDataLeave     (MemberData* InMemberData);
  void                          SlotMemberDataEnter     (MemberData* InMemberData);

 //! Public Signals
 signals :
  void                          SignalProjectCreated    (QString InProjectName);
  void                          SignalProjectOpened     (Project* InProject);
  void                          SignalMemberDataLeave   (MemberData* InMemberData);
  void                          SignalMemberDataEnter   (MemberData* InMemberData);

 //! Public Actions
 public :

};

#endif /* _mainsaffronwindow_h_*/
