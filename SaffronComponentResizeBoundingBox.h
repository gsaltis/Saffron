/*****************************************************************************
 * FILE NAME    : SaffronComponentResizeBoundingBox.h
 * DATE         : December 23 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffroncomponentresizeboundingbox_h_
#define _saffroncomponentresizeboundingbox_h_

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
#define SAFFRON_COMPONENT_RESIZE_BOUNDING_BOX_X 200
#define SAFFRON_COMPONENT_RESIZE_BOUNDING_BOX_Y 200
#define SAFFRON_COMPONENT_RESIZE_BOUNDING_BOX_WIDTH 200
#define SAFFRON_COMPONENT_RESIZE_BOUNDING_BOX_HEIGHT 200

/*****************************************************************************!
 * Exported Class : SaffronComponentResizeBoundingBox
 *****************************************************************************/
class SaffronComponentResizeBoundingBox : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronComponentResizeBoundingBox ();

 //! Destructor
 public :
  ~SaffronComponentResizeBoundingBox ();

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

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffroncomponentresizeboundingbox_h_*/
