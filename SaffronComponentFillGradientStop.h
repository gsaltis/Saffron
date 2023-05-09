/*****************************************************************************
 * FILE NAME    : SaffronComponentFillGradientStop.h
 * DATE         : December 19 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _saffroncomponentfillgradientstop_h_
#define _saffroncomponentfillgradientstop_h_

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

/*****************************************************************************!
 * Exported Class : SaffronComponentFillGradientStop
 *****************************************************************************/
class SaffronComponentFillGradientStop : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SaffronComponentFillGradientStop      (qreal InPosition, QColor InColor, qreal InOpacity = 1.0);
  SaffronComponentFillGradientStop      ();
  
 //! Destructor
 public :
  ~SaffronComponentFillGradientStop     ();

 //! Public Methods
 public :
  void                          SetPosition             (qreal InPosition);
  void                          SetColor                (QColor InColor);
  void                          SetOpacity              (qreal InOpacity);
  QString                       GetSVGString            ();
  QJsonObject                   TOJSONObject            (void);
  void                          CreateJSON              (QJsonObject& InObject);
  void                          FromJSON                (QJsonObject& InObject);
  QColor                        GetColor                ();
  SaffronComponentFillGradientStop* Copy                ();
  qreal                         GetOpacity              (void);
  qreal                         GetPosition             (void);

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
  qreal                                 position;
  QColor                                color;
  qreal                                 opacity;
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _saffroncomponentfillgradientstop_h_*/
