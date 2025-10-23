/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolgroup.h"

#include <QToolButton>


QxToolGroup::QxToolGroup(QWidget* parent, Qt::WindowFlags flags)
    : QWidget{parent, flags}
    , m_type{Type::NoBox}
    , m_title{}
    , m_columnCount{}
    , m_rowCount{}
    , m_spanning{false}
{

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

    return m_widgets.indexOf(widget);
}


bool QxToolGroup::removeWidget(const int index)
{
    if (index < 0 || index >= m_widgets.size())
        return false;

    m_widgets.removeAt(index);

    return true;
}


int QxToolGroup::widgetCount()
{
    return m_widgets.size();
}


int QxToolGroup::addAction(QAction* action)
{
    QToolButton* button = new QToolButton;
    button->setDefaultAction(action);
    button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    return addWidget(button);
}


void QxToolGroup::addActions(const QList<QAction*>& actions)
{
    for (QAction* action : actions)
        addAction(action);
}
