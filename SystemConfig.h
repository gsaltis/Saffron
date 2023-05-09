/*****************************************************************************
 * FILE NAME    : SystemConfig.h
 * DATE         : November 15 2022
 * PROJECT      : Saffron
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _systemconfig_h_
#define _systemconfig_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QJsonObject>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : SystemConfig
 *****************************************************************************/
class SystemConfig : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SystemConfig                  ();

 //! Destructor
 public :
  ~SystemConfig                 ();

 //! Public Methods
 public :
  void                          Read                    (QString InFilename);
  QPoint                        GetDisplayPos           (void);
  QSize                         GetDisplaySize          (void);
  QString                       GetProjectsBasePath     (void);
  void                          SetProjectsBasePath     (QString InProjectsBasePath);

 //! Public Data
 public :
  static QString                SystemName;

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          ReadDisplayObject       (QJsonObject InDisplayObject);
  void                          Initialize              (void);
  void                          ReadProjectsObject      (QJsonObject InObject);
  QString                       PathResolve             (QString InPathname);
  QString                       VariableResolve         (QString InVarname);

 //! Private Data
 private :
  int                                   displayY;
  int                                   displayWidth;
  int                                   displayHeight;
  int                                   displayX;
  QString                               projectsBasePath;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _systemconfig_h_*/
