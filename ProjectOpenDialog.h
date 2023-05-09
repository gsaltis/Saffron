/*****************************************************************************
 * FILE NAME    : ProjectOpenDialog.h
 * DATE         : December 02 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Vertiv Company
 *****************************************************************************/
#ifndef _projectopendialog_h_
#define _projectopendialog_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QPushButton>
#include <QAction>
#include <QTableWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ProjectInfoList.h"
#include "ProjectOpenDialogFrame.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define PROJECT_OPEN_DIALOG_WIDTH               600
#define PROJECT_OPEN_DIALOG_HEIGHT              400

/*****************************************************************************!
 * Exported Class : ProjectOpenDialog
 *****************************************************************************/
class ProjectOpenDialog : public QDialog
{
  Q_OBJECT;

 //! Constructors
 public :
  ProjectOpenDialog       ();

 //! Destructor
 public :
  ~ProjectOpenDialog      ();

 //! Public Methods
 public :
  QString                       GetInfoName             (void);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              (void);
  void                          CreateSubWindows        (void);
  void                          CreateConnections       ();
  void                          resizeEvent             (QResizeEvent* InEvent);

 //! Private Data
 private :
  QPushButton*                  OKButton;
  QPushButton*                  CancelButton;
  ProjectOpenDialogFrame*       InfoTable;
  ProjectInfoList               projects;
  QString                       infoName;
  
 //! Public Slots
 public slots :
  void                          SlotCancelButtonPushed  (void);
  void                          SlotSelected            (QString InInfoName);

 //! Public Signals
 signals :

 //! Public Actions
 public :
  QAction*                      ActionOKButtonPushed;
  QAction*                      ActionCancelButtonPushed;

};

#endif /* _projectopendialog_h_*/
