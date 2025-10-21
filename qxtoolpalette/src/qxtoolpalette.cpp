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
    , m_displayMode{DisplayMode::Custom}
{

}

QxToolPalette::QxToolPalette(const QString& title, QWidget* parent, Qt::WindowFlags flags)
    : QxToolPalette{parent, flags}
{
    setWindowTitle(title);
}


QxToolPalette::DisplayMode QxToolPalette::displayMode() const
{
    return m_displayMode;
}

void QxToolPalette::setDisplayMode(const DisplayMode mode)
{
    if (mode == m_displayMode)
        return;

    m_displayMode = mode;

    emit displayModeChanged(m_displayMode);
}
