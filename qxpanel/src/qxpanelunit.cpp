/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxpanelunit.h"


QxPanelUnit::QxPanelUnit(QWidget* parent, Qt::WindowFlags flags)
    : QWidget{parent, flags}
    , m_unitType{UnitType::NoType}
    , m_unitTitle{}
    , m_unitDescription{}
{}


QxPanelUnit::UnitType QxPanelUnit::unitType() const
{
    return m_unitType;
}

void QxPanelUnit::setUnitType(const UnitType type)
{
    if (type == m_unitType)
        return;

    m_unitType = type;
    emit unitTypeChanged(m_unitType);
}


QString QxPanelUnit::unitTitle() const
{
    return m_unitTitle;
}

void QxPanelUnit::setUnitTitle(const QString& title)
{
    if (title == m_unitTitle)
        return;

    m_unitTitle = title;
    emit unitTitleChanged(m_unitTitle);
}


QString QxPanelUnit::unitDescription() const
{
    return m_unitDescription;
}

void QxPanelUnit::setUnitDescription(const QString& description)
{
    if (description == m_unitDescription)
        return;

    m_unitDescription = description;
    emit unitDescriptionChanged(m_unitDescription);
}
