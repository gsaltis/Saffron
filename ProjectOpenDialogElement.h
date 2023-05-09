/*****************************************************************************
 * FILE NAME    : ProjectOpenDialogElement.h
 * DATE         : December 05 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _projectopendialogelement_h_
#define _projectopendialogelement_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QFrame>
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ProjectInfo.h"
#include "SelectionLabel.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define PROJECT_OPEN_DIALOG_ELEMENT_X           1
#define PROJECT_OPEN_DIALOG_ELEMENT_Y           1
#define PROJECT_OPEN_DIALOG_ELEMENT_WIDTH       200
#define PROJECT_OPEN_DIALOG_ELEMENT_HEIGHT      20

/*****************************************************************************!
 * Exported Class : ProjectOpenDialogElement
 *****************************************************************************/
class ProjectOpenDialogElement : public QFrame
{
  Q_OBJECT;

 //! Constructors
 public :
  ProjectOpenDialogElement      (ProjectInfo* InInfo, int InIndex);

 //! Destructor
 public :
  ~ProjectOpenDialogElement     ();

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

 //! Private Data
 private :
  ProjectInfo*                  info;
  int                           index;
  SelectionLabel*               dateTimeLabel;
  QBrush                        currentBrush;
  
 //! Public Slots
 public slots :
  void                          SlotHoverOff            (void);
  void                          SlotHoverOn             (void);
  void                          SlotSelected            (void);

 //! Public Signals
 signals :
  void                          SignalHoverOff          (void);
  void                          SignalHoverOn           (void);
  void                          SignalSelected          (QString InName);

 //! Public Actions
 public :

};

#endif /* _projectopendialogelement_h_*/
