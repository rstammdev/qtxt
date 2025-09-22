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
    , m_unitDisplayMode{UnitDisplayMode::NoBox}
    , m_unitTitle{}
{

}


QxPanelUnit::UnitDisplayMode QxPanelUnit::unitDisplayMode() const
{
    return m_unitDisplayMode;
}

void QxPanelUnit::setUnitDisplayMode(const UnitDisplayMode mode)
{
    if (mode == m_unitDisplayMode)
        return;

    m_unitDisplayMode = mode;
    emit unitDisplayModeChanged(m_unitDisplayMode);
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
