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

include(qxcomponentsdialog/qxcomponentsdialog.pri)
include(qxconfirmationbox/qxconfirmationbox.pri)
include(qxdialogheaderbox/qxdialogheaderbox.pri)
include(qxheadinglabel/qxheadinglabel.pri)
include(qxtoolbarsdialog/qxtoolbarsdialog.pri)
include(qxzoombutton/qxzoombutton.pri)
