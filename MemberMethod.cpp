/*****************************************************************************
 * FILE NAME    : MemberMethod.cpp
 * DATE         : November 18 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Vertiv Company
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
#include "MemberMethod.h"

/*****************************************************************************!
 * Function : MemberMethod
 *****************************************************************************/
MemberMethod::MemberMethod
() : QWidget()
{
  frames = new MemberMethodFrameStack();
}

/*****************************************************************************!
 * Function : ~MemberMethod
 *****************************************************************************/
MemberMethod::~MemberMethod
()
{
  delete frames;
}

/*****************************************************************************!
 * Function : GetName
 *****************************************************************************/
QString
MemberMethod::GetName(void)
{
  return name->ToString();
}

/*****************************************************************************!
 * Function : GetFrameCount
 *****************************************************************************/
int
MemberMethod::GetFrameCount(void)
{
  return frames->GetFrameCount();
}

/*****************************************************************************!
 * Function : GetParameterCount
 *****************************************************************************/
int
MemberMethod::GetParameterCount(void)
{
  return parameters.count();
}

/*****************************************************************************!
 * Function : GetMethodFrame
 *****************************************************************************/
MemberMethodFrame*
MemberMethod::GetMethodFrame
(int InIndex)
{
  (void)InIndex;
  return NULL;
}

/*****************************************************************************!
 * Function : GetMethodParameter
 *****************************************************************************/
MemberMethodParameter*
MemberMethod::GetMethodParameter
(int InIndex)
{
  if ( InIndex < 0 || InIndex >= parameters.count() ) {
    return NULL;
  }
  return parameters[InIndex];
}

/*****************************************************************************!
 * Function : GetModuleView
 *****************************************************************************/
QSvgWidget*
MemberMethod::GetModuleView(void)
{
  return NULL;
}
