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

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

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

 //! Private Data
 private :
  QPushButton*                  OKButton;
  QPushButton*                  CancelButton;

 //! Public Slots
 public slots :
  void                          SlotOKButtonPushed      (void);
  void                          SlotCancelButtonPushed  (void);

 //! Public Signals
 signals :

 //! Public Actions
 public :
  QAction*                      ActionOKButtonPushed;
  QAction*                      ActionCancelButtonPushed;

};

#endif /* _projectopendialog_h_*/
