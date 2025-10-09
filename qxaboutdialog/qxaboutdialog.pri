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

isEmpty(QXABOUTDIALOG_PRI_INCLUDED) {
    QXABOUTDIALOG_PRI_INCLUDED = 1

    QT += core gui widgets

    CONFIG += qt6 c++23

    INCLUDEPATH += \
        $$PWD/src

    HEADERS += \
        $$PWD/src/qxaboutdialog.h

    SOURCES += \
        $$PWD/src/qxaboutdialog.cpp

    DISTFILES += \
        $$PWD/README.md
}
