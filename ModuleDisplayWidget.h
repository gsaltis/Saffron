/*****************************************************************************
 * FILE NAME    : ModuleDisplayWidget.h
 * DATE         : December 13 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Vertiv Company
 *****************************************************************************/
#ifndef _moduledisplaywidget_h_
#define _moduledisplaywidget_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QLabel>
#include <QMenu>
#include <QLineEdit>
#include <QSvgWidget>
#include <QAction>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronComponentDisplayData.h"
#include "SaffronComponentDisplayWidget.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_DISPLAY_WIDGET_X         0
#define MODULE_DISPLAY_WIDGET_Y         0
#define MODULE_DISPLAY_WIDGET_WIDTH     130
#define MODULE_DISPLAY_WIDGET_HEIGHT    30

/*****************************************************************************!
 * Exported Class : ModuleDisplayWidget
 *****************************************************************************/
class ModuleDisplayWidget : public SaffronComponentDisplayWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ModuleDisplayWidget           (class Module* InModule, QString InName); 
  ModuleDisplayWidget           (class Module* InModule, QString InName,
                                 SaffronComponentDisplayData* InData,
                                 QPoint InPoint,
                                 QSize InSize);
 //! Destructor
 public :
  ~ModuleDisplayWidget          ();

 //! Public Methods
 public :
  void                          CreateConnections       (void);

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
  void                          mousePressEvent         (QMouseEvent *event);
  
 //! Private Data
 private :
  
 //! Public Slots
 public slots :
  void                          SlotRenameModule        (void);
  void                          SlotNameEditFinished    (void);
  void                          SlotNameChanged         (const QString& InName);
  void                          SlotOpenModule          (void);

 //! Public Signals
 signals :
  void                          SignalOpenModule        (Module* InModule);

 //! Public Actions
 public :
  QAction*                      ActionRenameModule;
  QAction*                      ActionOpenModule;
};

#endif /* _moduledisplaywidget_h_*/
