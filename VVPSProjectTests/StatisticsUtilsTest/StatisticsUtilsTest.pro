QT += testlib
QT -= gui

QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../VVPSProject

HEADERS += ../../VVPSProject/statisticsutils.h
SOURCES += ../../VVPSProject/statisticsutils.cpp   \
           tst_statisticsutilstest.cpp
