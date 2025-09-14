#
# SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
#
# SPDX-FileCopyrightText: 2025 Ralf Stamm
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

isEmpty(QXCONFIRMATIONBOX_PRI_INCLUDED) {
    QXCONFIRMATIONBOX_PRI_INCLUDED = 1

    QT += widgets

    INCLUDEPATH += \
        $$PWD/src

    HEADERS += \
        $$PWD/src/qxconfirmationbox.h

    SOURCES += \
        $$PWD/src/qxconfirmationbox.cpp

    DISTFILES += \
        $$PWD/README.md
}
