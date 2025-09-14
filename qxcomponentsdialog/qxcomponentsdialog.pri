#
# SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
#
# SPDX-FileCopyrightText: 2025 Ralf Stamm
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

isEmpty(QXCOMPONENTSDIALOG_PRI_INCLUDED) {
    QXCOMPONENTSDIALOG_PRI_INCLUDED = 1

    QT += widgets

    INCLUDEPATH += \
        $$PWD/src

    HEADERS += \
        $$PWD/src/qxcomponentsdialog.h

    SOURCES += \
        $$PWD/src/qxcomponentsdialog.cpp

    DISTFILES += \
        $$PWD/README.md
}
