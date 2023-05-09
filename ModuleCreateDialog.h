/*****************************************************************************
 * FILE NAME    : ModuleCreateDialog.h
 * DATE         : December 09 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _modulecreatedialog_h_
#define _modulecreatedialog_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QPushButton>
#include <QAction>
#include <QLineEdit>
#include <QTextEdit>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_CREATE_DIALOG_WIDTH              400
#define MODULE_CREATE_DIALOG_HEIGHT             200

/*****************************************************************************!
 * Exported Class : ModuleCreateDialog
 *****************************************************************************/
class ModuleCreateDialog : public QDialog
{
  Q_OBJECT;

 //! Constructors
 public :
  ModuleCreateDialog            (QString InName, QString InDescription);

 //! Destructor
 public :
  ~ModuleCreateDialog           ();

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
  QString                               name;
  QString                               description;

  QPushButton*                  OKButton;
  QPushButton*                  CancelButton;
  QLineEdit*                    nameEdit;
  QTextEdit*                    descriptionEdit;
  
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

#endif /* _modulecreatedialog_h_*/
