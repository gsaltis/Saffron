/*****************************************************************************
 * FILE NAME    : ProjectOpenDialogFrame.h
 * DATE         : December 05 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _projectopendialogframe_h_
#define _projectopendialogframe_h_

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
#include "ProjectInfoList.h"
#include "ProjectOpenDialogElement.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define PROJECT_OPEN_DIALOG_FRAME_X             10
#define PROJECT_OPEN_DIALOG_FRAME_Y             10
#define PROJECT_OPEN_DIALOG_FRAME_WIDTH         200
#define PROJECT_OPEN_DIALOG_FRAME_HEIGHT        200

/*****************************************************************************!
 * Exported Class : ProjectOpenDialogFrame
 *****************************************************************************/
class ProjectOpenDialogFrame : public QFrame
{
  Q_OBJECT;

 //! Constructors
 public :
  ProjectOpenDialogFrame        (ProjectInfoList* InInfoList);

 //! Destructor
 public :
  ~ProjectOpenDialogFrame       ();

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
  void                          paintEvent              (QPaintEvent* InEvent);

 //! Private Data
 private :
  ProjectInfoList*              projectInfoList;
  QList<ProjectOpenDialogElement*> Entries;

 //! Public Slots
 public slots :
  void                          SlotElementSelected     (QString InInfoName);

 //! Public Signals
 signals :
  void                          SignalSelected          (QString InInfoName);

 //! Public Actions
 public :

};

#endif /* _projectopendialogframe_h_*/
