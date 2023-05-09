/*****************************************************************************
 * FILE NAME    : SaffronToolBarButtonWindow.h
 * DATE         : November 25 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffrontoolbarbuttonwindow_h_
#define _saffrontoolbarbuttonwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QPushButton>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SAFFRON_TOOL_BAR_BUTTON_WINDOW_X 200
#define SAFFRON_TOOL_BAR_BUTTON_WINDOW_Y 200
#define SAFFRON_TOOL_BAR_BUTTON_WINDOW_WIDTH 200
#define SAFFRON_TOOL_BAR_BUTTON_WINDOW_HEIGHT 200

/*****************************************************************************!
 * Exported Class : SaffronToolBarButtonWindow
 *****************************************************************************/
class SaffronToolBarButtonWindow : public QPushButton
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronToolBarButtonWindow    ();
  SaffronToolBarButtonWindow    (QString InName, QString InImageName);

 //! Destructor
 public :
  ~SaffronToolBarButtonWindow   ();

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
  void                          Initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);

 //! Private Data
 private :
  QString                               name;
  QString                               imageName;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffrontoolbarbuttonwindow_h_*/
