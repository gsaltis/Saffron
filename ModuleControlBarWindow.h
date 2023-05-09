/*****************************************************************************
 * FILE NAME    : ModuleControlBarWindow.h
 * DATE         : January 16 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _modulecontrolbarwindow_h_
#define _modulecontrolbarwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QComboBox>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "Project.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_CONTROL_BAR_WINDOW_X             200
#define MODULE_CONTROL_BAR_WINDOW_Y             200
#define MODULE_CONTROL_BAR_WINDOW_WIDTH         200
#define MODULE_CONTROL_BAR_WINDOW_HEIGHT        25

/*****************************************************************************!
 * Exported Class : ModuleControlBarWindow
 *****************************************************************************/
class ModuleControlBarWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ModuleControlBarWindow        ();

 //! Destructor
 public :
  ~ModuleControlBarWindow       ();

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
  QStringList                   dataTypesSelectAddItems (void);
  QStringList                   userDataTypesSelect_add_items (void);

 //! Private Data
 private :
  QComboBox*                    dataTypesSelect;
  Project*                      project;
  QComboBox*                    userDataTypesSelect;

 //! Public Slots
 public slots :
  void                          slotdataTypesSelectSelectedItem (int selected_index);
  void                          slotuserDataTypesSelect_selected_item (int selected_index);
  void                          SlotProjectOpened       (Project* InProject);
  void                          SlotDataTypeTextChanged (QString InString);
  void                          SlotUserDataTypeChanged (QString InUserDataTypeName);

 //! Public Signals
 signals :
  void                          SignalDataTypeChanged   (QString InDataTypeName);
  void                          SignalUserDataTypeChanged (QString InUserDataTypeName);

 //! Public Actions
 public :

};

#endif /* _modulecontrolbarwindow_h_*/
