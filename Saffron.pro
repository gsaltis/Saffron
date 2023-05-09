QMAKE_CXX                       = @echo [C+] $@ && g++ 

QMAKE_CC                        = @echo [C+] $@ && gcc 

QMAKE_MOC_EXE                   = @echo [MO] $@ && moc 

QMAKE_LINK                      = @echo [LD] $@ && g++ 

QMAKE_RC                        = @echo [RC] $@ && windres 

QMAKE_RCC                       = @echo [RC] $@ && rcc 

#QMAKE_LFLAGS_WINDOWS            += -mwindows
QMAKE_LFLAGS_WINDOWS            += -Wl,--subsystem,console

QMAKE_CXXFLAGS                  += -DTRACE_USE -DTRACE_USE_PRINT

QMAKE_LIBS                      = 

RESOURCES                       += images.qrc

TARGET                          = saffron

VERSION                         = "0.0.0"
QMAKE_TARGET_COMPANY            = "Greg Saltis"

QMAKE_TARGET_PRODUCT            = "Saffron"

QMAKE_TARGET_COPYRIGHT          = "Copyright (C) 2022 Greg Saltis"

QT                              += core gui widgets svgwidgets

DEFINES                         += \

SOURCES                         += \
				   DataName.cpp                                 \
				   DataType.cpp                                 \
				   FramesDisplayWindow.cpp                      \
				   MainDisplayWindow.cpp                        \
				   MainSaffronToolBar.cpp                       \
				   MainSaffronWindow.cpp                        \
				   MainSaffronWindowContainer.cpp               \
				   MainWindow.cpp                               \
				   MemberData.cpp                               \
				   MemberDataConfigureDialog.cpp                \
				   MemberDataDisplayWidget.cpp                  \
				   MemberDataMemberEdit.cpp                     \
				   MemberDataResizeMimeData.cpp                 \
				   MemberMethod.cpp                             \
				   MemberMethodFrameStack.cpp                   \
				   MemberMethodParameter.cpp                    \
				   MemberMimeData.cpp                           \
				   Module.cpp                                   \
				   ModuleControlBarWindow.cpp                   \
				   ModuleCreateDialog.cpp                       \
				   ModuleDisplayBaseWindow.cpp                  \
				   ModuleDisplayWidget.cpp                      \
				   ModuleDisplayWindow.cpp                      \
				   ModuleMimeData.cpp                           \
				   ModuleSelectElement.cpp                      \
				   ModuleSelectWindow.cpp                       \
				   Project.cpp                                  \
				   ProjectCreateDialog.cpp                      \
				   ProjectDisplayBodyWindow.cpp                 \
				   ProjectDisplayWindow.cpp                     \
				   ProjectInfo.cpp                              \
				   ProjectInfoList.cpp                          \
				   ProjectOpenDialog.cpp                        \
				   ProjectOpenDialogElement.cpp                 \
				   ProjectOpenDialogFrame.cpp                   \
				   SaffronBaseWindow.cpp                        \
				   SaffronComponent.cpp                         \
				   SaffronComponentColorConfigWindow.cpp        \
				   SaffronComponentColorDialog.cpp              \
				   SaffronComponentDisplayData.cpp              \
				   SaffronComponentDisplayWidget.cpp            \
				   SaffronComponentFill.cpp                     \
				   SaffronComponentFillGradient.cpp             \
				   SaffronComponentFillGradientStop.cpp         \
				   SaffronComponentFillSolid.cpp                \
				   SaffronComponentResizeHandle.cpp             \
				   SaffronComponentResizeWindow.cpp             \
				   SaffronDisplayWindow.cpp                     \
				   SaffronJSON.cpp                              \
				   SaffronSelectWindow.cpp                      \
				   SaffronStatusBar.cpp                         \
				   SaffronToolBarButtonSet.cpp                  \
				   SaffronToolBarButtonWindow.cpp               \
				   SaffronToolBarWindow.cpp                     \
				   SaffronWindowGrid.cpp                        \
				   SaffronWindowGridElement.cpp                 \
				   SaffronWindowHeader.cpp                      \
				   SelectionLabel.cpp                           \
				   SystemConfig.cpp                             \
				   main.cpp                                     \
				   trace.cpp                                    \

HEADERS                         += \
				   DataName.h                                   \
				   DataType.h                                   \
				   FramesDisplayWindow.h                        \
				   MainDisplayWindow.h                          \
				   MainSaffronToolBar.h                         \
				   MainSaffronWindow.h                          \
				   MainSaffronWindowContainer.h                 \
				   MainWindow.h                                 \
				   MemberData.h                                 \
				   MemberDataConfigureDialog.h                  \
				   MemberDataDisplayWidget.h                    \
				   MemberDataMemberEdit.h                       \
				   MemberDataResizeMimeData.h                   \
				   MemberMethod.h                               \
				   MemberMethodFrameStack.h                     \
				   MemberMethodParameter.h                      \
				   MemberMimeData.h                             \
				   Module.h                                     \
				   ModuleControlBarWindow.h                     \
				   ModuleCreateDialog.h                         \
				   ModuleDisplayBaseWindow.h                    \
				   ModuleDisplayWidget.h                        \
				   ModuleDisplayWindow.h                        \
				   ModuleMimeData.h                             \
				   ModuleSelectElement.h                        \
				   ModuleSelectWindow.h                         \
				   Project.h                                    \
				   ProjectCreateDialog.h                        \
				   ProjectDisplayBodyWindow.h                   \
				   ProjectDisplayWindow.h                       \
				   ProjectInfo.h                                \
				   ProjectInfoList.h                            \
				   ProjectOpenDialog.h                          \
				   ProjectOpenDialogElement.h                   \
				   ProjectOpenDialogFrame.h                     \
				   SaffronBaseWindow.h                          \
				   SaffronComponent.h                           \
				   SaffronComponentColorConfigWindow.h          \
				   SaffronComponentColorDialog.h                \
				   SaffronComponentDisplayData.h                \
				   SaffronComponentDisplayWidget.h              \
				   SaffronComponentFill.h                       \
				   SaffronComponentFillGradient.h               \
				   SaffronComponentFillGradientStop.h           \
				   SaffronComponentFillSolid.h                  \
				   SaffronComponentResizeHandle.h               \
				   SaffronComponentResizeWindow.h               \
				   SaffronDisplayWindow.h                       \
				   SaffronJSON.h                                \
				   SaffronSelectWindow.h                        \
				   SaffronStatusBar.h                           \
				   SaffronToolBarButtonSet.h                    \
				   SaffronToolBarButtonWindow.h                 \
				   SaffronToolBarWindow.h                       \
				   SaffronWindowGrid.h                          \
				   SaffronWindowGridElement.h                   \
				   SaffronWindowHeader.h                        \
				   SelectionLabel.h                             \
				   SystemConfig.h                               \
				   trace.h                                      \
				   trace_file.h                                 \
				   trace_net.h                                  \
				   trace_none.h                                 \
				   trace_printf.h                               \

FORMS                           += \

QMAKE_EXTRA_TARGETS             += junkclean
junkclean.target                = junkclean
junkclean.commands              = @echo Removing junk                           \
                                  && rm -rf $(wildcard core* *~)
junkclean.depends               = 

QMAKE_EXTRA_TARGETS             += cleanall
cleanall.target                 = cleanall
cleanall.commands               = rm -rf $(wildcard release/*)                  \
                                  rm -rf $(wildcard debug/*)                    \
                                  rm -rf $(wildcard object_script*)             \
                                  rm -rf Makefile*
                                  
cleanall.depends                = junkclean                                     \
                                  clean                                         \
 
