#
# SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
#
# SPDX-FileCopyrightText: 2025 Ralf Stamm
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

isEmpty(QXZOOMBUTTON_PRI_INCLUDED) {
    QXZOOMBUTTON_PRI_INCLUDED = 1

    QT += widgets

    INCLUDEPATH += \
        $$PWD/src

    HEADERS += \
        $$PWD/src/qxzoombutton.h

    SOURCES += \
        $$PWD/src/qxzoombutton.cpp

    DISTFILES += \
        $$PWD/README.md
}
