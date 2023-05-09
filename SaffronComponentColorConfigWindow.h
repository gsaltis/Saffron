/*****************************************************************************
 * FILE NAME    : SaffronComponentColorConfigWindow.h
 * DATE         : February 16 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Vertiv Company
 *****************************************************************************/
#ifndef _saffroncomponentcolorconfigwindow_h_
#define _saffroncomponentcolorconfigwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QSlider>
#include <QFrame>
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronComponentFill.h"
#include "SaffronComponentFillGradient.h"
#include "SaffronComponentFillSolid.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH    400
#define SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_HEIGHT   350

/*****************************************************************************!
 * Exported Class : SaffronComponentColorConfigWindow
 *****************************************************************************/
class SaffronComponentColorConfigWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronComponentColorConfigWindow   (SaffronComponentFill* InFill);

 //! Destructor
 public :
  ~SaffronComponentColorConfigWindow  ();

 //! Public Methods
 public :
  void                          SwitchStops             (void);
  void                          SetSolidColors          (void);
  void                          SetGradientColors       (void);
  SaffronComponentFill*         GetFill                 ();
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          Initialize              (void);
  void                          CreateConnections       (void);
  void                          CreateSubWindows        (void);
  void                          CreateFillTypeSection   (void );
  void                          CreateSolidColorSection (void);
  void                          CreateGradientColorSection (void);
  void                          UpdateGradientColor     ();
  void                          UpdateGradientDisplay   ();
  void                          Setup                   ();
  void                          SetStop                 (int InStop);
  void                          SetDisplayColor         (int InColorIndex, QColor InColor);
  SaffronComponentFillGradient* GetGradientFill         ();
  SaffronComponentFillSolid*    GetSolidFill            ();
  
 //! Private Data
 private :
  QGroupBox*                    FillTypeSection;
  QGroupBox*                    SolidColorSection;
  QGroupBox*                    GradientColorSection;
  QRadioButton*                 solidColorRadioButton;
  QRadioButton*                 gradientColorRadioButton;
  SaffronComponentFill*         fill;
  
  QFrame*                       redSolidDisplay;
  QSlider*                      redSolidSlider;
  QFrame*                       blueSolidDisplay;
  QSlider*                      blueSolidSlider;
  QFrame*                       greenSolidDisplay;
  QSlider*                      greenSolidSlider;
  QFrame*                       solidColorDisplay;
  QLabel*                       redSolidTextDisplay;
  QLabel*                       greenSolidTextDisplay;
  QLabel*                       blueSolidTextDisplay;

  QFrame*                       redGradientDisplay;
  QSlider*                      redGradientSlider;
  QFrame*                       blueGradientDisplay;
  QSlider*                      blueGradientSlider;
  QFrame*                       greenGradientDisplay;
  QSlider*                      greenGradientSlider;
  QFrame*                       gradientColorDisplay[3];
  QColor                        gradientStopColors[2];
  QColor                        solidColor;
  QRadioButton*                 gradientStopRadioButton[2];
  QLabel*                       redGradientTextDisplay;
  QLabel*                       greenGradientTextDisplay;
  QLabel*                       blueGradientTextDisplay;
  int                           currentGradientStop;
  
 //! Public Slots
 public slots :
  void                          SlotSolidColorChecked   (bool InChecked);
  void                          SlotGradientColorChecked(bool InChecked);
  void                          SlotRedSolidSliderChanged (int InRedValue);
  void                          SlotBlueSolidSliderChanged (int InRedValue);
  void                          SlotGreenSolidSliderChanged (int InRedValue);
  void                          SlotSolidColorChanged(int InColor);
  void                          SlotRedGradientSliderChanged (int InRedValue);
  void                          SlotBlueGradientSliderChanged (int InRedValue);
  void                          SlotGreenGradientSliderChanged (int InRedValue);
  void                          SlotGradient0RadioButtonChanged(bool InChecked);
  void                          SlotGradient1RadioButtonChanged(bool InChecked);
  
 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffroncomponentcolorconfigwindow_h_*/
