TEMPLATE = app
TARGET = polyomino

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp \
    polyominos.cpp \
    drawPolyCanvas.cpp

HEADERS += \
    window.h \
    polyominos.h \
    drawPolyCanvas.h
