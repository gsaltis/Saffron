/*****************************************************************************
 * FILE NAME    : MemberDataDisplayWidget.h
 * DATE         : December 28 2022
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2022 by Gregory R Saltis
 *****************************************************************************/
#ifndef _memberdatadisplaywidget_h_
#define _memberdatadisplaywidget_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <SaffronComponentDisplayWidget.h>
#include <QAction>
#include <QMenu>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SaffronComponentDisplayWidget.h"
#include "SaffronComponentDisplayData.h"
#include "DataType.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MEMBER_DATA_DISPLAY_WIDGET_X    200
#define MEMBER_DATA_DISPLAY_WIDGET_Y    200
#define MEMBER_DATA_DISPLAY_WIDGET_WIDTH 130
#define MEMBER_DATA_DISPLAY_WIDGET_HEIGHT 30

/*****************************************************************************!
 * Exported Class : MemberDataDisplayWidget
 *****************************************************************************/
class MemberDataDisplayWidget : public SaffronComponentDisplayWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MemberDataDisplayWidget
  (class MemberData* InData, QString InName);

  MemberDataDisplayWidget
  (MemberData* InMemberData, QString InName, SaffronComponentDisplayData* InData,
   QPoint InPoint, QSize InSize);

  MemberDataDisplayWidget
  (MemberData* InMemberData, QString InName, DataType::DataTypeType InDataType);

  MemberDataDisplayWidget
  (MemberData* InMemberData, QString InName, QJsonObject InObject, QString InObjectName);

  MemberDataDisplayWidget
  (MemberData* InMemberData, QString InName, QSize InSize, SaffronComponentDisplayData* InDisplayData);
  
 //! Destructor
 public :
  ~MemberDataDisplayWidget      ();

 //! Public Methods
 public :
  void                          SetPosition             (QPoint InLocation);
  QPoint                        GetPosition             (void);
  class MemberData*             GetMemberData           ();
  
 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :
  class MemberData*             memberData;
  
 //! Private Methods
 private :
  void                          initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          mousePressEvent         (QMouseEvent* InEvent);
  void                          mouseMoveEvent          (QMouseEvent* InEvent);
  void                          keyPressEvent           (QKeyEvent* InEvent);
  void                          enterEvent              (QEnterEvent* InEvent);
  void                          leaveEvent              (QEvent* InEvent);
  void                          CreateMenu              (void);
  void                          CreateActions           (void);
  void                          CreateConnections       (void);
  
 //! Private Data
 private :
  QMenu*                        menu;
  QPoint                        mouseLocation;
  QPoint                        position;
  
 //! Public Slots
 public slots :
  void                          SlotRenameData          (void);
  void                          SlotNameEditFinished    (void);
  void                          SlotNameChanged         (const QString& InName);
  void                          SlotConfigureData       (void);
  void                          SlotDelete              (void);
  void                          SlotCopy                (void);
  void                          SlotResize              (void);

 //! Public Signals
 signals :
  void                          SignalDeleteMemberData  (MemberData* InMemberData);
  void                          SignalCopyMemberData    (MemberData* InMemberData);
  void                          SignalResizeMember      (MemberData* InMemberData);
  void                          SignalMemberDataLeave   (MemberData* InMemberData);
  void                          SignalMemberDataEnter   (MemberData* InMemberData);

 //! Public Actions
 public :
  QAction*                      ActionRenameData;
  QAction*                      ActionConfigureData;
  QAction*                      ActionDelete;
  QAction*                      ActionResize;
  QAction*                      ActionCopy;

};

#endif /* _memberdatadisplaywidget_h_*/
