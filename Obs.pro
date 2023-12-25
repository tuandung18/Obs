TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += qt
QT += core gui
QT += widgets

HEADERS += \
        benutzer.h \
        dozentin.h \
        mainwindow.h \
        obs.h \
        student.h \
        vorlesung.h \
        json.hpp
SOURCES += \
        benutzer.cpp \
        dozentin.cpp \
        main.cpp \
        mainwindow.cpp \
        obs.cpp \
        student.cpp \
        vorlesung.cpp

FORMS += \
    mainwindow.ui

