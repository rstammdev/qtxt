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


QString QxDialogHeaderBox::title() const
{
    return m_title;
}

void QxDialogHeaderBox::setTitle(const QString& title)
{
    if (title == m_title)
        return;

    m_title = title;
    emit changed();
}


QString QxDialogHeaderBox::subTitle() const
{
    return m_subTitle;
}

void QxDialogHeaderBox::setSubTitle(const QString& subTitle)
{
    if (subTitle == m_subTitle)
        return;

    m_subTitle = subTitle;
    emit changed();
}


QString QxDialogHeaderBox::description() const
{
    return m_description;
}

void QxDialogHeaderBox::setDescription(const QString& description)
{
    if (description == m_description)
        return;

    m_description = description;
    emit changed();
}
