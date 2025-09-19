#
# SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
#
# SPDX-FileCopyrightText: 2025 Ralf Stamm
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

!versionAtLeast(QT_VERSION, 6.8) {
    error("Requires at least Qt 6.8")
}

TEMPLATE = app
TARGET = statusbutton

QT += core gui widgets

CONFIG += qt6 c++23
CONFIG += lrelease
CONFIG += embed_translations

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    src/mainwindow.h

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp

include(../../qxstatusbutton.pri)
