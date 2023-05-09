/*****************************************************************************
 * FILE NAME    : ProjectInfoList.h
 * DATE         : December 02 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _projectinfolist_h_
#define _projectinfolist_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ProjectInfo.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : ProjectInfoList
 *****************************************************************************/
class ProjectInfoList : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ProjectInfoList               ();

 //! Destructor
 public :
  ~ProjectInfoList              ();

 //! Public Methods
 public :
  void
  Read
  (QString InDirName);
  int                           GetCount                (void);
  ProjectInfo*                  GetInfoByIndex          (int InIndex);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void
  Initialize
  (void);

 //! Private Data
 private :
  QList<ProjectInfo*>                   projectInfo;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _projectinfolist_h_*/
