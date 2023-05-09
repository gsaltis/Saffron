/*****************************************************************************
 * FILE NAME    : SaffronToolBarButtonSet.cpp
 * DATE         : November 25 2022
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
#include "SaffronToolBarButtonSet.h"

/*****************************************************************************!
 * Function : SaffronToolBarButtonSet
 *****************************************************************************/
SaffronToolBarButtonSet::SaffronToolBarButtonSet
() : QWidget()
{
}

/*****************************************************************************!
 * Function : ~SaffronToolBarButtonSet
 *****************************************************************************/
SaffronToolBarButtonSet::~SaffronToolBarButtonSet
()
{
}

/*****************************************************************************!
 * Function : AddButton
 *****************************************************************************/
void
SaffronToolBarButtonSet::AddButton
(SaffronToolBarButtonWindow* InButton)
{
  if ( NULL == InButton ) {
    return;
  }

  buttons << InButton;
}
