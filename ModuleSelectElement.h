/*****************************************************************************
 * FILE NAME    : ModuleSelectElement.h
 * DATE         : December 09 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Vertiv Company
 *****************************************************************************/
#ifndef _moduleselectelement_h_
#define _moduleselectelement_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QFrame>
#include <QWidget>
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_SELECT_ELEMENT_X         200
#define MODULE_SELECT_ELEMENT_Y         200
#define MODULE_SELECT_ELEMENT_WIDTH     200
#define MODULE_SELECT_ELEMENT_HEIGHT    22

/*****************************************************************************!
 * Exported Class : ModuleSelectElement
 *****************************************************************************/
class ModuleSelectElement : public QFrame
{
  Q_OBJECT;

 //! Constructors
 public :
  ModuleSelectElement           (QString InName, QString InType, QString InLabel);

 //! Destructor
 public :
  ~ModuleSelectElement          ();

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
  void
  initialize
  ();

  void
  CreateSubWindows
  ();

  void
  InitializeSubWindows
  ();

  void
  resizeEvent
  (QResizeEvent* InEvent);

  void
  paintEvent
  (QPaintEvent* InEvent);

  void
  mousePressEvent
  (QMouseEvent *event) override;
  
 //! Private Data
 private :
  QString                               name;
  QString                               type;
  QString                               label;
  QLabel*                               nameLabel;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _moduleselectelement_h_*/
