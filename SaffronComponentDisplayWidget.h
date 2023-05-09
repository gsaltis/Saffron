/*****************************************************************************
 * FILE NAME    : SaffronComponentDisplayWidget.h
 * DATE         : December 24 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffroncomponentdisplaywidget_h_
#define _saffroncomponentdisplaywidget_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QSvgWidget>
#include <QLabel>
#include <QLineEdit>
#include <QJsonDocument>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronComponentDisplayData.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SAFFRON_COMPONENT_DISPLAY_WIDGET_X 200
#define SAFFRON_COMPONENT_DISPLAY_WIDGET_Y 200
#define SAFFRON_COMPONENT_DISPLAY_WIDGET_WIDTH 200
#define SAFFRON_COMPONENT_DISPLAY_WIDGET_HEIGHT 200

/*****************************************************************************!
 * Exported Class : SaffronComponentDisplayWidget
 *****************************************************************************/
class SaffronComponentDisplayWidget : public QSvgWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronComponentDisplayWidget (QString InName);

 //! Destructor
 public :
  ~SaffronComponentDisplayWidget ();

 //! Public Methods
 public :
  SaffronComponentDisplayData*  GetDisplayData          ();
  void                          CreateJSON              (QJsonObject& InObject);
  void                          FromJSON                (QJsonObject& InObject, QString InTag);
  void                          SetName                 (QString InName);
  void                          SetSize                 (QSize InSize);
  QSize                         GetSize                 ();
  void                          ReplaceDisplayData      (SaffronComponentDisplayData* InDisplayData);
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :
  QLabel*                       nameLabel;
  QLineEdit*                    nameEdit;
  QString                       name;
  class Module*                 module;
  QMenu*                        menu;
  SaffronComponentDisplayData*  displayData;
  
 //! Private Methods
 private :
  void                          initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  
 //! Private Data
 private :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffroncomponentdisplaywidget_h_*/
