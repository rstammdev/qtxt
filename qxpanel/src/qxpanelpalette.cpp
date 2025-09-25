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
    , m_paletteDisplayMode{PaletteDisplayMode::NoMode}
    , m_paletteDisplayDirection{QBoxLayout::TopToBottom}
    , m_listUnits{}
{

}

QxPanelPalette::QxPanelPalette(const QString& title, QWidget* parent, Qt::WindowFlags flags)
    : QxPanelPalette{parent, flags}
{
    setWindowTitle(title);
}


QxPanelPalette::PaletteDisplayMode QxPanelPalette::paletteDisplayMode() const
{
    return m_paletteDisplayMode;
}

void QxPanelPalette::setPaletteDisplayMode(const PaletteDisplayMode mode)
{
    if (mode == m_paletteDisplayMode)
        return;

    m_paletteDisplayMode = mode;
    emit paletteDisplayModeChanged(m_paletteDisplayMode);
}


QBoxLayout::Direction QxPanelPalette::paletteDisplayDirection() const
{
    return m_paletteDisplayDirection;
}

void QxPanelPalette::setPaletteDisplayDirection(const QBoxLayout::Direction direction)
{
    if (direction == m_paletteDisplayDirection)
        return;

    m_paletteDisplayDirection = direction;

    emit paletteDisplayDirectionChanged(m_paletteDisplayDirection);
}


int QxPanelPalette::addUnit(QxPanelUnit* unit)
{
    return insertUnit(-1, unit);
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


void QxPanelPalette::removeUnit(const int index)
{
    if (index < 0 || index >= m_listUnits.count())
        return;

    m_listUnits.removeAt(index);
}
