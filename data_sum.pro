TEMPLATE = app
TARGET = data_sum

QT = core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp \
    data.cpp

HEADERS += \
    window.h \
    data.h

DISTFILES += \
    data/numbers.csv
