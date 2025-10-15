/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxsysinfo.h"

#include <QApplication>

using namespace Qt::Literals::StringLiterals;


QString QxSysInfo::buildQtVersion()
{
    return QT_VERSION_STR;
}


QString QxSysInfo::currentQtVersion()
{
    return qVersion();
}


QString QxSysInfo::prettyPlatformName()
{
    const QString& platformName = QApplication::platformName();

    if (platformName == "wayland"_L1)
        return "Wayland"_L1;
    else if (platformName == "xcb"_L1)
        return "X11"_L1;

    return QCoreApplication::translate("qxsysinfo", "Unknown (%1)").arg(platformName);
}
