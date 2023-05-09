/*****************************************************************************
 * FILE NAME    : ProjectInfoList.cpp
 * DATE         : December 02 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QDir>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ProjectInfoList.h"
#include "Trace.h"

/*****************************************************************************!
 * Function : ProjectInfoList
 *****************************************************************************/
ProjectInfoList::ProjectInfoList
() : QWidget()
{
  Initialize();
}

/*****************************************************************************!
 * Function : ~ProjectInfoList
 *****************************************************************************/
ProjectInfoList::~ProjectInfoList
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
ProjectInfoList::Initialize(void)
{
  
}

/*****************************************************************************!
 * Function : Read
 *****************************************************************************/
void
ProjectInfoList::Read
(QString InDirName)
{
  ProjectInfo*                          info;
  QString                               dirName;
  QDir                                  dir(InDirName);

  dir.setSorting(QDir::Name);
  dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
  dir.refresh();
  QDirIterator                          it(dir);
  
  while (it.hasNext() ) {
    dirName = it.next();
    if ( ! ProjectInfo::Exists(dirName) ) {
      continue;
    }
    info = new ProjectInfo(dirName);
    if ( ! info->IsOpened() ) {
      delete info;
      continue;
    }
    projectInfo << info;
  }
}

/*****************************************************************************!
 * Function : GetCount
 *****************************************************************************/
int
ProjectInfoList::GetCount(void)
{
  return projectInfo.count();
}

/*****************************************************************************!
 * Function : GetInfoByIndex
 *****************************************************************************/
ProjectInfo*
ProjectInfoList::GetInfoByIndex
(int InIndex)
{
  if ( InIndex < 0 && InIndex >= projectInfo.count() ) {
    return NULL;
  }
  return projectInfo[InIndex];
}
