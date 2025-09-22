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
    , m_displayMode{DisplayMode::NoMode}
    , m_listUnits{}
{

}

QxPanelPalette::QxPanelPalette(const QString& title, QWidget* parent, Qt::WindowFlags flags)
    : QxPanelPalette{parent, flags}
{
    setWindowTitle(title);
}


QxPanelPalette::DisplayMode QxPanelPalette::displayMode() const
{
    return m_displayMode;
}

void QxPanelPalette::setDisplayMode(const DisplayMode mode)
{
    if (mode == m_displayMode)
        return;

    m_displayMode = mode;
    emit displayModeChanged(m_displayMode);
}


int QxPanelPalette::insertUnit(int index, QxPanelUnit* unit)
{
    if (index < -1 || index >= m_listUnits.count() || !unit)
        return -1;

    if (index >= 0)
        m_listUnits.insert(index, unit);
    else
        m_listUnits.append(unit);

    return m_listUnits.indexOf(unit);
}
