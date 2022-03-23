QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# QXlsx code for Application Qt project
QXLSX_PARENTPATH=../../VVPSProject         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=../../VVPSProject/header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=../../VVPSProject/source/  # current QXlsx source path is ./source/
include(../../VVPSProject/QXlsx.pri)

INCLUDEPATH += ../../VVPSProject

HEADERS += ../../VVPSProject/xlsxutils.h
SOURCES += ../../VVPSProject/xlsxutils.cpp   \
           tst_xlsxutilstest.cpp

RESOURCES += \
    resource.qrc

DISTFILES +=
