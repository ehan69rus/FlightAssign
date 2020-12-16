TARGET = FlightAssignView
TEMPLATE = app
VERSION = 0.1.0

UI_DIR =        .build
MOC_DIR =       .build
OBJECTS_DIR =   .build

DESTDIR = bin

QT       += core gui widgets

HEADERS += \
        src/FlightAssignMainWindow.h

SOURCES += \
        src/main.cpp \
        src/FlightAssignMainWindow.cpp

FORMS += \
        src/FlightAssignMainWindow.ui
