/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxsysinfo.h"

#include <QApplication>


QString QxSysInfo::buildQtVersion()
{
    return QT_VERSION_STR;
}


QString QxSysInfo::currentQtVersion()
{
    return qVersion();
}
