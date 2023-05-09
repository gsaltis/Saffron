/*****************************************************************************
 * FILE NAME    : ProjectDisplayBodyWindow.h
 * DATE         : December 01 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _projectdisplaybodywindow_h_
#define _projectdisplaybodywindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QAction>
#include <QMenu>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "Project.h"
#include "SaffronDisplayWindow.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define PROJECT_DISPLAY_BODY_WINDOW_X   200
#define PROJECT_DISPLAY_BODY_WINDOW_Y   200
#define PROJECT_DISPLAY_BODY_WINDOW_WIDTH 200
#define PROJECT_DISPLAY_BODY_WINDOW_HEIGHT 200

/*****************************************************************************!
 * Exported Class : ProjectDisplayBodyWindow
 *****************************************************************************/
class ProjectDisplayBodyWindow : public SaffronDisplayWindow
{
  Q_OBJECT;

 //! Constructors
 public :
  ProjectDisplayBodyWindow      ();

 //! Destructor
 public :
  ~ProjectDisplayBodyWindow     ();

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
  void                          paintEvent              (QPaintEvent* InEvent);
  void                          mouseMoveEvent          (QMouseEvent* InEvent);
  void                          dragMoveEvent           (QDragMoveEvent* InEvent) override;
  void                          mousePressEvent         (QMouseEvent* InEvent);
  void                          CreateMenu              (void);
  void                          dragEnterEvent          (QDragEnterEvent *event) override;
  void                          dropEvent               (QDropEvent *event) override;
  void                          ModuleCreate            (QString InName);

 //! Private Data
 private :
  QMenu*                                menu;
  QPoint                                mousePressPoint;
  Project*                              project;
  
  //! Public Slots
 public slots :
  void                          SlotNewModule           (void);
  void                          SlotProjectOpened       (Project* InProject);
  void                          SlotOpenModule          (Module* InModule);
  
 //! Public Signals
 signals :
  void                          SignalOpenModule        (Module* InModule);

 //! Public Actions
 public :
  QAction*                      ActionNewModule;

};

#endif /* _projectdisplaybodywindow_h_*/
