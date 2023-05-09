/*****************************************************************************
 * FILE NAME    : ModuleMimeData.h
 * DATE         : December 15 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Vertiv Company
 *****************************************************************************/
#ifndef _modulemimedata_h_
#define _modulemimedata_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QMimeData>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_MIME_DATA_X              200
#define MODULE_MIME_DATA_Y              200
#define MODULE_MIME_DATA_WIDTH          200
#define MODULE_MIME_DATA_HEIGHT         200

/*****************************************************************************!
 * Exported Class : ModuleMimeData
 *****************************************************************************/
class ModuleMimeData : public QMimeData
{
  Q_OBJECT;

 //! Constructors
 public :
  ModuleMimeData                (class ModuleDisplayWidget* InWidget,
                                 class Module* InModule);

 //! Destructor
 public :
  ~ModuleMimeData               ();

 //! Public Methods
 public :
  class ModuleDisplayWidget*    GetWidget               ();
  class Module*                 GetModule               (void);
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();

 //! Private Data
 private :
  class ModuleDisplayWidget*    widget;
  class Module*                 module;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _modulemimedata_h_*/
