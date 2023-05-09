 /*****************************************************************************
 * FILE NAME    : Module.h
 * DATE         : November 18 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Vertiv Company
 *****************************************************************************/
#ifndef _module_h_
#define _module_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MemberData.h"
#include "MemberMethod.h"
#include "DataName.h"
#include "SaffronComponent.h"
#include "ModuleDisplayWidget.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : Module
 *****************************************************************************/
class Module : public SaffronComponent
{
  Q_OBJECT;

 //! Constructors
 public :
  Module                        ();
  Module                        (class Project* InProject);

 //! Destructor
 public :
  ~Module                       ();

 //! Public Methods
 public :
  MemberMethod*                 FindMethod              (QString InMethodName);
  virtual QString               GetTypeName             (void);
  static class Module*          Create                  (class Project*, QString InName);
  void                          CreateDisplay           (QString InName);
  void                          CreateDisplay           (int InX, int InY, QString InName);
  void                          CreateDisplay           (QPoint InPos, QString InName);
  ModuleDisplayWidget*          GetDisplay              ();
  
  void                          SaveNew                 (void);
  void                          SaveConfig              (void);
  void                          CreateConfigFile        (QString InConfigFilename);
  void                          Open                    (QString InDirectoryName);
  void                          OpenConfigFile          (QString InFullFilename);
  void                          SetPosition             (QPoint InPosition);
  void                          SetName                 (QString InName);
  QBrush                        GetBackgroundBrush      (QSize InSize);
  void                          AddDataElement          (MemberData* InData);
  QString                       GetPath                 (void);
  void                          OpenDataElements        (QString InDirectoryName);
  int                           GetDataCount            ();
  MemberData*                   GetDataByIndex          (int InIndex);
  void                          MemberDataDelete        (MemberData* InMemberData);
  void                          RemoveStorage           (void);
  bool                          GetIsOpened             (void);
  void                          SetIsOpened             (bool InIsOpened);
  void                          RemoveConfigFile        (QString InConfigFileName);
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          Initialize              ();
  QString                       GetFullConfigFilename   ();
  
 //! Private Data
 private :
  QList<MemberMethod*>                  methods;
  QList<MemberData*>                    properties;
  QString                               description;
  class Project*                        project;
  QPoint                                projectPosition;
  SaffronComponentDisplayData*          displayData;
  ModuleDisplayWidget*                  displayWidget;
  QPoint                                widgetPos;
  QSize                                 widgetSize;
  QColor                                background;
  
  bool                                  isOpened;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _module_h_*/









