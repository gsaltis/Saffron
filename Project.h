/*****************************************************************************
 * FILE NAME    : Project.h
 * DATE         : November 21 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _project_h_
#define _project_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "Module.h"
#include "DataName.h"
#include "SaffronComponent.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : Project
 *****************************************************************************/
class Project : public SaffronComponent
{
  Q_OBJECT;

 //! Constructors
 public :
  Project                       ();

 //! Destructor
 public :
  ~Project                      ();

 //! Public Methods
 public :
  static bool
  Exists
  (QString InProjectName);

  bool
  Create
  (QString InProjectName);

  void
  CreateConfigFile
  (QString InConfigFilename);
  QString                       GetTypeName             (void);
  bool                          Open                    (QString InProjectName);
  bool                          ModuleExists            (QString InModuleName);
  QString                       GetProjectPath          (void);
  int                           GetModuleCount          ();
  Module*                       GetModuleByIndex        (int InIndex);
  QList<QString>                GetModuleNames          ();
  
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
  QList<Module*>                        modules;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _project_h_*/
