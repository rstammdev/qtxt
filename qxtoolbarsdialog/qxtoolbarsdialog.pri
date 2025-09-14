#
# SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
#
# SPDX-FileCopyrightText: 2025 Ralf Stamm
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

isEmpty(QXTOOLBARSDIALOG_PRI_INCLUDED) {
    QXTOOLBARSDIALOG_PRI_INCLUDED = 1

    QT += widgets

    INCLUDEPATH += \
        $$PWD/src

    HEADERS += \
        $$PWD/src/qxtoolbarsdialog.h \
        $$PWD/src/qxtoolbarstoolbar.h \
        $$PWD/src/qxtoolbarstoolbarpage.h \
        $$PWD/src/qxtoolbarstoolbarpagebar.h \
        $$PWD/src/qxtoolbarstoolbarpagebutton.h \
        $$PWD/src/qxtoolbarstoolbarpageseparator.h

    SOURCES += \
        $$PWD/src/qxtoolbarsdialog.cpp \
        $$PWD/src/qxtoolbarstoolbar.cpp \
        $$PWD/src/qxtoolbarstoolbarpage.cpp \
        $$PWD/src/qxtoolbarstoolbarpagebar.cpp \
        $$PWD/src/qxtoolbarstoolbarpagebutton.cpp \
        $$PWD/src/qxtoolbarstoolbarpageseparator.cpp

    DISTFILES += \
        $$PWD/README.md
}
