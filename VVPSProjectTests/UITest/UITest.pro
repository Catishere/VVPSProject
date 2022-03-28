QT += testlib gui widgets

QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

# QXlsx code for Application Qt project
QXLSX_PARENTPATH=../../VVPSProject         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=../../VVPSProject/header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=../../VVPSProject/source/  # current QXlsx source path is ./source/
include(../../VVPSProject/QXlsx.pri)

INCLUDEPATH += ../../VVPSProject

HEADERS += ../../VVPSProject/mainwindow.h \
           ../../VVPSProject/statisticsutils.h \
           ../../VVPSProject/xlsxutils.h

SOURCES += ../../VVPSProject/mainwindow.cpp \
           ../../VVPSProject/statisticsutils.cpp \
           ../../VVPSProject/xlsxutils.cpp \
           tst_uitest.cpp

FORMS += \
    ../../VVPSProject/mainwindow.ui
