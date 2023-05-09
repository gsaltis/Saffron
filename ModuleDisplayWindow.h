/*****************************************************************************
 * FILE NAME    : ModuleDisplayWindow.h
 * DATE         : November 21 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _moduledisplaywindow_h_
#define _moduledisplaywindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QAction>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "Module.h"
#include "SaffronDisplayWindow.h"
#include "DataType.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_DISPLAY_WINDOW_X         200
#define MODULE_DISPLAY_WINDOW_Y         200
#define MODULE_DISPLAY_WINDOW_WIDTH     200
#define MODULE_DISPLAY_WINDOW_HEIGHT    200

/*****************************************************************************!
 * Exported Class : ModuleDisplayWindow
 *****************************************************************************/
class ModuleDisplayWindow : public SaffronDisplayWindow
{
  Q_OBJECT;

 //! Constructors
 public :
  ModuleDisplayWindow           ();

 //! Destructor
 public :
  ~ModuleDisplayWindow          ();

 //! Public Methods
 public :
  void                          SetModule               (Module* InModule);
  void                          WindowClear             (void);
  QString                       GetCurrentUserDataType  (void);
  void                          SetCurrentUserDataType  (QString InCurrentUserDataType);

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
  void                          CreateMenu              ();
  void                          CreateActions           (void);
  void                          mousePressEvent         (QMouseEvent* InEvent);
  void                          mouseMoveEvent          (QMouseEvent* InEvent);
  void                          keyPressEvent           (QKeyEvent* InEvent);
  void                          dragEnterEvent          (QDragEnterEvent *event) override;
  void                          dropEvent               (QDropEvent *event) override;
  void                          dragMoveEvent           (QDragMoveEvent* InEvent) override;
  void                          MembersDisplay          (void);
  
 //! Private Data
 private :
  Module*                       currentModule;
  QMenu*                        menu;
  QPoint                        mousePressPoint;
  QPoint                        mouseLocation;
  DataType::DataTypeType        currentDataType;
  QList<MemberDataDisplayWidget*> displayElements;
  
  QString                       currentUserDataType;

 //! Public Slots
 public slots :
  void                          SlotClose               (void);
  void                          SlotCreateDataElement   (void);
  void                          SlotCreateMethod        (void);
  void                          SlotAlignDataElements   (void);
  void                          SlotDataTypeChanged     (QString InDataTypeName);
  void                          SlotDeleteMemberData    (MemberData* InMemberData);
  void                          SlotSplitWindow         (void);
  void                          SlotMemberResize        (MemberData* InMemberData);
  void                          SlotCopyMemberData      (MemberData* InMemberData);
  void                          SlotMemberDataEnter     (MemberData* InMemberData);
  void                          SlotMemberDataLeave     (MemberData* InMemberData);
  void                          SlotUserDataTypeChanged (QString InUserDataTypeName);

 //! Public Signals
 signals :
  void                          SignalModuleClose       (void);
  void                          SignalCloseModuleDisplayWindow (void);
  void                          SignalModuleWindowSplit (ModuleDisplayWindow* InModuleWindow);
  void                          SignalMemberDataResize  (MemberData* InMemberData);
  void                          SignalMemberDataLeave   (MemberData* InMemberData);
  void                          SignalMemberDataEnter   (MemberData* InMemberData);
  
 //! Public Actions
 public :
  QAction*                      ActionClose;
  QAction*                      ActionCreateDataElement;
  QAction*                      ActionCreateMethod;
  QAction*                      ActionAlignDataElements;
  QAction*                      ActionSplitWindow;

};

#endif /* _moduledisplaywindow_h_*/
