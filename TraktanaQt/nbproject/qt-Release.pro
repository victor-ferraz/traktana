# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux-x86
TARGET = TraktanaQt
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
QT = core gui
SOURCES += MainWindow.cpp USBInterface.cpp main.cpp Program.cpp TraktanaDebug.cpp Traktana.cpp
HEADERS += USBInterface.h TraktanaDebug.h Traktana.h MainWindow.h Program.h
FORMS += MainWindow.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++-4.5
DEFINES += 
INCLUDEPATH += 
LIBS += 
