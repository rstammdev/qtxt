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

isEmpty(QXCONFIRMATIONBOX_PRI_INCLUDED) {
    QXCONFIRMATIONBOX_PRI_INCLUDED = 1

    QT += core gui widgets

    INCLUDEPATH += \
        $$PWD/src

    HEADERS += \
        $$PWD/src/qxconfirmationbox.h

    SOURCES += \
        $$PWD/src/qxconfirmationbox.cpp

    DISTFILES += \
        $$PWD/README.md
}
