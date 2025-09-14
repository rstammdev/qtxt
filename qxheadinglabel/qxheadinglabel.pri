#
# SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
#
# SPDX-FileCopyrightText: 2025 Ralf Stamm
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

isEmpty(QXHEADINGLABEL_PRI_INCLUDED) {
    QXHEADINGLABEL_PRI_INCLUDED = 1

    QT += widgets

    INCLUDEPATH += \
        $$PWD/src

    HEADERS += \
        $$PWD/src/qxheadinglabel.h

    SOURCES += \
        $$PWD/src/qxheadinglabel.cpp
}
