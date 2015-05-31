# -------------------------------------------------
# Project created by QtCreator 2015-03-31T17:12:51
# -------------------------------------------------
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mu0
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    apprendre.cpp \
    test.cpp \
    aide.cpp

HEADERS += mainwindow.h \
    apprendre.h \
    test.h \
    aide.h

FORMS += ui/mainwindow.ui \
    ui/apprendre.ui \
    ui/test.ui \
    ui/aide.ui

RESOURCES += schema.qrc