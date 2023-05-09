/*****************************************************************************
 * FILE NAME    : ModuleSelectWindow.h
 * DATE         : November 21 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _moduleselectwindow_h_
#define _moduleselectwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ModuleSelectElement.h"
#include "Project.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_SELECT_WINDOW_X          200
#define MODULE_SELECT_WINDOW_Y          200
#define MODULE_SELECT_WINDOW_WIDTH      200
#define MODULE_SELECT_WINDOW_HEIGHT     200

/*****************************************************************************!
 * Exported Class : ModuleSelectWindow
 *****************************************************************************/
class ModuleSelectWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ModuleSelectWindow            ();

 //! Destructor
 public :
  ~ModuleSelectWindow           ();

 //! Public Methods
 public :
  void                          AddElement              (ModuleSelectElement* InElement);
  int                           FindLastElementY        (void);

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
  QList<ModuleSelectElement*>   elements;
  
 //! Public Slots
 public slots :
  void                          SlotProjectOpened       (Project* InProject);

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _moduleselectwindow_h_*/
