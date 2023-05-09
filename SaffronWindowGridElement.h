/*****************************************************************************
 * FILE NAME    : SaffronWindowGridElement.h
 * DATE         : February 15 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffronwindowgridelement_h_
#define _saffronwindowgridelement_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SAFFRON_WINDOW_GRID_ELEMENT_X   200
#define SAFFRON_WINDOW_GRID_ELEMENT_Y   200
#define SAFFRON_WINDOW_GRID_ELEMENT_WIDTH 200
#define SAFFRON_WINDOW_GRID_ELEMENT_HEIGHT 200

#define MAXIMIZED_NONE                          0
#define MAXIMIZED_HORIZONTAL                    1
#define MAXIMIZED_VERTICAL                      2

/*****************************************************************************!
 * Exported Class : SaffronWindowGridElement
 *****************************************************************************/
class SaffronWindowGridElement : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronWindowGridElement      ();

 //! Destructor
 public :
  ~SaffronWindowGridElement     ();

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

 //! Private Data
 private :
  QWidget*                      widget;
  int                           maximized;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffronwindowgridelement_h_*/
