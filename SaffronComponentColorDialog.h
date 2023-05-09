/*****************************************************************************
 * FILE NAME    : SaffronComponentColorDialog.h
 * DATE         : February 16 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Vertiv Company
 *****************************************************************************/
#ifndef _saffroncomponentcolordialog_h_
#define _saffroncomponentcolordialog_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QSlider>
#include <QFrame>
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SAFFRON_COMPONENT_COLOR_DIALOG_WIDTH    300
#define SAFFRON_COMPONENT_COLOR_DIALOG_HEIGHT   400

/*****************************************************************************!
 * Exported Class : SaffronComponentColorDialog
 *****************************************************************************/
class SaffronComponentColorDialog : public QDialog
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronComponentColorDialog   ();

 //! Destructor
 public :
  ~SaffronComponentColorDialog  ();

 //! Public Methods
 public :
  void                          SwitchStops             (void);

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

 //! Private Data
 private :
  QPushButton*                  OKButton;
  QPushButton*                  CancelButton;
  QGroupBox*                    FillTypeSection;
  QGroupBox*                    SolidColorSection;
  QGroupBox*                    GradientColorSection;
  QRadioButton*                 solidColorRadioButton;
  QRadioButton*                 gradientColorRadioButton;

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
  QRadioButton*                 gradientStopRadioButton[2];
  QLabel*                       redGradientTextDisplay;
  QLabel*                       greenGradientTextDisplay;
  QLabel*                       blueGradientTextDisplay;

  int                           currentGradientStop;
  
 //! Public Slots
 public slots :
  void                          SlotOKButtonPressed     ();
  void                          SlotCancelButtonPressed ();
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

#endif /* _saffroncomponentcolordialog_h_*/
