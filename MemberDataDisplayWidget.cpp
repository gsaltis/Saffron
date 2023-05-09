/*****************************************************************************
 * FILE NAME    : MemberDataDisplayWidget.cpp
 * DATE         : December 28 2022
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
#include "MemberDataDisplayWidget.h"
#include "MemberData.h"
#include "MemberMimeData.h"
#include "Trace.h"
#include "MemberDataConfigureDialog.h"

/*****************************************************************************!
 * Function : MemberDataDisplayWidget
 *****************************************************************************/
MemberDataDisplayWidget::MemberDataDisplayWidget
(MemberData* InMemberData, QString InName) : SaffronComponentDisplayWidget(InName)
{
  QString                               si;
  QString                               si2;

  displayData = new SaffronComponentDisplayData(DataType::DataTypeInt16);
  displayData->SetSize(QSize(100, 30));
  si2 = displayData->GetSVGSizeString();
  
  si = displayData->GetSVGFillString("moduleGradient");
  QString st = QString("<svg xmlns=\"http://www.w3.org/2000/svg\">\n"
                       "  <defs>\n" + si + 
                       "  </defs>\n\n"
                       "  <rect " + si2 + " rx=\"10\" fill=\"url(#moduleGradient)\" stroke=\"#400\" />\n"
                       "</svg>\n");
  load(st.toLatin1());
  name = InName;
  memberData = InMemberData;
  initialize();
  resize(MEMBER_DATA_DISPLAY_WIDGET_WIDTH, MEMBER_DATA_DISPLAY_WIDGET_HEIGHT);
}

/*****************************************************************************!
 * Function : MemberDataDisplayWidget
 *****************************************************************************/
MemberDataDisplayWidget::MemberDataDisplayWidget
(MemberData* InMemberData, QString InName, DataType::DataTypeType InDataType) : SaffronComponentDisplayWidget(InName)
{
  QString                               si;
  QString                               si2;

  displayData = new SaffronComponentDisplayData(DataType::GetFillByType(InDataType));
  displayData->SetSize(QSize(100, 30));
  si2 = displayData->GetSVGSizeString();
  si = displayData->GetSVGFillString("moduleGradient");
  QString st = QString("<svg xmlns=\"http://www.w3.org/2000/svg\">\n"
                       "  <defs>\n" + si + 
                       "  </defs>\n\n"
                       "  <rect " + si2 + " rx=\"10\" fill=\"url(#moduleGradient)\" stroke=\"#400\" />\n"
                       "</svg>\n");
  load(st.toLatin1());
  name = InName;
  memberData = InMemberData;
  initialize();
  resize(MEMBER_DATA_DISPLAY_WIDGET_WIDTH, MEMBER_DATA_DISPLAY_WIDGET_HEIGHT);
}

/*****************************************************************************!
 * Function : MemberDataDisplayWidget
 *****************************************************************************/
MemberDataDisplayWidget::MemberDataDisplayWidget
(MemberData* InMemberData,
 QString InName,
 QSize InSize,
 SaffronComponentDisplayData* InDisplayData) : SaffronComponentDisplayWidget(InName)
{
  QString                               si;
  QString                               si2;

  displayData = InDisplayData;
  displayData->SetSize(InSize);
  si2 = displayData->GetSVGSizeString();
  
  si = displayData->GetSVGFillString("moduleGradient");
  QString st = QString("<svg xmlns=\"http://www.w3.org/2000/svg\">\n"
                       "  <defs>\n" + si + 
                       "  </defs>\n\n"
                       "  <rect " + si2 + " rx=\"10\" fill=\"url(#moduleGradient)\" stroke=\"#400\" />\n"
                       "</svg>\n");
  load(st.toLatin1());
  name = InName;
  memberData = InMemberData;
  initialize();
  resize(MEMBER_DATA_DISPLAY_WIDGET_WIDTH, MEMBER_DATA_DISPLAY_WIDGET_HEIGHT);
}

/*****************************************************************************!
 * Function : MemberDataDisplayWidget
 *****************************************************************************/
MemberDataDisplayWidget::MemberDataDisplayWidget
(MemberData* InMemberData, QString InName, QJsonObject InObject, QString InObjectName) : SaffronComponentDisplayWidget(InName)
{
  QString                               si;
  QString                               si2;

  displayData = new SaffronComponentDisplayData(InObject, InObjectName);
  si2 = displayData->GetSVGSizeString();
  si = displayData->GetSVGFillString("moduleGradient");
  QString st = QString("<svg xmlns=\"http://www.w3.org/2000/svg\">\n"
                       "  <defs>\n" + si + 
                       "  </defs>\n\n"
                       "  <rect " + si2 + " rx=\"10\" fill=\"url(#moduleGradient)\" stroke=\"#400\" />\n"
                       "</svg>\n");
  load(st.toLatin1());
  name = InName;
  memberData = InMemberData;
  initialize();
  resize(displayData->GetSize());
}

/*****************************************************************************!
 * Function : MemberDataDisplayWidget
 *****************************************************************************/
MemberDataDisplayWidget::MemberDataDisplayWidget
(MemberData* InMemberData, QString InName, SaffronComponentDisplayData* InData,
 QPoint InPoint, QSize InSize) : SaffronComponentDisplayWidget(InName)
{
  QString                               si;
  QString                               si2;
  resize(InSize);
  move(InPoint);
  
  displayData = InData;
  displayData->SetSize(InSize);
  displayData->SetPosition(InPoint);
  si2 = displayData->GetSVGSizeString();
  si = displayData->GetSVGFillString();

  QString st = QString("<svg xmlns=\"http://www.w3.org/2000/svg\">\n"
                       "  <defs>\n" + si + 
                       "  </defs>\n\n"
                       "  <rect " + si2 + " rx=\"10\" fill=\"url(#moduleGradient)\" stroke=\"#400\" />\n"
                       "</svg>\n");
  load(st.toLatin1());
  name = InMemberData->GetName()->ToString();
  memberData = InMemberData;
  resize(MEMBER_DATA_DISPLAY_WIDGET_WIDTH, MEMBER_DATA_DISPLAY_WIDGET_HEIGHT);
  initialize();
}

/*****************************************************************************!
 * Function : ~MemberDataDisplayWidget
 *****************************************************************************/
MemberDataDisplayWidget::~MemberDataDisplayWidget
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MemberDataDisplayWidget::initialize()
{
  setCursor(Qt::PointingHandCursor);
  InitializeSubWindows();  
  CreateSubWindows();
  CreateActions();
  CreateConnections();
  CreateMenu();
  setMouseTracking(true);
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MemberDataDisplayWidget::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MemberDataDisplayWidget::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : mousePressEvent
 *****************************************************************************/
void
MemberDataDisplayWidget::mouseMoveEvent
(QMouseEvent *InEvent)
{
  mouseLocation = InEvent->position().toPoint();
  setFocus();
}

/*****************************************************************************!
 * Function : leaveEvent
 *****************************************************************************/
void
MemberDataDisplayWidget::leaveEvent
(QEvent* InEvent)
{
  emit SignalMemberDataLeave(memberData);
  (void)InEvent;
}

/*****************************************************************************!
 * Function : enterEvent
 *****************************************************************************/
void
MemberDataDisplayWidget::enterEvent
(QEnterEvent* InEvent)
{
  (void)InEvent;
  emit SignalMemberDataEnter(memberData);
}
 
/*****************************************************************************!
 * Function : keyPressEvent
 *****************************************************************************/
void
MemberDataDisplayWidget::keyPressEvent
(QKeyEvent* InEvent)
{
  int                                   key;
  Qt::KeyboardModifiers                 mods;

  key = InEvent->key();
  mods = InEvent->modifiers();

  switch (mods) {
    case Qt::ShiftModifier : {
      switch ( key ) {
        case Qt::Key_R : {
          SlotRenameData();
          break;
        }
        default :
          break;
      }
      default :
        break;
    }
  }
}
    
/*****************************************************************************!
 * Function : mousePressEvent
 *****************************************************************************/
void
MemberDataDisplayWidget::mousePressEvent
(QMouseEvent *InEvent)
{
  QPoint                                p;
  QPixmap                               iconPixmap(1, 1);

  iconPixmap.fill(QColor(0, 0, 0, 0));
  if (InEvent->button() == Qt::LeftButton ) {
    QDrag *drag = new QDrag(this);
    MemberMimeData *mimeData = new MemberMimeData(this, memberData);
    
    mimeData->setText(QString("MemberDataMove/MemberData/MemberData"));
    drag->setMimeData(mimeData);
    drag->setPixmap(iconPixmap);
    Qt::DropAction dropAction = drag->exec();
    (void)dropAction;
  } else if ( InEvent->button() == Qt::RightButton ) {
    p = InEvent->position().toPoint();
    menu->popup(mapToGlobal(p));
  }
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MemberDataDisplayWidget::CreateConnections(void)
{
  connect(nameEdit, SIGNAL(editingFinished()), this, SLOT(SlotNameEditFinished()));
  connect(nameEdit, SIGNAL(textChanged(const QString&)),
          this,     SLOT(SlotNameChanged(const QString&)));
}

/*****************************************************************************!
 * Function : CreateMenu
 *****************************************************************************/
void
MemberDataDisplayWidget::CreateMenu(void)
{
  menu = new QMenu();
  menu->addAction(ActionRenameData);
  menu->addAction(ActionConfigureData);
  menu->addAction(ActionDelete);
  menu->addAction(ActionCopy);
  menu->addAction(ActionResize);
}

/*****************************************************************************!
 * Function : SlotNameEditFinished
 *****************************************************************************/
void
MemberDataDisplayWidget::SlotNameEditFinished(void)
{
  QString                               s;
  
  nameLabel->show();
  nameEdit->hide();
  s = nameEdit->text();
  s = s.trimmed();
  if ( s.isEmpty() ) {
    return;
  }
  nameLabel->setText(s);
  memberData->SetName(s);
  memberData->SaveConfigFile();
}

/*****************************************************************************!
 * Function : SlotRenameData
 *****************************************************************************/
void
MemberDataDisplayWidget::SlotRenameData(void)
{
  int                                   n;
  nameLabel->hide();
  nameEdit->show();
  nameEdit->setFocus();
  n = memberData->GetName()->ToString().length();
  nameEdit->setSelection(0, n);
}

/*****************************************************************************!
 * Function : CreateActions
 *****************************************************************************/
void
MemberDataDisplayWidget::CreateActions(void)
{
  ActionRenameData = new QAction("Property Rename", this);
  connect(ActionRenameData, SIGNAL(triggered()), this, SLOT(SlotRenameData()));
  ActionConfigureData = new QAction("Property Configure", this);
  connect(ActionConfigureData, SIGNAL(triggered()), this, SLOT(SlotConfigureData()));
  ActionDelete = new QAction("Property Delete", this);
  connect(ActionDelete, SIGNAL(triggered()), this, SLOT(SlotDelete()));
  ActionCopy = new QAction("Property Copy", this);
  connect(ActionCopy, SIGNAL(triggered()), this, SLOT(SlotCopy()));
  ActionResize = new QAction("Property Resize", this);
  connect(ActionResize, SIGNAL(triggered()), this, SLOT(SlotResize()));
}

/*****************************************************************************!
 * Function : SlotNameChanged
 *****************************************************************************/
void
MemberDataDisplayWidget::SlotNameChanged
(const QString& InName)
{
  (void)InName;
}

/*****************************************************************************!
 * Function : SlotConfigureData
 *****************************************************************************/
void
MemberDataDisplayWidget::SlotConfigureData(void)
{
  MemberDataConfigureDialog*            dialog;
  SaffronComponentFill*                 fill;
  QString                               si, si2;
  
  dialog = new MemberDataConfigureDialog(memberData);
  if ( !dialog->exec() ) {
    return;
  }
  memberData->SaveConfigFile();
  fill = dialog->GetFill();
  displayData->ReplaceFill(fill);
  si2 = displayData->GetSVGSizeString();
  si = displayData->GetSVGFillString("moduleGradient");
  QString st = QString("<svg xmlns=\"http://www.w3.org/2000/svg\">\n"
                       "  <defs>\n" + si + 
                       "  </defs>\n\n"
                       "  <rect " + si2 + " rx=\"10\" fill=\"url(#moduleGradient)\" stroke=\"#400\" />\n"
                       "</svg>\n");
  load(st.toLatin1());
  memberData->SaveConfigFile();
  delete dialog;
}

/*****************************************************************************!
 * Function : SetPosition
 *****************************************************************************/
void
MemberDataDisplayWidget::SetPosition
(QPoint InLocation)
{
  position = QPoint(InLocation);
  displayData->SetPosition(InLocation);
  move(InLocation);
}

/*****************************************************************************!
 * Function : GetPosition
 *****************************************************************************/
QPoint
MemberDataDisplayWidget::GetPosition(void)
{
  return displayData->GetPosition();
}

/*****************************************************************************!
 * Function : SlotDelete
 *****************************************************************************/
void
MemberDataDisplayWidget::SlotDelete(void)
{
  emit SignalDeleteMemberData(memberData);
}

/*****************************************************************************!
 * Function : SlotDelete
 *****************************************************************************/
void
MemberDataDisplayWidget::SlotCopy(void)
{
  emit SignalCopyMemberData(memberData);
}

/*****************************************************************************!
 * Function : SlotResize
 *****************************************************************************/
void
MemberDataDisplayWidget::SlotResize(void)
{
  emit SignalResizeMember(memberData);
}

/*****************************************************************************!
 * Function : GetMemberData
 *****************************************************************************/
MemberData*
MemberDataDisplayWidget::GetMemberData
()
{
  return memberData;
}

