/*****************************************************************************
 * FILE NAME    : ModuleMimeData.cpp
 * DATE         : December 15 2022
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
#include "ModuleMimeData.h"
#include "ModuleDisplayWidget.h"
#include "Module.h"

/*****************************************************************************!
 * Function : ModuleMimeData
 *****************************************************************************/
ModuleMimeData::ModuleMimeData
(ModuleDisplayWidget* InWidget, Module* InModule) : QMimeData()
{
  initialize();
  widget = InWidget;
  module = InModule;
}

/*****************************************************************************!
 * Function : ~ModuleMimeData
 *****************************************************************************/
ModuleMimeData::~ModuleMimeData
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleMimeData::initialize()
{
  widget = NULL;
  module = NULL;
}

/*****************************************************************************!
 * Function : GetWidget
 * Purpose  : ModuleDisplayWidget*
 *****************************************************************************/
ModuleDisplayWidget*
ModuleMimeData::GetWidget(void)
{
  return widget;
}

/*****************************************************************************!
 * Function : GetModule
 *****************************************************************************/
Module*
ModuleMimeData::GetModule(void)
{
  return module;
}
