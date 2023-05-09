/*****************************************************************************
 * FILE NAME    : MainWindow.h
 * DATE         : November 15 2022
 * PROJECT      : Saffron
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _mainwindow_h_
#define _mainwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QMainWindow>
#include <QAction>
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainDisplayWindow.h"
#include "SystemConfig.h"
#include "Project.h"
#include "SaffronStatusBar.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_WINDOW_WIDTH                       640
#define MAIN_WINDOW_HEIGHT                      480
#define MAIN_WINDOW_Y                           100
#define MAIN_WINDOW_X                           100

/*****************************************************************************!
 * Exported Class : MainWindow
 *****************************************************************************/
class MainWindow : public QMainWindow
{
  Q_OBJECT;

 //! Constructors
 public :
  MainWindow                    ();
  MainWindow                    (QWidget* );

 //! Destructor
 public :
  ~MainWindow                   ();

 //! Public Methods
 public :
  void                          OpenProject             (QString InProjectName);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          Initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  void                          CreateActions           ();
  void                          CreateMenus             ();
  void                          CreateConnections       (void);
  void                          SetStatusLabelTimed     (QString InMessage);

 //! Private Data
 private :
  QMenuBar*                     menubar;
  QMenu*                        fileMenu;
  QStatusBar*                   statusbar;
  MainDisplayWindow*            displayWindow;
  QLabel*                       StatusLabel;
  SaffronStatusBar*             messageBar;

 //! Public Slots
 public slots :
  void                          SlotExit                (void);
  void                          SlotCreateNewProject    (void);
  void                          SlotOpenProject         (void);
  void                          SlotMemberDataLeave     (MemberData* InMemberData);
  void                          SlotMemberDataEnter     (MemberData* InMemberData);
  void                          SlotClearStatusMessage  (void);

 //! Public Signals
 signals :
  void                          SignalProjectCreated    (QString InProjectName);
  void                          SignalProjectOpened     (Project* InProject);

 //! Public Actions
 public :
  QAction*                      ActionExit;
  QAction*                      ActionCreateNewProject;
  QAction*                      ActionOpenProject;

};

#endif /* _mainwindow_h_*/
