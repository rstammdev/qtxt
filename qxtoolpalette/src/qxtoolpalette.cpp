/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolpalette.h"

#include <QGridLayout>
#include <QLayoutItem>


QxToolPalette::QxToolPalette(QWidget* parent, Qt::WindowFlags flags)
    : QDockWidget{parent, flags}
    , m_displayMode{DisplayMode::Custom}
    , m_columnCount{1}
    , m_rowCount{}
    , m_spanning{false}
{
    QWidget* widget = new QWidget;
    widget->setLayout(new QGridLayout);
    setWidget(widget);
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

    rebuildLayout();

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

    rebuildLayout();

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

    rebuildLayout();

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

    rebuildLayout();

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

    rebuildLayout();

    return m_groups.indexOf(group);
}


bool QxToolPalette::removeGroup(const int index)
{
    if (index < 0 || index >= m_groups.size())
        return false;

    m_groups.removeAt(index);

    rebuildLayout();

    return true;
}


int QxToolPalette::groupCount()
{
    return m_groups.size();
}


void QxToolPalette::rebuildLayout()
{
    QGridLayout* layout = qobject_cast<QGridLayout*>(widget()->layout());
    if (!layout)
        return;

    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item;
    }

    const int maxGroups = m_groups.size();
    const int maxColumns = (m_columnCount == 0) ? maxGroups : m_columnCount;
    const int maxRows = (m_rowCount == 0) ? (maxGroups + maxColumns - 1) / maxColumns : m_rowCount;
    const int maxCells = (maxColumns == 0 || maxRows == 0) ? maxGroups : maxColumns * maxRows;
    const int lastColumnSpan = (m_spanning) ? maxColumns * maxRows - maxGroups + 1 : 1;

    const int count = qMin(maxGroups, maxCells);
    for (int i = 0; i < count; ++i) {

        const int row = (maxColumns > 0) ? (i / maxColumns) : i;
        const int column = (maxColumns > 0) ? (i % maxColumns) : 0;
        const int rowSpan = 1;
        const int columnSpan = (i == count - 1) ? lastColumnSpan : 1;

        layout->addWidget(m_groups[i], row, column, rowSpan, columnSpan);
        m_groups[i]->show();
    }
    for (int i = count; i < maxGroups; ++i)
        m_groups[i]->hide();
}
