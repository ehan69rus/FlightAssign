TARGET = FlightAssignCoreLib
TEMPLATE = lib
VERSION = 0.1.0

UI_DIR =        .build
MOC_DIR =       .build
OBJECTS_DIR =   .build

DESTDIR = lib

QT -= gui
QT += sql

SOURCES += \
    src/FlightAssignDataManager.cpp \
    src/FlightAssignDatabaseManager.cpp \
    src/FlightAssignAirdrome.cpp \
    src/FlightAssignClaim.cpp \
    src/FlightAssignDestination.cpp \
    src/FlightAssignBaseItem.cpp

HEADERS += \
    src/FlightAssignDataManager.h \
    src/FlightAssignDatabaseManager.h \
    src/FlightAssignAirdrome.h \
    src/FlightAssignClaim.h \
    src/FlightAssignDestination.h \
    src/FlightAssignBaseItem.h

headers.files = $$HEADERS
headers.path = ~/usr/include/FlightAssignCore

target.path = ~/usr/lib

INSTALLS += target \
            headers
