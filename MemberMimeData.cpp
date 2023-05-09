/*****************************************************************************
 * FILE NAME    : MemberMimeData.cpp
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
#include "MemberMimeData.h"
#include "MemberData.h"
#include "MemberDataDisplayWidget.h"

/*****************************************************************************!
 * Function : MemberMimeData
 *****************************************************************************/
MemberMimeData::MemberMimeData
(MemberDataDisplayWidget* InWidget, MemberData* InMemberData) : QMimeData()
{
  initialize();
  widget = InWidget;
  memberData = InMemberData;
}

/*****************************************************************************!
 * Function : ~MemberMimeData
 *****************************************************************************/
MemberMimeData::~MemberMimeData
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MemberMimeData::initialize()
{
  widget = NULL;
  memberData = NULL;
}

/*****************************************************************************!
 * Function : GetWidget
 *****************************************************************************/
MemberDataDisplayWidget*
MemberMimeData::GetWidget(void)
{
  return widget;
}

/*****************************************************************************!
 * Function : GetMemberData
 *****************************************************************************/
MemberData*
MemberMimeData::GetMemberData(void)
{
  return memberData;
}
