/*****************************************************************************
 * FILE NAME    : ModuleDisplayWindow.cpp
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
#include "ModuleDisplayWindow.h"
#include "Trace.h"
#include "MemberMimeData.h"
#include "main.h"

/*****************************************************************************!
 * Function : ModuleDisplayWindow
 *****************************************************************************/
ModuleDisplayWindow::ModuleDisplayWindow
() : SaffronDisplayWindow()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(128, 0, 0)));
  setPalette(pal);
  setAcceptDrops(true);
  setAutoFillBackground(true);
  setMouseTracking(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ModuleDisplayWindow
 *****************************************************************************/
ModuleDisplayWindow::~ModuleDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleDisplayWindow::initialize()
{
  currentDataType = DataType::DataTypeInt32;
  currentModule = NULL;
  InitializeSubWindows();  
  CreateSubWindows();
  CreateActions();
  CreateMenu();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleDisplayWindow::CreateSubWindows()
{
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleDisplayWindow::InitializeSubWindows()
{
}

/*****************************************************************************!
 * Function : SetModule
 *****************************************************************************/
void
ModuleDisplayWindow::SetModule
(Module* InModule)
{
  QPalette                              pal;
  QSize                                 si;

  WindowClear();
  si = size();
  currentModule = InModule;
  pal = palette();
  pal.setBrush(QPalette::Window, InModule->GetBackgroundBrush(si));
  setPalette(pal);
  WindowClear();
  MembersDisplay();
}

/*****************************************************************************!
 * Function : CreateMenu
 *****************************************************************************/
void
ModuleDisplayWindow::CreateMenu()
{
  menu = new QMenu();
  menu->addAction(ActionClose);
  menu->addAction(ActionCreateMethod);
  menu->addAction(ActionCreateDataElement);
  menu->addAction(ActionAlignDataElements);
  menu->addAction(ActionSplitWindow);
}

/*****************************************************************************!
 * Function : CreateActions
 *****************************************************************************/
void
ModuleDisplayWindow::CreateActions(void)
{
  ActionClose = new QAction("Close", this);
  connect(ActionClose, SIGNAL(triggered()), this, SLOT(SlotClose()));

  ActionCreateDataElement = new QAction("Create Property", this);
  connect(ActionCreateDataElement, SIGNAL(triggered()), this, SLOT(SlotCreateDataElement()));

  ActionCreateMethod = new QAction("Create Method", this);
  connect(ActionCreateMethod, SIGNAL(triggered()), this, SLOT(SlotCreateMethod()));

  ActionAlignDataElements = new QAction("Align  Properties", this);
  connect(ActionAlignDataElements, SIGNAL(triggered()), this, SLOT(SlotAlignDataElements()));

  ActionSplitWindow = new QAction("Split", this);
  connect(ActionSplitWindow, SIGNAL(triggered()), this, SLOT(SlotSplitWindow()));
}

/*****************************************************************************!
 * Function : SlotClose
 *****************************************************************************/
void
ModuleDisplayWindow::SlotClose(void)
{
  emit SignalCloseModuleDisplayWindow();
}

/*****************************************************************************!
 * Function : mousePressEvent
 *****************************************************************************/
void
ModuleDisplayWindow::mousePressEvent
(QMouseEvent* InEvent)
{
  QPoint                                p;
  Qt::KeyboardModifiers                 mods;

  p = InEvent->position().toPoint();
  mousePressPoint = p;
  if ( InEvent->button() == Qt::RightButton ) {
    menu->popup(mapToGlobal(p));
    return;
  }
  if ( InEvent->button() == Qt::LeftButton ) {
    mods = InEvent->modifiers();
    if ( mods == Qt::ControlModifier ) {
      emit(SignalCloseModuleDisplayWindow());
    }
    return;
  }
}

/*****************************************************************************!
 * Function : mouseMoveEvent
 *****************************************************************************/
void
ModuleDisplayWindow::mouseMoveEvent
(QMouseEvent* InEvent)
{
  QPoint                        p;

  p = InEvent->position().toPoint();
  mouseLocation = p;
  setFocus();
}

/*****************************************************************************!
 * Function : keyPressEvent
 *****************************************************************************/
void
ModuleDisplayWindow::keyPressEvent
(QKeyEvent* InEvent)
{
  int                                   key;
  Qt::KeyboardModifiers                 mods;

  key = InEvent->key();
  mods = InEvent->modifiers();

  //!
  if ( mods == Qt::ShiftModifier ) {
    if ( key == Qt::Key_D ) {
      mousePressPoint = mouseLocation;
      SlotCreateDataElement();
    }
    return;
  }

  //!
  if ( mods == (Qt::ControlModifier | Qt::ShiftModifier) ) {
    if ( key == Qt::Key_Question ) {
      printf("ModuleDisplayWindow\n");
    }
    return;
  }
  
  //!
  if ( mods == Qt::ControlModifier ) {
    if ( key == Qt::Key_Left ) {
      emit(SignalCloseModuleDisplayWindow());
    }
  }
}

/*****************************************************************************!
 * Function : SlotCreateDataElement
 *****************************************************************************/
void
ModuleDisplayWindow::SlotCreateDataElement(void)
{
  QPoint                                loc;
  MemberData*                           dataElement;
  MemberDataDisplayWidget*              displayWidget;
  QString                               st;

  st = DataType::ToString(currentDataType);
  dataElement = MemberData::Create(currentModule, DataType::ToString(currentDataType),
                                   DataType::ToString(currentDataType));
  loc = SnapToGrid(mousePressPoint);
  dataElement->CreateDisplay(loc, DataType::ToString(currentDataType), currentDataType);
  displayWidget = dataElement->GetDisplay();
  displayWidget->setParent(this);
  connect(displayWidget,
          SIGNAL(SignalDeleteMemberData(MemberData*)),
          this,
          SLOT(SlotDeleteMemberData(MemberData*)));
  connect(displayWidget,
          SIGNAL(SignalResizeMember(MemberData*)),
          this,
          SLOT(SlotMemberResize(MemberData*)));
  connect(displayWidget,
          SIGNAL(SignalCopyMemberData(MemberData*)),
          this,
          SLOT(SlotCopyMemberData(MemberData*)));
  connect(displayWidget,
          SIGNAL(SignalMemberDataEnter(MemberData*)),
          this,
          SLOT(SlotMemberDataEnter(MemberData*)));
  connect(displayWidget,
          SIGNAL(SignalMemberDataLeave(MemberData*)),
          this,
          SLOT(SlotMemberDataLeave(MemberData*)));
  
  displayWidget->show();
  displayWidget->SlotRenameData();
  dataElement->SaveNew();
}

/*****************************************************************************!
 * Function : SlotCreateMethod
 *****************************************************************************/
void
ModuleDisplayWindow::SlotCreateMethod(void)
{
}

/*****************************************************************************!
 * Function : dragEnterEvent
 *****************************************************************************/
void
ModuleDisplayWindow::dragEnterEvent
(QDragEnterEvent* InEvent)
{
  InEvent->acceptProposedAction();
}

/*****************************************************************************!
 * Function : dragMoveEvent
 *****************************************************************************/
void
ModuleDisplayWindow::dragMoveEvent
(QDragMoveEvent* InEvent)
{
  MemberDataDisplayWidget*              widget;
  QList<QString>                        elements;
  QString                               fullname;
  QPoint                                pos;
  QString                               action;
  MemberMimeData*                       mimeData;
  
  mimeData = (MemberMimeData*)InEvent->mimeData();

  if ( NULL == mimeData ) {
    return;
  }

  if ( ! mimeData->hasText() ) {
    return;
  }

  fullname = mimeData->text();
  elements = fullname.split("/");
  action = elements[0];
  if ( action == "MemberDataMove" ) {
    pos = InEvent->position().toPoint();
    widget = mimeData->GetWidget();
    widget->move(SnapToGrid(pos));
    InEvent->accept();
  }
}

/*****************************************************************************!
 * Function : dropEvent
 *****************************************************************************/
void
ModuleDisplayWindow::dropEvent
(QDropEvent* InEvent)
{
  MemberDataDisplayWidget*              widget;
  QList<QString>                        elements;
  QString                               fullname;
  QPoint                                pos;
  QPoint                                p;
  QString                               action;
  MemberMimeData*                       mimeData;
  MemberData*                           memberData;
  
  mimeData = (MemberMimeData*)InEvent->mimeData();

  if ( NULL == mimeData ) {
    return;
  }

  if ( ! mimeData->hasText() ) {
    return;
  }

  memberData = mimeData->GetMemberData();
  fullname = mimeData->text();
  elements = fullname.split("/");
  action = elements[0];
  if ( action == "MemberDataMove" ) {
    pos = InEvent->position().toPoint();
    widget = mimeData->GetWidget();
    p = SnapToGrid(pos);
    memberData->SetPosition(p);
    memberData->SaveConfigFile();
    widget->move(p);
    InEvent->acceptProposedAction();
  }
}

/*****************************************************************************!
 * Function : MembersDisplay
 *****************************************************************************/
void
ModuleDisplayWindow::MembersDisplay(void)
{
  int                                   n, i;
  MemberData*                           md;
  MemberDataDisplayWidget*              di;
  QSize                                 si;
  QPoint                                po;
  QString                               na;
  n = currentModule->GetDataCount();
  for (i = 0; i < n; i++) {
    
    md = currentModule->GetDataByIndex(i);
    di = md->GetDisplay();
    po = di->GetPosition();
    di->move(di->GetPosition());
    na = md->GetName()->ToString();
    si = di->size();
    po = di->pos();
    di->setParent(this);
    connect(di,
            SIGNAL(SignalDeleteMemberData(MemberData*)),
            this,
            SLOT(SlotDeleteMemberData(MemberData*)));
    connect(di,
            SIGNAL(SignalResizeMember(MemberData*)),
            this,
            SLOT(SlotMemberResize(MemberData*)));
    connect(di,
            SIGNAL(SignalCopyMemberData(MemberData*)),
            this,
            SLOT(SlotCopyMemberData(MemberData*)));
    connect(di,
            SIGNAL(SignalMemberDataEnter(MemberData*)),
            this,
            SLOT(SlotMemberDataEnter(MemberData*)));
    connect(di,
            SIGNAL(SignalMemberDataLeave(MemberData*)),
            this,
            SLOT(SlotMemberDataLeave(MemberData*)));
    di->show();
    displayElements << di;
  }
}

/*****************************************************************************!
 * Function : SlotAlignDataElements
 *****************************************************************************/
void
ModuleDisplayWindow::SlotAlignDataElements(void)
{
  int                                   i, n;
  int                                   yGap;
  MemberData*                           memberData;
  MemberDataDisplayWidget*              memberWidget;
  QSize                                 s;
  int                                   height, width, maxWidth;
  int                                   x, y;
  QPoint                                p;
  
  n = currentModule->GetDataCount();
  yGap = WINDOW_GAP_Y;
  x = 10;
  y = 10;
  maxWidth = 0;
  for (i = 0; i < n; i++) {
    memberData = currentModule->GetDataByIndex(i);
    memberWidget = memberData->GetDisplay();
    s = memberWidget->size();
    height = s.height();
    width =  s.width();
    if ( maxWidth < width ) {
      maxWidth = width;
    }
    memberWidget->move(x, y);
    p = QPoint(x, y);
    memberWidget->SetPosition(p);
    memberData->SaveConfigFile();
    y += height + yGap;
  }
}

/*****************************************************************************!
 * Function : SlotDeleteMemberData
 *****************************************************************************/
void
ModuleDisplayWindow::SlotDeleteMemberData
(MemberData* InMemberData)
{
  if ( currentModule ) {
    currentModule->MemberDataDelete(InMemberData);
  }
}

/*****************************************************************************!
 * Function : WindowClear
 *****************************************************************************/
void
ModuleDisplayWindow::WindowClear(void)
{
  MemberDataDisplayWidget*              di;
  int                                   i, n;
  
  n = displayElements.count();
  for ( i = 0 ; i < n ; i++ ) {
    di = displayElements[i];
    di->setParent(NULL);
  }

  n = displayElements.count();
}

/*****************************************************************************!
 * Function : SlotSplit
 *****************************************************************************/
void
ModuleDisplayWindow::SlotSplitWindow(void)
{
  emit SignalModuleWindowSplit(this);
}

/*****************************************************************************!
 * Function : SlotMemberResize
 *****************************************************************************/
void
ModuleDisplayWindow::SlotMemberResize
(MemberData* InMemberData)
{
  emit SignalMemberDataResize(InMemberData);
}

/*****************************************************************************!
 * Function : SlotCopyMemberData
 *****************************************************************************/
void
ModuleDisplayWindow::SlotCopyMemberData
(MemberData* InMemberData)
{
  QSize                                 memberSize;
  QPoint                                loc;
  MemberData*                           dataElement;
  MemberDataDisplayWidget*              displayWidget;
  DataType::DataTypeType                type;
  QString                               memberName;
  QPoint                                p, p2;
  QSize                                 s;
  MemberDataDisplayWidget*              dw;
  SaffronComponentDisplayData*          newDisplayData;
  SaffronComponentDisplayData*          displayData;
  
  memberSize = InMemberData->GetSize();  
  type = InMemberData->GetDataType()->GetType();
  memberName = InMemberData->GetName()->ToString();
  dw = InMemberData->GetDisplay();
  displayData = dw->GetDisplayData();
  newDisplayData = displayData->Copy();
    
  dataElement = MemberData::Create(currentModule, memberName,
                                   DataType::ToString(type));
                                   
  p = dw->pos();
  s = dw->size();


  p2 = p + QPoint(s.width() + 10, 0);
  loc = SnapToGrid(p2);
  dataElement->CreateDisplay(loc, memberName, memberSize, newDisplayData);
  displayWidget = dataElement->GetDisplay();
  displayWidget->setParent(this);
  displayWidget->SetSize(memberSize);
  displayWidget->resize(memberSize);
  connect(displayWidget,
          SIGNAL(SignalDeleteMemberData(MemberData*)),
          this,
          SLOT(SlotDeleteMemberData(MemberData*)));
  connect(displayWidget,
          SIGNAL(SignalResizeMember(MemberData*)),
          this,
          SLOT(SlotMemberResize(MemberData*)));
  connect(displayWidget,
          SIGNAL(SignalCopyMemberData(MemberData*)),
          this,
          SLOT(SlotCopyMemberData(MemberData*)));
  connect(displayWidget,
          SIGNAL(SignalMemberDataEnter(MemberData*)),
          this,
          SLOT(SlotMemberDataEnter(MemberData*)));
  connect(displayWidget,
          SIGNAL(SignalMemberDataLeave(MemberData*)),
          this,
          SLOT(SlotMemberDataLeave(MemberData*)));
  displayWidget->show();
  dataElement->SaveNew();
}

/*****************************************************************************!
 * Function : SlotMemberDataEnter
 *****************************************************************************/
void
ModuleDisplayWindow::SlotMemberDataEnter
(MemberData* InMemberData)
{
  emit SignalMemberDataEnter(InMemberData);  
}

/*****************************************************************************!
 * Function : SlotMemberDataLeave
 *****************************************************************************/
void
ModuleDisplayWindow::SlotMemberDataLeave
(MemberData* InMemberData)
{
  emit SignalMemberDataLeave(InMemberData);
}

/*****************************************************************************!
 * Function : SlotUserDataTypeChanged
 *****************************************************************************/
void
ModuleDisplayWindow::SlotUserDataTypeChanged
(QString InUserDataTypeName)
{
  currentDataType =DataType::FromString(QString("User"));
  currentUserDataType = InUserDataTypeName;
}

/*****************************************************************************!
 * Function : SlotDataTypeChanged
 *****************************************************************************/
void
ModuleDisplayWindow::SlotDataTypeChanged
(QString InDataTypeName)
{
  currentDataType = DataType::FromString(InDataTypeName);
  currentUserDataType = "";
}

/*****************************************************************************!
 * Function : GetCurrentUserDataType
 *****************************************************************************/
QString
ModuleDisplayWindow::GetCurrentUserDataType(void)
{
  
  return currentUserDataType;
}

/*****************************************************************************!
 * Function : SetCurrentUserDataType
 *****************************************************************************/
void
ModuleDisplayWindow::SetCurrentUserDataType
(QString InCurrentUserDataType)
{
  QString                                       st;
  currentUserDataType = InCurrentUserDataType;
  st = DataType::ToString(currentDataType);
}
