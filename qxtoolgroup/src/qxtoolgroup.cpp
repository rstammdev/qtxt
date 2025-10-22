/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolgroup.h"


QxToolGroup::QxToolGroup(QWidget* parent, Qt::WindowFlags flags)
    : QWidget{parent, flags}
    , m_type{Type::NoBox}
    , m_title{}
    , m_columnCount{}
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
