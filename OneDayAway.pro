#-------------------------------------------------
#
# Project created by QtCreator 2013-02-13T13:01:21
#
#-------------------------------------------------

QT += core gui

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = OneDayAway
TEMPLATE = app

RC_FILE = icon.rc

SOURCES +=\
        item.cpp \
    command.cpp \
    command_words.cpp \
    engine.cpp \
    game_main.cpp \
    game_window.cpp \
    start_window.cpp \
    room.cpp \
    player.cpp

HEADERS  += \
        item.h \
    command_words.h \
    command.h \
    engine.h \
    game_window.h \
    start_window.h \
    room.h \
    player.h

FORMS    += \
        gamewindow.ui \
    startwindow.ui

OTHER_FILES += \
    ToDo.txt \
    Features.txt

RESOURCES += \
    Resources.qrc
