/*****************************************************************************
 * FILE NAME    : SaffronWindowGrid.h
 * DATE         : February 15 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffronwindowgrid_h_
#define _saffronwindowgrid_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronWindowGridElement.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SAFFRON_WINDOW_GRID_X           200
#define SAFFRON_WINDOW_GRID_Y           200
#define SAFFRON_WINDOW_GRID_WIDTH       200
#define SAFFRON_WINDOW_GRID_HEIGHT      200

/*****************************************************************************!
 * Exported Class : SaffronWindowGrid
 *****************************************************************************/
class SaffronWindowGrid : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronWindowGrid             (int InRowCount, int InColumnCount);

 //! Destructor
 public :
  ~SaffronWindowGrid            ();

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
  void                          AddWidget               (QWidget* InWidget, int InRow, int InCol);
  void                          MaximizeWidget          (QWidget* InWidget);
  void                          ChangeWidgetSize        (QWidget* InWidget, int InMaximized);
  
 //! Private Data
 private :
  QList<SaffronWindowGridElement*>      widgets;
  int                                   rowCount;
  int                                   columnCount;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffronwindowgrid_h_*/
