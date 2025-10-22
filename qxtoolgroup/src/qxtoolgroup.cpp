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
