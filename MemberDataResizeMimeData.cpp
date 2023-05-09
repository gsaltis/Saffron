/*****************************************************************************
 * FILE NAME    : MemberDataResizeMimeData.cpp
 * DATE         : December 31 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MemberDataResizeMimeData.h"
#include "MemberData.h"
#include "SaffronComponentResizeHandle.h"

/*****************************************************************************!
 * Function : MemberDataResizeMimeData
 *****************************************************************************/
MemberDataResizeMimeData::MemberDataResizeMimeData
(SaffronComponentResizeHandle* InSaffronComponentResizeHandle, MemberData* InMemberData) : QMimeData()
{
  initialize();
  resizeHandle = InSaffronComponentResizeHandle;
  memberData = InMemberData;
}

/*****************************************************************************!
 * Function : ~MemberDataResizeMimeData
 *****************************************************************************/
MemberDataResizeMimeData::~MemberDataResizeMimeData
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MemberDataResizeMimeData::initialize()
{
  resizeHandle = NULL;
  memberData = NULL;
}

/*****************************************************************************!
 * Function : GetWidget
 *****************************************************************************/
SaffronComponentResizeHandle*
MemberDataResizeMimeData::GetResizeHandle(void)
{
  return resizeHandle;
}

/*****************************************************************************!
 * Function : GetMemberData
 *****************************************************************************/
MemberData*
MemberDataResizeMimeData::GetMemberData(void)
{
  return memberData;
}
