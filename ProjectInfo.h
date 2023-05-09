/*****************************************************************************
 * FILE NAME    : ProjectInfo.h
 * DATE         : December 02 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _projectinfo_h_
#define _projectinfo_h_

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
 * Exported Class : ProjectInfo
 *****************************************************************************/
class ProjectInfo : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ProjectInfo                           ();
  ProjectInfo                           (QString InName, QString InDescription,
                                         QDateTime InDateTime);
  ProjectInfo                           (QString InFilename);
  
 //! Destructor
 public :
  ~ProjectInfo                          ();

 //! Public Methods
 public :
  void                                  Initialize              (void);
  bool                          IsOpened                (void);
  QString                       GetName                 (void);
  QString                       GetDescription          (void);
  QDateTime                     GetDateTime             (void);
  static bool                   Exists                  (QString InFilename);
  
 //! Public Data
 public :
  QString                               name;
  QString                               description;
  QDateTime                             dateTime;

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :

 //! Private Data
 private :
  bool                                  opened;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _projectinfo_h_*/
