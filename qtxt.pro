#
# SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
#
# SPDX-FileCopyrightText: 2025 Ralf Stamm
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

TEMPLATE = lib
TARGET = libqtxt

!versionAtLeast(QT_VERSION, 6.5): error("Requires at least Qt 6.5")

QT += widgets

include(qxdialogheaderbox/qxdialogheaderbox.pri)
