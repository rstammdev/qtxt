#
# SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
#
# SPDX-FileCopyrightText: 2025 Ralf Stamm
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

isEmpty(QXDIALOGHEADERBOX_PRI_INCLUDED) {
    QXDIALOGHEADERBOX_PRI_INCLUDED = 1

    QT += widgets

    INCLUDEPATH += \
        $$PWD/src

    HEADERS += \
        $$PWD/src/qxdialogheaderbox.h

    SOURCES += \
        $$PWD/src/qxdialogheaderbox.cpp
}
