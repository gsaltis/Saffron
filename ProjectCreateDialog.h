/*****************************************************************************
 * FILE NAME    : ProjectCreateDialog.h
 * DATE         : November 26 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _projectcreatedialog_h_
#define _projectcreatedialog_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QPushButton>
#include <QAction>
#include <QLineEdit>
#include <QString>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : ProjectCreateDialog
 *****************************************************************************/
class ProjectCreateDialog : public QDialog
{
  Q_OBJECT;

 //! Constructors
 public :
  ProjectCreateDialog           (QString InProjectName);

 //! Destructor
 public :
  ~ProjectCreateDialog          ();

 //! Public Methods
 public :
  QString                       GetProjectName          (void);

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
  void                          resizeEvent             (QResizeEvent* InEvent);

 //! Private Data
 private :
  QPushButton*                  OKButton;
  QPushButton*                  CancelButton;
  QLineEdit*                    ProjectNameEdit;
  QString                       projectName;

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

#endif /* _projectcreatedialog_h_*/

