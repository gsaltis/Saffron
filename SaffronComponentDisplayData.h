/*****************************************************************************
 * FILE NAME    : SaffronComponentDisplayData.h
 * DATE         : December 17 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffroncomponentdisplaydata_h_
#define _saffroncomponentdisplaydata_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QJsonDocument>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronComponentFill.h"
#include "DataType.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : SaffronComponentDisplayData
 *****************************************************************************/
class SaffronComponentDisplayData : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronComponentDisplayData   ();
  SaffronComponentDisplayData   (SaffronComponentFill* InFill);
  SaffronComponentDisplayData   (DataType::DataTypeType InType);
  SaffronComponentDisplayData   (QJsonObject& InObject, QString InName);
  
 //! Destructor
 public :
  ~SaffronComponentDisplayData  ();

 //! Public Methods
 public :
  void                          SetPosition             (QPoint InPoint);
  void                          SetSize                 (QSize InSize);
  QSize                         GetSize                 ();
  QString                       GetSVGSizeString        (void);
  QString                       GetSVGFillString        (void);
  QString                       GetSVGFillString        (QString InFillName);
  void                          CreateJSON              (QJsonObject& InObject);
  void                          FromJSON                (QJsonObject& InObject, QString InName);
  QPoint                        GetPosition             (void);
  SaffronComponentFill*         GetFill                 ();
  void                          ReplaceFill             (SaffronComponentFill* InFill);
  class SaffronComponentDisplayData* Copy               ();
  
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
  QPoint                                position;
  QSize                                 componentSize;
  SaffronComponentFill*                 background;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffroncomponentdisplaydata_h_*/
