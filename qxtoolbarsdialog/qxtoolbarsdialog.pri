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

isEmpty(QXTOOLBARSDIALOG_PRI_INCLUDED) {
    QXTOOLBARSDIALOG_PRI_INCLUDED = 1

    QT += core gui widgets

    CONFIG += qt6 c++23

    INCLUDEPATH += \
        $$PWD/src

    HEADERS += \
        $$PWD/src/qxtoolbarsdialog.h \
        $$PWD/src/qxtoolbarstoolbar.h \
        $$PWD/src/qxtoolbarstoolbarpage.h \
        $$PWD/src/qxtoolbarstoolbarpagebar.h \
        $$PWD/src/qxtoolbarstoolbarpagebutton.h \
        $$PWD/src/qxtoolbarstoolbarpagelabel.h \
        $$PWD/src/qxtoolbarstoolbarpageseparator.h

    SOURCES += \
        $$PWD/src/qxtoolbarsdialog.cpp \
        $$PWD/src/qxtoolbarstoolbar.cpp \
        $$PWD/src/qxtoolbarstoolbarpage.cpp \
        $$PWD/src/qxtoolbarstoolbarpagebar.cpp \
        $$PWD/src/qxtoolbarstoolbarpagebutton.cpp \
        $$PWD/src/qxtoolbarstoolbarpagelabel.cpp \
        $$PWD/src/qxtoolbarstoolbarpageseparator.cpp

    DISTFILES += \
        $$PWD/README.md

    include($$PWD/../qxlabel/qxlabel.pri)
}
