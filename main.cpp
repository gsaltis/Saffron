/*****************************************************************************
 FILE NAME      : main.cpp
 DATE           : November 15 2022
 PROJECT        : Saffron
 COPYRIGHT      : Copyright (C) 2022 by Gregory R Saltis
******************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QtGui>
#include <QCommandLineParser>
/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainWindow.h"
#include "main.h"
#include "SystemConfig.h"
#include "Project.h"
#include "Trace.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
SystemConfig*
mainSystemConfig;

QString
mainSystemFilename = "System.json";

/*****************************************************************************!
 * Function : main
 *****************************************************************************/
int
main
(int argc, char** argv)
{
  QApplication                          application(argc, argv);
  MainWindow*                           w;
  QCommandLineParser                    commandLineParser;
  QString                               projectName;
  QString                               s;

  application.setApplicationName("Saffron");
  application.setApplicationVersion("0.0.1");
  application.setOrganizationName("Greg Saltis");
  application.setOrganizationDomain("www.gsaltis.com");
  
  commandLineParser.setApplicationDescription("Saffron");
  commandLineParser.addHelpOption();
  commandLineParser.addVersionOption();
  QCommandLineOption projectNameOption(QStringList() << "p" << "project",
                                       QCoreApplication::translate("main", "Load a project nameed <project>."),
                                       QCoreApplication::translate("main", "projectname"));
  QCommandLineOption systemNameOption(QStringList() << "s" << "systemfile",
                                       QCoreApplication::translate("main", "Use a system filename."),
                                       QCoreApplication::translate("main", "filename"));
  commandLineParser.addOption(projectNameOption);
  commandLineParser.addOption(systemNameOption);
  commandLineParser.process(application);
  projectName = commandLineParser.value(projectNameOption);
  s = commandLineParser.value(systemNameOption);
  if ( ! s.isEmpty() ) {
    mainSystemFilename = s;
  }
  
  mainSystemConfig = new SystemConfig();
  mainSystemConfig->Read(mainSystemFilename);
  s = mainSystemConfig->GetProjectsBasePath();
  w = new MainWindow(NULL);
  w->resize(mainSystemConfig->GetDisplaySize());
  w->move(mainSystemConfig->GetDisplayPos());
  w->show();
  if ( ! projectName.isNull() && Project::Exists(projectName) ) {
    w->OpenProject(projectName);
  }
  return application.exec();
}
