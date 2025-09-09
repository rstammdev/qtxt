#
# SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
#
# SPDX-FileCopyrightText: 2025 Ralf Stamm
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

TEMPLATE = app
TARGET = zoombutton

!versionAtLeast(QT_VERSION, 6.5): error("Requires at least Qt 6.5")

QT += core gui widgets

CONFIG += c++23
CONFIG += lrelease
CONFIG += embed_translations

DEFINES += QT_DEPRECATED_WARNINGS

include(../../qxzoombutton.pri)

HEADERS += \
    src/mainwindow.h

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp
