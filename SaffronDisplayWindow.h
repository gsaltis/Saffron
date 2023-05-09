/*****************************************************************************
 * FILE NAME    : SaffronDisplayWindow.h
 * DATE         : December 30 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffrondisplaywindow_h_
#define _saffrondisplaywindow_h_

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
#define SAFFRON_DISPLAY_WINDOW_X       200
#define SAFFRON_DISPLAY_WINDOW_Y       200
#define SAFFRON_DISPLAY_WINDOW_WIDTH   200
#define SAFFRON_DISPLAY_WINDOW_HEIGHT  200

/*****************************************************************************!
 * Exported Class : SaffronDisplayWindow
 *****************************************************************************/
class SaffronDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronDisplayWindow         ();

 //! Destructor
 public :
  ~SaffronDisplayWindow        ();

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

#endif /* _saffrondisplaywindow_h_*/
