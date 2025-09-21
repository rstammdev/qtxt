/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxpanelpalette.h"


QxPanelPalette::QxPanelPalette(QWidget* parent, Qt::WindowFlags flags)
    : QDockWidget{parent, flags}
{

}

QxPanelPalette::QxPanelPalette(const QString& title, QWidget* parent, Qt::WindowFlags flags)
    : QxPanelPalette{parent, flags}
{
    setWindowTitle(title);
}
