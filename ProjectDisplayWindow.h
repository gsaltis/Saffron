/*****************************************************************************
 * FILE NAME    : ProjectDisplayWindow.h
 * DATE         : November 24 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _projectdisplaywindow_h_
#define _projectdisplaywindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "Project.h"
#include "SaffronWindowHeader.h"
#include "ProjectDisplayBodyWindow.h"
#include "Module.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define PROJECT_DISPLAY_WINDOW_X        200
#define PROJECT_DISPLAY_WINDOW_Y        200
#define PROJECT_DISPLAY_WINDOW_WIDTH    200
#define PROJECT_DISPLAY_WINDOW_HEIGHT   200

/*****************************************************************************!
 * Exported Class : ProjectDisplayWindow
 *****************************************************************************/
class ProjectDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ProjectDisplayWindow          ();

 //! Destructor
 public :
  ~ProjectDisplayWindow         ();

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
  void                          CreateConnections       ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);

 //! Private Data
 private :
  Project*                      project;
  SaffronWindowHeader*          windowHeader;
  ProjectDisplayBodyWindow*     projectWindow;

 //! Public Slots
 public slots :
  void                          SlotProjectCreated      (QString InProjectName);
  void                          SlotProjectOpened       (Project* InProject);
  void                          SlotOpenModule          (Module* InModule);

 //! Public Signals
 signals :
  void                          SignalProjectOpened     (Project* InProject);
  void                          SignalOpenModule        (Module* InModule);
  
 //! Public Actions
 public :

};

#endif /* _projectdisplaywindow_h_*/
