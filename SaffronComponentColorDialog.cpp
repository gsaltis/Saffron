/*****************************************************************************
 * FILE NAME    : SaffronComponentColorDialog.cpp
 * DATE         : February 16 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Vertiv Company
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QRadioButton>
#include <QSlider>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronComponentColorDialog.h"

/*****************************************************************************!
 * Function : SaffronComponentColorDialog
 *****************************************************************************/
SaffronComponentColorDialog::SaffronComponentColorDialog
() : QDialog()
{
  Initialize();
}

/*****************************************************************************!
 * Function : ~SaffronComponentColorDialog
 *****************************************************************************/
SaffronComponentColorDialog::~SaffronComponentColorDialog
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
SaffronComponentColorDialog::Initialize(void)
{
  CreateSubWindows();  
  CreateConnections();
  resize(SAFFRON_COMPONENT_COLOR_DIALOG_WIDTH, SAFFRON_COMPONENT_COLOR_DIALOG_HEIGHT);
  solidColorRadioButton->setChecked(true);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
SaffronComponentColorDialog::CreateConnections(void)
{
  connect(OKButton, SIGNAL(pressed()), this, SLOT(SlotOKButtonPressed()));  
  connect(CancelButton, SIGNAL(pressed()), this, SLOT(SlotCancelButtonPressed()));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SaffronComponentColorDialog::CreateSubWindows(void)
{
  int                                   buttonHeight;
  int                                   buttonGap;
  int                                   cancelButtonX;
  int                                   okButtonX;
  int                                   buttonY;
  int                                   cancelButtonWidth;
  int                                   okButtonWidth;
  
  okButtonWidth = 40;
  cancelButtonWidth = 60;
  buttonGap = 5;
  buttonHeight = 20;
  okButtonX = SAFFRON_COMPONENT_COLOR_DIALOG_WIDTH - (okButtonWidth + cancelButtonWidth + (3 * buttonGap));
  cancelButtonX = SAFFRON_COMPONENT_COLOR_DIALOG_WIDTH - (cancelButtonWidth + (2 * buttonGap));
  buttonY = SAFFRON_COMPONENT_COLOR_DIALOG_HEIGHT - (buttonGap + buttonHeight);
 
  OKButton = new QPushButton();
  OKButton->setParent(this);
  OKButton->setText("OK");
  OKButton->move(okButtonX, buttonY);
  OKButton->resize(okButtonWidth, buttonHeight);
  
  CancelButton = new QPushButton();
  CancelButton->setParent(this);
  CancelButton->setText("Cancel");
  CancelButton->move(cancelButtonX, buttonY);
  CancelButton->resize(cancelButtonWidth, buttonHeight);

  CreateFillTypeSection();
  CreateSolidColorSection();
  CreateGradientColorSection();
  SlotSolidColorChecked(true);
}

/*****************************************************************************!
 * Function : SlotOKButtonPressed
 *****************************************************************************/
void
SaffronComponentColorDialog::SlotOKButtonPressed()
{
  accept();
}

/*****************************************************************************!
 * Function : SlotCancelButtonPressed
 *****************************************************************************/
void
SaffronComponentColorDialog::SlotCancelButtonPressed()
{
  reject();
}

/*****************************************************************************!
 * Function : create_Fill Type
 *****************************************************************************/
void
SaffronComponentColorDialog::CreateFillTypeSection(void)
{
  int                                   y;
  QLabel*                               label;
  FillTypeSection = new QGroupBox();
  FillTypeSection->setParent(this);
  FillTypeSection->resize(SAFFRON_COMPONENT_COLOR_DIALOG_WIDTH - 20, 70);
  FillTypeSection->move(10,20);
  FillTypeSection->setTitle("Fill Type");

  y = 20;
  label = new QLabel();  
  label->setParent(FillTypeSection);
  label->move(10,y);
  label->resize(100,20);
  label->setText("Solid Color : ");
  label->setAlignment(Qt::AlignRight);
  // label->setFont(QFont("Segoe UI", 10, QFont::Normal));

  solidColorRadioButton = new QRadioButton();  
  solidColorRadioButton->setParent(FillTypeSection);
  solidColorRadioButton->move(115, y + 2);
  connect(solidColorRadioButton,
          SIGNAL(toggled(bool)),
          this,
          SLOT(SlotSolidColorChecked(bool)));

  y += 20;
  label = new QLabel();  
  label->setParent(FillTypeSection);
  label->move(10,y);
  label->resize(100,20);
  label->setText("Gradient Color : ");
  label->setAlignment(Qt::AlignRight);
  // label->setFont(QFont("Segoe UI", 10, QFont::Normal));

  gradientColorRadioButton = new QRadioButton();  
  gradientColorRadioButton->setParent(FillTypeSection);
  gradientColorRadioButton->move(115, y + 2);
  connect(gradientColorRadioButton,
          SIGNAL(toggled(bool)),
          this,
          SLOT(SlotGradientColorChecked(bool)));
  
}

/*****************************************************************************!
 * Function : SlotSolidColorChecked
 *****************************************************************************/
void
SaffronComponentColorDialog::SlotSolidColorChecked
(bool InChecked)
{
  if ( InChecked ) {
    SolidColorSection->show();
    GradientColorSection->hide();
  }
}

/*****************************************************************************!
 * Function : SlotGradientColorChecked
 *****************************************************************************/
void
SaffronComponentColorDialog::SlotGradientColorChecked
(bool InChecked)
{
  if ( InChecked ) {
    SolidColorSection->hide();
    GradientColorSection->show();
  }  
}

/*****************************************************************************!
 * Function : CreateSolidColorSection
 *****************************************************************************/
void
SaffronComponentColorDialog::CreateSolidColorSection(void)
{
  QLabel*                               label;
  int                                   y;
  
  SolidColorSection = new QGroupBox();
  SolidColorSection->setParent(this);
  SolidColorSection->resize(280,170);
  SolidColorSection->move(10,100);
  SolidColorSection->setTitle("Solid Color");

  label = new QLabel("Red", SolidColorSection);
  label->resize(80, 20);
  label->move(10, 20);

  label = new QLabel("Blue", SolidColorSection);
  label->resize(80, 20);
  label->move(10, 45);

  label = new QLabel("Green", SolidColorSection);
  label->resize(80, 20);
  label->move(10, 70);

  //!
  y = 20;
  redSolidSlider = new QSlider(Qt::Horizontal, SolidColorSection);
  redSolidSlider->move(70, y);
  redSolidSlider->resize(180, 15);
  redSolidSlider->setMinimum(0);
  redSolidSlider->setMaximum(255);

  connect(redSolidSlider,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(SlotRedSolidSliderChanged(int)));

  connect(redSolidSlider,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(SlotSolidColorChanged(int)));
  
  redSolidDisplay = new QFrame(SolidColorSection);
  redSolidDisplay->resize(15, 15);
  redSolidDisplay->move(260, y);
  redSolidDisplay->setAutoFillBackground(true);
  redSolidDisplay->setFrameShape(QFrame::Panel);
  redSolidDisplay->setFrameShadow(QFrame::Raised);

  redSolidTextDisplay = new QLabel(SolidColorSection);
  redSolidTextDisplay->move(260, y+12);
  redSolidTextDisplay->setFont(QFont("Segoe UI", 8, QFont::Normal));
  redSolidTextDisplay->setText("000");

  //!
  y += 31;
  greenSolidSlider = new QSlider(Qt::Horizontal, SolidColorSection);
  greenSolidSlider->move(70, y);
  greenSolidSlider->resize(180, 15);
  greenSolidSlider->setMinimum(0);
  greenSolidSlider->setMaximum(255);

  connect(greenSolidSlider,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(SlotGreenSolidSliderChanged(int)));
  connect(greenSolidSlider,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(SlotSolidColorChanged(int)));
  
  
  greenSolidDisplay = new QFrame(SolidColorSection);
  greenSolidDisplay->resize(15, 15);
  greenSolidDisplay->move(260, y);
  greenSolidDisplay->setAutoFillBackground(true);
  greenSolidDisplay->setFrameShape(QFrame::Panel);
  greenSolidDisplay->setFrameShadow(QFrame::Raised);

  greenSolidTextDisplay = new QLabel(SolidColorSection);
  greenSolidTextDisplay->move(260, y+12);
  greenSolidTextDisplay->setFont(QFont("Segoe UI", 8, QFont::Normal));
  greenSolidTextDisplay->setText("000");

  //!
  y += 31;
  blueSolidSlider = new QSlider(Qt::Horizontal, SolidColorSection);
  blueSolidSlider->move(70, y);
  blueSolidSlider->resize(180, 15);
  blueSolidSlider->setMinimum(0);
  blueSolidSlider->setMaximum(255);

  connect(blueSolidSlider,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(SlotBlueSolidSliderChanged(int)));
  connect(blueSolidSlider,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(SlotSolidColorChanged(int)));
  
  
  blueSolidDisplay = new QFrame(SolidColorSection);
  blueSolidDisplay->resize(15, 15);
  blueSolidDisplay->move(260, y);
  blueSolidDisplay->setAutoFillBackground(true);
  blueSolidDisplay->setFrameShape(QFrame::Panel);
  blueSolidDisplay->setFrameShadow(QFrame::Raised);

  blueSolidTextDisplay = new QLabel(SolidColorSection);
  blueSolidTextDisplay->move(260, y+12);
  blueSolidTextDisplay->setFont(QFont("Segoe UI", 8, QFont::Normal));
  blueSolidTextDisplay->setText("000");

  //!
  y += 41;
  solidColorDisplay = new QFrame(SolidColorSection);
  solidColorDisplay->resize(260, 30);
  solidColorDisplay->move(10, 120);
  solidColorDisplay->setAutoFillBackground(true);
  solidColorDisplay->setFrameShape(QFrame::Panel);
  solidColorDisplay->setFrameShadow(QFrame::Raised);

  redSolidSlider->setValue(128);
  greenSolidSlider->setValue(128);
  blueSolidSlider->setValue(128);  
}

/*****************************************************************************!
 * Function : CreateGradientColorSection
 *****************************************************************************/
void
SaffronComponentColorDialog::CreateGradientColorSection(void)
{
  QLabel*                               label;
  int                                   y;

  currentGradientStop = 0;
  GradientColorSection = new QGroupBox();
  GradientColorSection->setParent(this);
  GradientColorSection->resize(280,270);
  GradientColorSection->move(10,100);
  GradientColorSection->setTitle("Gradient Color");

  label = new QLabel("Red", GradientColorSection);
  label->resize(80, 20);
  label->move(10, 20);

  label = new QLabel("Blue", GradientColorSection);
  label->resize(80, 20);
  label->move(10, 45);

  label = new QLabel("Green", GradientColorSection);
  label->resize(80, 20);
  label->move(10, 70);

  //!
  y = 20;
  redGradientSlider = new QSlider(Qt::Horizontal, GradientColorSection);
  redGradientSlider->move(70, y);
  redGradientSlider->resize(180, 15);
  redGradientSlider->setMinimum(0);
  redGradientSlider->setMaximum(255);

  connect(redGradientSlider,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(SlotRedGradientSliderChanged(int)));

  redGradientDisplay = new QFrame(GradientColorSection);
  redGradientDisplay->resize(15, 15);
  redGradientDisplay->move(260, y);
  redGradientDisplay->setAutoFillBackground(true);
  redGradientDisplay->setFrameShape(QFrame::Panel);
  redGradientDisplay->setFrameShadow(QFrame::Raised);

  redGradientTextDisplay = new QLabel(GradientColorSection);
  redGradientTextDisplay->move(260, y+12);
  redGradientTextDisplay->setFont(QFont("Segoe UI", 8, QFont::Normal));
  redGradientTextDisplay->setText("000");

  //!
  y += 31;
  greenGradientSlider = new QSlider(Qt::Horizontal, GradientColorSection);
  greenGradientSlider->move(70, y);
  greenGradientSlider->resize(180, 15);
  greenGradientSlider->setMinimum(0);
  greenGradientSlider->setMaximum(255);

  connect(greenGradientSlider,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(SlotGreenGradientSliderChanged(int)));
  
  
  greenGradientDisplay = new QFrame(GradientColorSection);
  greenGradientDisplay->resize(15, 15);
  greenGradientDisplay->move(260, y);
  greenGradientDisplay->setAutoFillBackground(true);
  greenGradientDisplay->setFrameShape(QFrame::Panel);
  greenGradientDisplay->setFrameShadow(QFrame::Raised);

  greenGradientTextDisplay = new QLabel(GradientColorSection);
  greenGradientTextDisplay->move(260, y+12);
  greenGradientTextDisplay->setFont(QFont("Segoe UI", 8, QFont::Normal));
  greenGradientTextDisplay->setText("000");

  //!
  y += 31;
  blueGradientSlider = new QSlider(Qt::Horizontal, GradientColorSection);
  blueGradientSlider->move(70, y);
  blueGradientSlider->resize(180, 15);
  blueGradientSlider->setMinimum(0);
  blueGradientSlider->setMaximum(255);

  connect(blueGradientSlider,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(SlotBlueGradientSliderChanged(int)));
  
  blueGradientDisplay = new QFrame(GradientColorSection);
  blueGradientDisplay->resize(15, 15);
  blueGradientDisplay->move(260, y);
  blueGradientDisplay->setAutoFillBackground(true);
  blueGradientDisplay->setFrameShape(QFrame::Panel);
  blueGradientDisplay->setFrameShadow(QFrame::Raised);

  blueGradientTextDisplay = new QLabel(GradientColorSection);
  blueGradientTextDisplay->move(260, y+12);
  blueGradientTextDisplay->setFont(QFont("Segoe UI", 8, QFont::Normal));
  blueGradientTextDisplay->setText("000");

  //!
  y += 38;
  gradientColorDisplay[0] = new QFrame(GradientColorSection);
  gradientColorDisplay[0]->resize(240, 30);
  gradientColorDisplay[0]->move(30, y);
  gradientColorDisplay[0]->setAutoFillBackground(true);
  gradientColorDisplay[0]->setFrameShape(QFrame::Panel);
  gradientColorDisplay[0]->setFrameShadow(QFrame::Raised);
  gradientStopRadioButton[0] = new QRadioButton();
  gradientStopRadioButton[0]->setParent(GradientColorSection);
  gradientStopRadioButton[0]->move(10, y);
  gradientStopRadioButton[0]->setChecked(true);
  connect(gradientStopRadioButton[0],
          SIGNAL(toggled(bool)),
          this,
          SLOT(SlotGradient0RadioButtonChanged(bool)));
    
  //!
  y += 41;
  gradientColorDisplay[1] = new QFrame(GradientColorSection);
  gradientColorDisplay[1]->resize(240, 30);
  gradientColorDisplay[1]->move(30, y);
  gradientColorDisplay[1]->setAutoFillBackground(true);
  gradientColorDisplay[1]->setFrameShape(QFrame::Panel);
  gradientColorDisplay[1]->setFrameShadow(QFrame::Raised);
  gradientStopRadioButton[1] = new QRadioButton(GradientColorSection);
  gradientStopRadioButton[1]->setParent(GradientColorSection);
  gradientStopRadioButton[1]->move(10, y);
  connect(gradientStopRadioButton[1],
          SIGNAL(toggled(bool)),
          this,
          SLOT(SlotGradient1RadioButtonChanged(bool)));
  
  //!
  y += 41;
  gradientColorDisplay[2] = new QFrame(GradientColorSection);
  gradientColorDisplay[2]->resize(240, 30);
  gradientColorDisplay[2]->move(30, y);
  gradientColorDisplay[2]->setAutoFillBackground(true);
  gradientColorDisplay[2]->setFrameShape(QFrame::Panel);
  gradientColorDisplay[2]->setFrameShadow(QFrame::Raised);

  
  redGradientSlider->setValue(128);
  greenGradientSlider->setValue(128);
  blueGradientSlider->setValue(128);  
}

/*****************************************************************************!
 * Function : SlotRedSolidSliderChanged
 *****************************************************************************/
void
SaffronComponentColorDialog::SlotRedSolidSliderChanged
(int InRedValue)
{
  QPalette                              pal;

  pal = redSolidDisplay->palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(InRedValue, 0, 0)));
  redSolidDisplay->setPalette(pal);
  redSolidTextDisplay->setText(QString("%1").arg(InRedValue));
}

/*****************************************************************************!
 * Function : SlotGreenSolidSliderChanged
 *****************************************************************************/
void
SaffronComponentColorDialog::SlotGreenSolidSliderChanged
(int InGreenValue)
{
  QPalette                              pal;

  pal = greenSolidDisplay->palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(0, InGreenValue, 0)));
  greenSolidDisplay->setPalette(pal);
  greenSolidTextDisplay->setText(QString("%1").arg(InGreenValue));
}

/*****************************************************************************!
 * Function : SlotSolidColorChanged
 *****************************************************************************/
void
SaffronComponentColorDialog::SlotSolidColorChanged
(int InColor)
{
  QPalette                              pal;

  (void)InColor;
  
  pal = solidColorDisplay->palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(redSolidSlider->value(),
                                               greenSolidSlider->value(),
                                               blueSolidSlider->value())));
  solidColorDisplay->setPalette(pal);
}

/*****************************************************************************!
 * Function : SlotBlueSolidSliderChanged
 *****************************************************************************/
void
SaffronComponentColorDialog::SlotBlueSolidSliderChanged
(int InBlueValue)
{
  QPalette                              pal;

  pal = blueSolidDisplay->palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(0, 0, InBlueValue)));
  blueSolidDisplay->setPalette(pal);
  blueSolidTextDisplay->setText(QString("%1").arg(InBlueValue));
}

/*****************************************************************************!
 * Function : SlotRedGradientSliderChanged
 *****************************************************************************/
void
SaffronComponentColorDialog::SlotRedGradientSliderChanged
(int InRedValue)
{
  QPalette                              pal;
  QColor                                c;

  c = gradientStopColors[currentGradientStop];
  gradientStopColors[currentGradientStop] = QColor(InRedValue, c.green(), c.blue());

  pal = redGradientDisplay->palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(InRedValue, 0, 0)));
  redGradientDisplay->setPalette(pal);
  redGradientTextDisplay->setText(QString("%1").arg(InRedValue));

  UpdateGradientColor();
}

/*****************************************************************************!
 * Function : SlotGreenGradientSliderChanged
 *****************************************************************************/
void
SaffronComponentColorDialog::SlotGreenGradientSliderChanged
(int InGreenValue)
{
  QPalette                              pal;
  QColor                                c;

  c = gradientStopColors[currentGradientStop];
  gradientStopColors[currentGradientStop] = QColor(c.red(), InGreenValue, c.blue());

  pal = greenGradientDisplay->palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(0, InGreenValue, 0)));
  greenGradientDisplay->setPalette(pal);
  greenGradientTextDisplay->setText(QString("%1").arg(InGreenValue));
  UpdateGradientColor();
}

/*****************************************************************************!
 * Function : SlotBlueGradientSliderChanged
 *****************************************************************************/
void
SaffronComponentColorDialog::SlotBlueGradientSliderChanged
(int InBlueValue)
{
  QPalette                              pal;
  QColor                                c;

  c = gradientStopColors[currentGradientStop];
  gradientStopColors[currentGradientStop] = QColor(c.red(), c.green(), InBlueValue);

  pal = blueGradientDisplay->palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(0, 0, InBlueValue)));
  blueGradientDisplay->setPalette(pal);
  blueGradientTextDisplay->setText(QString("%1").arg(InBlueValue));
  UpdateGradientColor();
}

/*****************************************************************************!
 * Function : UpdateGradientColor
 *****************************************************************************/
void
SaffronComponentColorDialog::UpdateGradientColor
()
{
  QPalette                              pal;
  
  pal = gradientColorDisplay[currentGradientStop]->palette();
  pal.setBrush(QPalette::Window, QBrush(gradientStopColors[currentGradientStop]));
  gradientColorDisplay[currentGradientStop]->setPalette(pal);
  UpdateGradientDisplay();
}

/*****************************************************************************!
 * Function : UpdateGradientDisplay
 *****************************************************************************/
void
SaffronComponentColorDialog::UpdateGradientDisplay
()
{
  QPalette                              pal;
  QSize                                 s = gradientColorDisplay[2]->size();
  QLinearGradient                       grad(QPoint(0, 0), QPoint(0, s.height()));

  grad.setColorAt(0, gradientStopColors[0]);
  grad.setColorAt(1, gradientStopColors[1]);
  
  pal = gradientColorDisplay[2]->palette();
  pal.setBrush(QPalette::Window, QBrush(grad));
  gradientColorDisplay[2]->setPalette(pal);
}

/*****************************************************************************!
 * Function : SlotGradient0RadioButtonChanged
 *****************************************************************************/
void
SaffronComponentColorDialog::SlotGradient0RadioButtonChanged
(bool InChecked)
{
  if ( InChecked ) {
    currentGradientStop = 0;
  }

  SwitchStops();
}

/*****************************************************************************!
 * Function : SlotGradient1RadioButtonChanged
 *****************************************************************************/
void
SaffronComponentColorDialog::SlotGradient1RadioButtonChanged
(bool InChecked)
{
  if ( InChecked ) {
    currentGradientStop = 1;
  }
  SwitchStops();
}

/*****************************************************************************!
 * Function : SwitchStops
 *****************************************************************************/
void
SaffronComponentColorDialog::SwitchStops(void)
{
  QColor                                c;
  int                                   r, g, b;
  QPalette                              pal;
  
  c = gradientStopColors[currentGradientStop];
  r = c.red();
  g = c.green();
  b = c.blue();

  redGradientSlider->setValue(r);
  greenGradientSlider->setValue(g);
  blueGradientSlider->setValue(b);
  
  pal = redGradientDisplay->palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(r, 0, 0)));
  redGradientDisplay->setPalette(pal);
  
  pal = blueGradientDisplay->palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(0, g, 0)));
  blueGradientDisplay->setPalette(pal);
  
  pal = greenGradientDisplay->palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(0, 0, b)));
  greenGradientDisplay->setPalette(pal);
  
}
