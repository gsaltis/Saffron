/*****************************************************************************
 * FILE NAME    : MemberMethodFrameStack.cpp
 * DATE         : November 21 2022
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
#include "MemberMethodFrameStack.h"

/*****************************************************************************!
 * Function : MemberMethodFrameStack
 *****************************************************************************/
MemberMethodFrameStack::MemberMethodFrameStack
() : QWidget()
{
}

/*****************************************************************************!
 * Function : ~MemberMethodFrameStack
 *****************************************************************************/
MemberMethodFrameStack::~MemberMethodFrameStack
()
{
}

/*****************************************************************************!
 * Function : GetFrameCount
 *****************************************************************************/
int
MemberMethodFrameStack::GetFrameCount(void)
{
  return frames.count();
}
