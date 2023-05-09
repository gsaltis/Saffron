/*****************************************************************************
 * FILE NAME    : MainSaffronWindowContainer.h
 * DATE         : November 15 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _mainsaffronwindowcontainer_h_
#define _mainsaffronwindowcontainer_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainSaffronWindow.h"
#include "Project.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_SAFFRON_WINDOW_CONTAINER_X 200
#define MAIN_SAFFRON_WINDOW_CONTAINER_Y 200
#define MAIN_SAFFRON_WINDOW_CONTAINER_WIDTH 200
#define MAIN_SAFFRON_WINDOW_CONTAINER_HEIGHT 200

/*****************************************************************************!
 * Exported Class : MainSaffronWindowContainer
 *****************************************************************************/
class MainSaffronWindowContainer : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainSaffronWindowContainer    ();

 //! Destructor
 public :
  ~MainSaffronWindowContainer   ();

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
  MainSaffronWindow*            mainSaffronWindow;

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

#endif /* _mainsaffronwindowcontainer_h_*/
