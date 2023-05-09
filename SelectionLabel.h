/*****************************************************************************
 * FILE NAME    : SelectionLabel.h
 * DATE         : December 05 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _selectionlabel_h_
#define _selectionlabel_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define SELECTION_LABEL_X               200
#define SELECTION_LABEL_Y               200
#define SELECTION_LABEL_WIDTH           200
#define SELECTION_LABEL_HEIGHT          200

/*****************************************************************************!
 * Exported Class : SelectionLabel
 *****************************************************************************/
class SelectionLabel : public QLabel
{
  Q_OBJECT;

 //! Constructors
 public :
  SelectionLabel                ();

 //! Destructor
 public :
  ~SelectionLabel               ();

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
  void                          mousePressEvent         (QMouseEvent* InEvent);
  void                          leaveEvent              (QEvent* InEvent);
  void                          enterEvent              (QEnterEvent* InEvent);

 //! Private Data
 private :
  QBrush                        currentBrush;
  
 //! Public Slots
 public slots :
  void                          SlotHoverOn             (void);
  void                          SlotHoverOff            (void);
  void                          SlotSelect              (void);
  void                          SlotDeSelect            (void);

 //! Public Signals
 signals :
  void                          SignalHoverOff          (void);
  void                          SignalHoverOn           (void);
  void                          SignalSelected          (void);

 //! Public Actions
 public :

};

#endif /* _selectionlabel_h_*/
