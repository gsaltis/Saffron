/*****************************************************************************
 * FILE NAME    : SaffronBaseWindow.h
 * DATE         : November 15 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffronbasewindow_h_
#define _saffronbasewindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QFrame>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ModuleDisplayBaseWindow.h"
#include "FramesDisplayWindow.h"
#include "ProjectDisplayWindow.h"
#include "SaffronToolBarWindow.h"
#include "SaffronToolBarButtonSet.h"
#include "Project.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SAFFRON_BASE_WINDOW_X           200
#define SAFFRON_BASE_WINDOW_Y           200
#define SAFFRON_BASE_WINDOW_WIDTH       200
#define SAFFRON_BASE_WINDOW_HEIGHT      200

/*****************************************************************************!
 * Exported Class : SaffronBaseWindow
 *****************************************************************************/
class SaffronBaseWindow : public QFrame
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronBaseWindow             ();

 //! Destructor
 public :
  ~SaffronBaseWindow            ();

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
  void                          WindowsHide             (void);

 //! Private Data
 private :
  QList<ModuleDisplayBaseWindow*>       moduleWindows;
  FramesDisplayWindow*                  framesWindow;
  ProjectDisplayWindow*                 projectWindow;
  
 //! Public Slots
 public slots :
  void                          SlotProjectCreated      (QString InProjectName);
  void                          SlotProjectOpened       (Project* InProject);
  void                          SlotOpenModule          (Module* InModule);
  void                          SlotModuleClose         (void);
  void                          SlotDataNameChanged     (QString InDataTypeName);
  void                          SlotCloseModuleWindow   (void);
  void                          SlotModuleWindowSplit   (ModuleDisplayWindow* InWindow);
  void                          SlotMemberDataEnter     (MemberData* InMemberData);
  void                          SlotMemberDataLeave     (MemberData* InMemberData);
  void                          SlotModuleWindowClosed  ();

 //! Public Signals
 signals :
  void                          SignalProjectCreated    (QString InProjectName);
  void                          SignalProjectOpened     (Project* InProject);
  void                          SignalMemberDataEnter   (MemberData* InMemberData);
  void                          SignalMemberDataLeave   (MemberData* InMemberData);

 //! Public Actions
 public :

};

#endif /* _saffronbasewindow_h_*/
