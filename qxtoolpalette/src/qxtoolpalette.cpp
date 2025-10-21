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
    , m_columnCount{1}
    , m_rowCount{}
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


int QxToolPalette::columnCount() const
{
    return m_columnCount;
}

void QxToolPalette::setColumnCount(const int count)
{
    if (count == m_columnCount)
        return;

    m_columnCount = count;

    emit columnCountChanged(m_columnCount);
}


int QxToolPalette::rowCount() const
{
    return m_rowCount;
}

void QxToolPalette::setRowCount(const int count)
{
    if (count == m_rowCount)
        return;

    m_rowCount = count;

    emit rowCountChanged(m_rowCount);
}
