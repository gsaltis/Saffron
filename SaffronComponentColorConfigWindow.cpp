/*****************************************************************************
 * FILE NAME    : SaffronComponentColorConfigWindow.cpp
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
#include <QLabel>
#include <QRadioButton>
#include <QSlider>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronComponentColorConfigWindow.h"
#include "SaffronComponentFillGradient.h"
#include "trace.h"

/*****************************************************************************!
 * Function : SaffronComponentColorConfigWindow
 *****************************************************************************/
SaffronComponentColorConfigWindow::SaffronComponentColorConfigWindow
(SaffronComponentFill* InFill) : QWidget()
{
  fill = InFill;
  Initialize();
}

/*****************************************************************************!
 * Function : ~SaffronComponentColorConfigWindow
 *****************************************************************************/
SaffronComponentColorConfigWindow::~SaffronComponentColorConfigWindow
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
SaffronComponentColorConfigWindow::Initialize(void)
{
  CreateSubWindows();  
  CreateConnections();
  resize(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH,
         SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_HEIGHT);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
SaffronComponentColorConfigWindow::CreateConnections(void)
{

}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SaffronComponentColorConfigWindow::CreateSubWindows(void)
{
  CreateSolidColorSection();
  CreateGradientColorSection();
  CreateFillTypeSection();
  Setup();
}

/*****************************************************************************!
 * Function : CreateFillTypeSection
 *****************************************************************************/
void
SaffronComponentColorConfigWindow::CreateFillTypeSection(void)
{
  int                                   x, y;
  QLabel*                               label;
  FillTypeSection = new QGroupBox();
  FillTypeSection->setParent(this);
  FillTypeSection->resize(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 20, 50);
  FillTypeSection->move(10,10);
  FillTypeSection->setTitle("Fill Type");

  y = 20;
  x = 10;
  label = new QLabel();  
  label->setParent(FillTypeSection);
  label->move(x,y);
  label->resize(130,20);
  label->setText("Solid Color : ");
  label->setAlignment(Qt::AlignRight);
  // label->setFont(QFont("Segoe UI", 10, QFont::Normal));

  x += 135;
  solidColorRadioButton = new QRadioButton();  
  solidColorRadioButton->setParent(FillTypeSection);
  solidColorRadioButton->move(x, y + 2);
  connect(solidColorRadioButton,
          SIGNAL(toggled(bool)),
          this,
          SLOT(SlotSolidColorChecked(bool)));

  x += 20;
  label = new QLabel();  
  label->setParent(FillTypeSection);
  label->move(x,y);
  label->resize(130,20);
  label->setText("Gradient Color : ");
  label->setAlignment(Qt::AlignRight);

  x += 135;
  gradientColorRadioButton = new QRadioButton();  
  gradientColorRadioButton->setParent(FillTypeSection);
  gradientColorRadioButton->move(x, y + 2);
  connect(gradientColorRadioButton,
          SIGNAL(toggled(bool)),
          this,
          SLOT(SlotGradientColorChecked(bool)));
}

/*****************************************************************************!
 * Function : Setup
 *****************************************************************************/
void
SaffronComponentColorConfigWindow::Setup
()
{
  QString st = fill->GetType();
  if ( st == "gradient" ) {
    gradientColorRadioButton->setChecked(true);
    SlotGradientColorChecked(true);
    SetGradientColors();
  } else {
    solidColorRadioButton->setChecked(true);
    SlotSolidColorChecked(true);
    SetSolidColors();
  }
}

/*****************************************************************************!
 * Function : SlotSolidColorChecked
 *****************************************************************************/
void
SaffronComponentColorConfigWindow::SlotSolidColorChecked
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
SaffronComponentColorConfigWindow::SlotGradientColorChecked
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
SaffronComponentColorConfigWindow::CreateSolidColorSection(void)
{
  QLabel*                               label;
  int                                   y;
  
  SolidColorSection = new QGroupBox();
  SolidColorSection->setParent(this);
  SolidColorSection->resize(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 20 ,170);
  SolidColorSection->move(10,70);
  SolidColorSection->setTitle("Solid Color");

  label = new QLabel("Red : ", SolidColorSection);
  label->resize(130, 20);
  label->move(10, 20);
  label->setAlignment(Qt::AlignRight);

  label = new QLabel("Green : ", SolidColorSection);
  label->resize(130, 20);
  label->move(10, 45);
  label->setAlignment(Qt::AlignRight);

  label = new QLabel("Blue : ", SolidColorSection);
  label->resize(130, 20);
  label->move(10, 70);
  label->setAlignment(Qt::AlignRight);

  //!
  y = 20;
  redSolidSlider = new QSlider(Qt::Horizontal, SolidColorSection);
  redSolidSlider->move(145, y);
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
  redSolidDisplay->move(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 50, y);
  redSolidDisplay->setAutoFillBackground(true);
  redSolidDisplay->setFrameShape(QFrame::Panel);
  redSolidDisplay->setFrameShadow(QFrame::Raised);

  redSolidTextDisplay = new QLabel(SolidColorSection);
  redSolidTextDisplay->move(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 50, y+12);
  redSolidTextDisplay->resize(50, 11);
  redSolidTextDisplay->setFont(QFont("Segoe UI", 8, QFont::Normal));
  redSolidTextDisplay->setText("000");

  //!
  y += 31;
  greenSolidSlider = new QSlider(Qt::Horizontal, SolidColorSection);
  greenSolidSlider->move(145, y);
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
  greenSolidDisplay->move(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 50, y);
  greenSolidDisplay->setAutoFillBackground(true);
  greenSolidDisplay->setFrameShape(QFrame::Panel);
  greenSolidDisplay->setFrameShadow(QFrame::Raised);

  greenSolidTextDisplay = new QLabel(SolidColorSection);
  greenSolidTextDisplay->move(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 50, y+12);
  greenSolidTextDisplay->setFont(QFont("Segoe UI", 8, QFont::Normal));
  greenSolidTextDisplay->setText("000");
  greenSolidTextDisplay->resize(50, 11);

  //!
  y += 31;
  blueSolidSlider = new QSlider(Qt::Horizontal, SolidColorSection);
  blueSolidSlider->move(145, y);
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
  blueSolidDisplay->move(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 50, y);
  blueSolidDisplay->setAutoFillBackground(true);
  blueSolidDisplay->setFrameShape(QFrame::Panel);
  blueSolidDisplay->setFrameShadow(QFrame::Raised);

  blueSolidTextDisplay = new QLabel(SolidColorSection);
  blueSolidTextDisplay->move(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 50, y+12);
  blueSolidTextDisplay->setFont(QFont("Segoe UI", 8, QFont::Normal));
  blueSolidTextDisplay->setText("000");
  blueSolidTextDisplay->resize(50, 11);

  //!
  y += 41;
  solidColorDisplay = new QFrame(SolidColorSection);
  solidColorDisplay->resize(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 40, 30);
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
SaffronComponentColorConfigWindow::CreateGradientColorSection(void)
{
  QLabel*                               label;
  int                                   y;

  currentGradientStop = 0;
  GradientColorSection = new QGroupBox();
  GradientColorSection->setParent(this);
  GradientColorSection->resize(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 20, 260);
  GradientColorSection->move(10,70);
  GradientColorSection->setTitle("Gradient Color");

  label = new QLabel("Red", GradientColorSection);
  label->resize(80, 20);
  label->move(10, 20);

  label = new QLabel("Green", GradientColorSection);
  label->resize(80, 20);
  label->move(10, 45);

  label = new QLabel("Blue", GradientColorSection);
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
  redGradientDisplay->move(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 50, y);
  redGradientDisplay->setAutoFillBackground(true);
  redGradientDisplay->setFrameShape(QFrame::Panel);
  redGradientDisplay->setFrameShadow(QFrame::Raised);

  redGradientTextDisplay = new QLabel(GradientColorSection);
  redGradientTextDisplay->move(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 50, y+12);
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
  greenGradientDisplay->move(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 50, y);
  greenGradientDisplay->setAutoFillBackground(true);
  greenGradientDisplay->setFrameShape(QFrame::Panel);
  greenGradientDisplay->setFrameShadow(QFrame::Raised);

  greenGradientTextDisplay = new QLabel(GradientColorSection);
  greenGradientTextDisplay->move(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 50, y+12);
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
  blueGradientDisplay->move(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 50, y);
  blueGradientDisplay->setAutoFillBackground(true);
  blueGradientDisplay->setFrameShape(QFrame::Panel);
  blueGradientDisplay->setFrameShadow(QFrame::Raised);

  blueGradientTextDisplay = new QLabel(GradientColorSection);
  blueGradientTextDisplay->move(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 50, y+12);
  blueGradientTextDisplay->setFont(QFont("Segoe UI", 8, QFont::Normal));
  blueGradientTextDisplay->setText("000");

  //!
  y += 38;
  gradientColorDisplay[0] = new QFrame(GradientColorSection);
  gradientColorDisplay[0]->resize(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 60, 30);
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
  gradientColorDisplay[1]->resize(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 60, 30);
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
  gradientColorDisplay[2]->resize(SAFFRON_COMPONENT_COLOR_CONFIG_WINDOW_WIDTH - 60, 30);
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
SaffronComponentColorConfigWindow::SlotRedSolidSliderChanged
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
SaffronComponentColorConfigWindow::SlotGreenSolidSliderChanged
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
SaffronComponentColorConfigWindow::SlotSolidColorChanged
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
SaffronComponentColorConfigWindow::SlotBlueSolidSliderChanged
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
SaffronComponentColorConfigWindow::SlotRedGradientSliderChanged
(int InRedValue)
{
  QPalette                              pal;
  QColor                                c;

  c = gradientStopColors[currentGradientStop];
  gradientStopColors[currentGradientStop] = QColor(InRedValue, c.green(), c.blue());

  pal = redGradientDisplay->palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(InRedValue, 0, 0)));
  redGradientDisplay->setPalette(pal);
  redGradientTextDisplay->setText(QString("%1").arg(InRedValue, 3, 10, QLatin1Char('0')));

  UpdateGradientColor();
}

/*****************************************************************************!
 * Function : SlotGreenGradientSliderChanged
 *****************************************************************************/
void
SaffronComponentColorConfigWindow::SlotGreenGradientSliderChanged
(int InGreenValue)
{
  QPalette                              pal;
  QColor                                c;

  c = gradientStopColors[currentGradientStop];
  gradientStopColors[currentGradientStop] = QColor(c.red(), InGreenValue, c.blue());

  pal = greenGradientDisplay->palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(0, InGreenValue, 0)));
  greenGradientDisplay->setPalette(pal);
  greenGradientTextDisplay->setText(QString("%1").arg(InGreenValue, 3, 10, QLatin1Char('0')));
  UpdateGradientColor();
}

/*****************************************************************************!
 * Function : SlotBlueGradientSliderChanged
 *****************************************************************************/
void
SaffronComponentColorConfigWindow::SlotBlueGradientSliderChanged
(int InBlueValue)
{
  QPalette                              pal;
  QColor                                c;

  c = gradientStopColors[currentGradientStop];
  gradientStopColors[currentGradientStop] = QColor(c.red(), c.green(), InBlueValue);

  pal = blueGradientDisplay->palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(0, 0, InBlueValue)));
  blueGradientDisplay->setPalette(pal);
  blueGradientTextDisplay->setText(QString("%1").arg(InBlueValue, 3, 10, QLatin1Char('0')));
  UpdateGradientColor();
}

/*****************************************************************************!
 * Function : UpdateGradientColor
 *****************************************************************************/
void
SaffronComponentColorConfigWindow::UpdateGradientColor
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
SaffronComponentColorConfigWindow::UpdateGradientDisplay
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
SaffronComponentColorConfigWindow::SlotGradient0RadioButtonChanged
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
SaffronComponentColorConfigWindow::SlotGradient1RadioButtonChanged
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
SaffronComponentColorConfigWindow::SwitchStops(void)
{
  SetStop(currentGradientStop);
}

/*****************************************************************************!
 * Function : SetStop
 *****************************************************************************/
void
SaffronComponentColorConfigWindow::SetStop
(int InStop)
{
  QColor                                c;
  int                                   r, g, b;
  QPalette                              pal;

  if ( InStop < 0 || InStop >= 2 ) {
    return;
  }
  c = gradientStopColors[InStop];
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

/*****************************************************************************!
 * Function : SetSolidColors
 *****************************************************************************/
void
SaffronComponentColorConfigWindow::SetSolidColors(void)
{
}

/*****************************************************************************!
 * Function : SetGradientColors
 *****************************************************************************/
void
SaffronComponentColorConfigWindow::SetGradientColors(void)
{
  SaffronComponentFillGradient* gfill = (SaffronComponentFillGradient*)fill;
  auto n = gfill->GetStopCount();

  for ( auto i = 0; i < n ; i++ ) {
    auto stop = gfill->GetStopByIndex(i);
    auto color = stop->GetColor();
    SetDisplayColor(i, color);
  }
  SwitchStops();
}

/*****************************************************************************!
 * Function : SetDisplayColor
 *****************************************************************************/
void
SaffronComponentColorConfigWindow::SetDisplayColor
(int InColorIndex, QColor InColor)
{
  QPalette                              pal;
  
  gradientStopColors[InColorIndex] = InColor;
  pal = gradientColorDisplay[InColorIndex]->palette();
  pal.setBrush(QPalette::Window, QBrush(InColor));
  gradientColorDisplay[InColorIndex]->setPalette(pal);
}

/*****************************************************************************!
 * Function : GetFill
 *****************************************************************************/
SaffronComponentFill*
SaffronComponentColorConfigWindow::GetFill
()
{
  if ( solidColorRadioButton->isChecked() ) {
    return GetSolidFill();
  }
  return GetGradientFill();
}

/*****************************************************************************!
 * Function : GetSolidFill
 *****************************************************************************/
SaffronComponentFillSolid*
SaffronComponentColorConfigWindow::GetSolidFill
()
{
  SaffronComponentFillSolid*            solidFill;
  solidFill = new SaffronComponentFillSolid(fill->GetName(), fill->GetRotation());
  solidFill->SetColor(solidColor);
  return solidFill;
}

/*****************************************************************************!
 * Function : GetGradientFill
 *****************************************************************************/
SaffronComponentFillGradient*
SaffronComponentColorConfigWindow::GetGradientFill
()
{
  SaffronComponentFillGradient*         gradientFill;

  gradientFill = new SaffronComponentFillGradient(fill->GetName(), fill->GetRotation());
  gradientFill->AddStop(new SaffronComponentFillGradientStop(0, gradientStopColors[0], 1.0));
  gradientFill->AddStop(new SaffronComponentFillGradientStop(1, gradientStopColors[1], 1.0));
  return gradientFill;
}
