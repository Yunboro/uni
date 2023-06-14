GOOGLETEST_DIR = C:/qt/googletest

include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt


HEADERS += \
    bohrung.h \
    delist.h \
    fraesung.h \
    ikomponente.h \
    iterator.h \
    komponente.h \
    komponentenlist.h \
    p01test.h \
    werkstueck.h

SOURCES += \
    P02Main.cpp \
    bohrung.cpp \
    delist.cpp \
    fraesung.cpp \
    ikomponente.cpp \
    iterator.cpp \
    komponente.cpp \
    komponentenlist.cpp \
    werkstueck.cpp
