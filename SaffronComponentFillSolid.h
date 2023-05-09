/*****************************************************************************
 * FILE NAME    : SaffronComponentFillSolid.h
 * DATE         : December 17 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffroncomponentfillsolid_h_
#define _saffroncomponentfillsolid_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronComponentFill.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : SaffronComponentFillSolid
 *****************************************************************************/
class SaffronComponentFillSolid : public SaffronComponentFill
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronComponentFillSolid      (QString InName, int InPosition = 0);

 //! Destructor
 public :
  ~SaffronComponentFillSolid    ();

 //! Public Methods
 public :
  virtual QBrush                GetBrush                (void);
  virtual QString               GetSVGString            (void);  
  virtual QString               GetSVGString            (QString InFillName);  
  virtual QString               GetType                 (void);
  virtual void                  CreateJSON              (QJsonObject& InObject);
  virtual void                  FromJSON                (QJsonObject& InObject);
  void                          SetColor                (QColor InColor);
  virtual class SaffronComponentFill*
  Copy                    ();
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :

 //! Private Data
 private :
  QColor                        color;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffroncomponentfillsolid_h_*/
