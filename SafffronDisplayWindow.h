/*****************************************************************************
 * FILE NAME    : SafffronDisplayWindow.h
 * DATE         : December 30 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _safffrondisplaywindow_h_
#define _safffrondisplaywindow_h_

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
#define SAFFFRON_DISPLAY_WINDOW_X       200
#define SAFFFRON_DISPLAY_WINDOW_Y       200
#define SAFFFRON_DISPLAY_WINDOW_WIDTH   200
#define SAFFFRON_DISPLAY_WINDOW_HEIGHT  200

/*****************************************************************************!
 * Exported Class : SafffronDisplayWindow
 *****************************************************************************/
class SafffronDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SafffronDisplayWindow         ();

 //! Destructor
 public :
  ~SafffronDisplayWindow        ();

 //! Public Methods
 public :

 //! Public Data
 public :

 //! Protected Methods
 protected :
  QPoint                        SnapToGrid              (QPoint InPoint);

 //! Protected Data
 protected :
  bool                                  useGrid;
  bool                                  displayGrid;
  int                                   gridSize;

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
  void                          SlotSetUseGrid          (bool InUseGrid);
  void                          SlotDisplayGrid         (bool InDisplayGrid);

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _safffrondisplaywindow_h_*/
