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
    , m_spanning{false}
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
    if (count < 0 || count == m_columnCount)
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
    if (count < 0 || count == m_rowCount)
        return;

    m_rowCount = count;

    emit rowCountChanged(m_rowCount);
}


bool QxToolPalette::isSpanning() const
{
    return m_spanning;
}

void QxToolPalette::setSpanning(const bool enable)
{
    if (enable == m_spanning)
        return;

    m_spanning = enable;

    emit spanningChanged(m_spanning);
}


int QxToolPalette::addGroup(QxToolGroup* group)
{
    return insertGroup(-1, group);
}


int QxToolPalette::insertGroup(const int index, QxToolGroup* group)
{
    if (index < -1 || !group)
        return -1;

    group->setParent(this);

    if (index >= 0 && index < m_groups.size())
        m_groups.insert(index, group);
    else
        m_groups.append(group);

    return m_groups.indexOf(group);
}
