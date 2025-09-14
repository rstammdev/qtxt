#
# SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
#
# SPDX-FileCopyrightText: 2025 Ralf Stamm
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

TEMPLATE = lib
TARGET = libqtxt

!versionAtLeast(QT_VERSION, 6.8): error("Requires at least Qt 6.8")

QT += widgets

include($$PWD/qtxt.pri)
