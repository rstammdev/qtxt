/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolgroup.h"

#include <QFrame>
#include <QGridLayout>
#include <QLayoutItem>
#include <QToolButton>


QxToolGroup::QxToolGroup(QWidget* parent, Qt::WindowFlags flags)
    : QWidget{parent, flags}
    , m_type{Type::NoBox}
    , m_title{}
    , m_columnCount{}
    , m_rowCount{}
    , m_spanning{false}
{
    setLayout(new QGridLayout);
}


QxToolGroup::Type QxToolGroup::type() const
{
    return m_type;
}

void QxToolGroup::setType(const QxToolGroup::Type type)
{
    if (type == m_type)
        return;

    m_type = type;

    emit typeChanged(m_type);
}


QString QxToolGroup::title() const
{
    return m_title;
}

void QxToolGroup::setTitle(const QString& title)
{
    if (title == m_title)
        return;

    m_title = title;

    emit titleChanged(m_title);
}


int QxToolGroup::columnCount() const
{
    return m_columnCount;
}

void QxToolGroup::setColumnCount(const int count)
{
    if (count < 0 || count == m_columnCount)
        return;

    m_columnCount = count;

    rebuildLayout();

    emit columnCountChanged(m_columnCount);
}


int QxToolGroup::rowCount() const
{
    return m_rowCount;
}

void QxToolGroup::setRowCount(const int count)
{
    if (count < 0 || count == m_rowCount)
        return;

    m_rowCount = count;

    rebuildLayout();

    emit rowCountChanged(m_rowCount);
}


bool QxToolGroup::isSpanning() const
{
    return m_spanning;
}

void QxToolGroup::setSpanning(const bool enable)
{
    if (enable == m_spanning)
        return;

    m_spanning = enable;

    rebuildLayout();

    emit spanningChanged(m_spanning);
}


int QxToolGroup::addWidget(QWidget* widget)
{
    return insertWidget(-1, widget);
}


int QxToolGroup::insertWidget(const int index, QWidget* widget)
{
    if (index < -1 || !widget)
        return -1;

    widget->setParent(this);

    if (index >= 0 && index < m_widgets.size())
        m_widgets.insert(index, widget);
    else
        m_widgets.append(widget);

    rebuildLayout();

    return m_widgets.indexOf(widget);
}


bool QxToolGroup::removeWidget(const int index)
{
    if (index < 0 || index >= m_widgets.size())
        return false;

    m_widgets.removeAt(index);

    rebuildLayout();

    return true;
}


QList<QWidget*> QxToolGroup::widgets() const
{
    return m_widgets;
}


int QxToolGroup::widgetCount()
{
    return m_widgets.size();
}


void QxToolGroup::addActions(const QList<QAction*>& actions)
{
    for (QAction* action : actions)
        addAction(action);
}


int QxToolGroup::addAction(QAction* action)
{
    return insertAction(-1, action);
}


int QxToolGroup::insertAction(const int index, QAction* action)
{
    if (index < -1 || !action)
        return -1;

    QToolButton* button = new QToolButton;
    button->setDefaultAction(action);
    button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    return insertWidget(index, button);
}


int QxToolGroup::addSeparator(const Qt::Orientation orientation)
{
    return insertSeparator(-1, orientation);
}


int QxToolGroup::insertSeparator(const int index, const Qt::Orientation orientation)
{
    if (index < -1)
        return -1;

    QFrame* frameLine = new QFrame;
    frameLine->setFrameShape((orientation == Qt::Vertical) ? QFrame::VLine : QFrame::HLine);
    frameLine->setFrameShadow(QFrame::Sunken);

    return insertWidget(index, frameLine);
}


void QxToolGroup::rebuildLayout()
{
    QGridLayout* layout = qobject_cast<QGridLayout*>(this->layout());
    if (!layout)
        return;

    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr)
        delete item;

    const int maxWidgets = m_widgets.size();
    const int maxColumns = (m_columnCount == 0) ? maxWidgets : m_columnCount;
    const int maxRows = (m_rowCount == 0) ? (maxWidgets + maxColumns - 1) / maxColumns : m_rowCount;
    const int maxCells = (maxColumns == 0 || maxRows == 0) ? maxWidgets : maxColumns * maxRows;
    const int lastColumnSpan = (m_spanning) ? maxColumns * maxRows - maxWidgets + 1 : 1;

    const int count = qMin(maxWidgets, maxCells);
    for (int i = 0; i < count; ++i) {

        const int row = (maxColumns > 0) ? (i / maxColumns) : i;
        const int column = (maxColumns > 0) ? (i % maxColumns) : 0;
        const int rowSpan = 1;
        const int columnSpan = (i == count - 1) ? lastColumnSpan : 1;

        layout->addWidget(m_widgets[i], row, column, rowSpan, columnSpan);
        m_widgets[i]->show();
    }
    for (int i = count; i < maxWidgets; ++i)
        m_widgets[i]->hide();
}
