/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxdialogheaderbox.h"


QxDialogHeaderBox::QxDialogHeaderBox(QWidget* parent)
    : QWidget{parent}
{

}


QIcon QxDialogHeaderBox::icon() const
{
    return m_icon;
}

void QxDialogHeaderBox::setIcon(const QIcon& icon)
{
    if (icon.cacheKey() == m_icon.cacheKey())
        return;

    m_icon = icon;
    emit changed();
}
