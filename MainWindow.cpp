/*****************************************************************************
 * FILE NAME    : MainWindow.cpp
 * DATE         : November 15 2022
 * PROJECT      : Saffron
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QMenuBar>
#include <QStatusBar>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainWindow.h"
#include "ProjectCreateDialog.h"
#include "ProjectOpenDialog.h"
#include "Trace.h"
#include "Project.h"

/*****************************************************************************!
 * Function : MainWindow
 *****************************************************************************/
MainWindow::MainWindow
() : QMainWindow()
{
}

/*****************************************************************************!
 * Function : MainWindow
 *****************************************************************************/
MainWindow::MainWindow
(QWidget* parent) : QMainWindow(parent)
{
    Initialize();
    CreateActions();
    CreateMenus();
    InitializeSubWindows();
    CreateSubWindows();
    CreateConnections();
}

/*****************************************************************************!
 * Function : ~MainWindow
 *****************************************************************************/
MainWindow::~MainWindow
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
MainWindow::Initialize()
{
  setWindowTitle(SystemConfig::SystemName);  
}

/*****************************************************************************!
 * Function : CreateSubWindows
 * Purpose  : Create Sub Windows
 *****************************************************************************/
void
MainWindow::CreateSubWindows()
{
  displayWindow = new MainDisplayWindow();  
  displayWindow->setParent(this);
  messageBar = new SaffronStatusBar();
  messageBar->setParent(this);
  messageBar->move(0, 0);
  messageBar->show();

  //! Create label
  StatusLabel = new QLabel();
  StatusLabel->setParent(messageBar);
  StatusLabel->move(5, 0);
  StatusLabel->resize(100, 20);
  StatusLabel->setText("");
  StatusLabel->setAlignment(Qt::AlignLeft);
  StatusLabel->setFont(QFont("Segoe UI", 10, QFont::Bold));
  StatusLabel->show();
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 * Purpose  : Create Sub Windows
 *****************************************************************************/
void
MainWindow::InitializeSubWindows()
{
  displayWindow = NULL;
  messageBar = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 * Purpose  : Handle Resize Event
 *****************************************************************************/
void
MainWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   width;
  int                                   height;
  int                                   statusbar_height;
  int                                   statusbar_y;
  QSize                                 size;
  QSize                                 statusbar_size;
  QSize                                 menu_size;
  QSize                                 statusLabelSize;
  int                                   statusLabelHeight;
  QPoint                                statusLabelLocation;
  int                                   statusLabelX;
  
  statusLabelSize = StatusLabel->size();
  statusLabelLocation = StatusLabel->pos();
  statusLabelX = statusLabelLocation.x();
  statusLabelHeight = statusLabelSize.height();
  
  size = InEvent->size();  
  width = size.width();
  height = size.height();
  
  menu_size = menubar->size();
  statusbar_height = SAFFRON_STATUS_BAR_HEIGHT;
  statusbar_y = size.height() - SAFFRON_STATUS_BAR_HEIGHT;
  
  height = size.height() - (menu_size.height() + statusbar_height);
  if ( displayWindow ) {
    displayWindow->move(0, menu_size.height());
    displayWindow->resize(width, height);
  }
  if ( messageBar ) {
    messageBar->move(0, statusbar_y);
    messageBar->resize(width, SAFFRON_STATUS_BAR_HEIGHT);
    StatusLabel->resize(width - (statusLabelX * 2), statusLabelHeight);
  }
}

/*****************************************************************************!
 * Function : CreateActions
 * Purpose  : Create New Actions
 *****************************************************************************/
void
MainWindow::CreateActions()
{
  ActionExit = new QAction("E&xit", this);
  connect(ActionExit, SIGNAL(triggered()), this, SLOT(SlotExit()));
  ActionCreateNewProject = new QAction("&New Project", this);
  connect(ActionCreateNewProject, SIGNAL(triggered()), this, SLOT(SlotCreateNewProject()));
  ActionOpenProject = new QAction("&Open Project", this);
  connect(ActionOpenProject, SIGNAL(triggered()), this, SLOT(SlotOpenProject()));
}

/*****************************************************************************!
 * Function : CreateMenus
 * Purpose  : Create New Menus
 *****************************************************************************/
void
MainWindow::CreateMenus()
{
  menubar = menuBar();  
  fileMenu = menubar->addMenu("&File");
  fileMenu->addAction(ActionExit);
  fileMenu->addAction(ActionCreateNewProject);
  fileMenu->addAction(ActionOpenProject);
}

/*****************************************************************************!
 * Function : SlotExit
 *****************************************************************************/
void
MainWindow::SlotExit(void)
{
  exit(EXIT_SUCCESS);  
}

/*****************************************************************************!
 * Function : SlotCreateNewProject
 *****************************************************************************/
void
MainWindow::SlotCreateNewProject(void)
{
  QString                               projectName;
  ProjectCreateDialog*                  dialog;
  int                                   n;
  Project                               project;
  
  dialog = new ProjectCreateDialog("NewProject");
  dialog->resize(300, 100);
  n = dialog->exec();
  do {
    if ( ! n ) {
      break;
    }

    projectName = dialog->GetProjectName();
    if ( Project::Exists(projectName) ) {
      break;
    }
    project.Create(projectName);
  }
  while (false);
  emit SignalProjectCreated(projectName);
  delete dialog;
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MainWindow::CreateConnections(void)
{
  connect(this,
          SIGNAL(SignalProjectCreated(QString)),
          displayWindow,
          SLOT(SlotProjectCreated(QString)));
  
  connect(this,
          SIGNAL(SignalProjectOpened(Project*)),
          displayWindow,
          SLOT(SlotProjectOpened(Project*)));
  
  connect(displayWindow,
          SIGNAL(SignalMemberDataEnter(MemberData*)),
          this,
          SLOT(SlotMemberDataEnter(MemberData*)));
          
  connect(displayWindow,
          SIGNAL(SignalMemberDataLeave(MemberData*)),
          this,
          SLOT(SlotMemberDataLeave(MemberData*)));
          
}

/*****************************************************************************!
 * Function : SlotOpenProject
 *****************************************************************************/
void
MainWindow::SlotOpenProject(void)
{
  ProjectOpenDialog*                    dialog;
  QString                               infoName;
  
  dialog = new ProjectOpenDialog();
  dialog->resize(PROJECT_OPEN_DIALOG_WIDTH, PROJECT_OPEN_DIALOG_HEIGHT);
  if ( dialog->exec() ) {
    infoName = dialog->GetInfoName();
    OpenProject(infoName);
  }
  delete dialog;
}

/*****************************************************************************!
 * Function : OpenProject
 *****************************************************************************/
void
MainWindow::OpenProject
(QString InProjectName)
{
  Project*                              project;
  if ( ! Project::Exists(InProjectName) ) {
    return;
  }

  project = new Project();
  project->Open(InProjectName);
  emit SignalProjectOpened(project);
}

/*****************************************************************************!
 * Function : SlotMemberDataLeave
 *****************************************************************************/
void
MainWindow::SlotMemberDataLeave
(MemberData* InMemberData)
{
  (void)InMemberData;
  StatusLabel->setText("");
}

/*****************************************************************************!
 * Function : SlotMemberDataEnter
 *****************************************************************************/
void
MainWindow::SlotMemberDataEnter
(MemberData* InMemberData)
{
  QString                               typeString;
  QString                               st;
  if ( ! InMemberData ) {
    return;
  }
  typeString = DataType::ToString(InMemberData->GetDataType()->GetType());
  st = InMemberData->GetName()->ToString() + QString("(") + typeString + QString(")");
  SetStatusLabelTimed(st);
}

/*****************************************************************************!
 * Function : SetStatusLabelTimed
 *****************************************************************************/
void
MainWindow::SetStatusLabelTimed
(QString InMessage)
{
  StatusLabel->setText(InMessage);
  QTimer::singleShot(15 * 1000, this, SLOT(SlotClearStatusMessage()));
}

/*****************************************************************************!
 * Function : SlotClearStatusMessage
 *****************************************************************************/
void
MainWindow::SlotClearStatusMessage(void)
{
  StatusLabel->setText("");
}
