/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXSYSINFO_H
#define QXSYSINFO_H

#include <QSysInfo>


class QxSysInfo : public QSysInfo
{
public:
    static QString buildQtVersion();
};

#endif // QXSYSINFO_H
