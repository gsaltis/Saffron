/*****************************************************************************
 * FILE NAME    : ModuleDisplayBaseWindow.h
 * DATE         : January 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _moduledisplaybasewindow_h_
#define _moduledisplaybasewindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ModuleDisplayWindow.h"
#include "SaffronWindowHeader.h"
#include "ModuleControlBarWindow.h"
#include "SaffronComponentResizeWindow.h"
#include "Project.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_DISPLAY_BASE_WINDOW_X    200
#define MODULE_DISPLAY_BASE_WINDOW_Y    200
#define MODULE_DISPLAY_BASE_WINDOW_WIDTH 200
#define MODULE_DISPLAY_BASE_WINDOW_HEIGHT 200

/*****************************************************************************!
 * Exported Class : ModuleDisplayBaseWindow
 *****************************************************************************/
class ModuleDisplayBaseWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ModuleDisplayBaseWindow       ();

 //! Destructor
 public :
  ~ModuleDisplayBaseWindow      ();

 //! Public Methods
 public :
  void                          SetModule               (class Module* InModule);
  void                          CreateConnections       (void);
  ModuleDisplayWindow*          GetModuleWindow         (void);

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
  ModuleDisplayWindow*          moduleDisplayWindow;
  SaffronWindowHeader*          header;
  class Module*                 module;
  ModuleControlBarWindow*       controlBar;
  SaffronComponentResizeWindow* moduleMemberDataResizeWindow;
  Project*                      project;
  
 //! Public Slots
 public slots :
  void                          SlotDataTypeChanged     (QString InDataTypeName);
  void                          SlotCloseModuleDisplayWindow (void);
  void                          SlotModuleWindowSplit   (ModuleDisplayWindow* InModuleWindow);
  void                          SlotMemberDataResize    (MemberData* InMemberData);
  void                          SlotMemberDataLeave     (MemberData* InMemberData);
  void                          SlotMemberDataEnter     (MemberData* InMemberData);
  void                          SlotProjectOpened       (Project* InProject);
  void                          SlotUserDataTypeChanged (QString InUserDataTypeName);
  
 //! Public Signals
 signals :
  void                          SignalDataTypeChanged   (QString InDataTypeName);
  void                          SignalCloseWindow       (void);
  void                          SignalModuleWindowSplit (ModuleDisplayWindow* InModuleWindow);
  void                          SignalMemberDataLeave   (MemberData* InMemberData);
  void                          SignalMemberDataEnter   (MemberData* InMemberData);
  void                          SignalProjectOpened     (Project* InProject);

 //! Public Actions
 public :

};

#endif /* _moduledisplaybasewindow_h_*/
