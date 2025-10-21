/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolpalette.h"


QxToolPalette::QxToolPalette(QWidget* parent, Qt::WindowFlags flags)
    : QDockWidget{parent, flags}
{

}

QxToolPalette::QxToolPalette(const QString& title, QWidget* parent, Qt::WindowFlags flags)
    : QxToolPalette{parent, flags}
{
    setWindowTitle(title);
}
