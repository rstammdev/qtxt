/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolbarstoolbarpage.h"


QxToolbarsToolbarPage::QxToolbarsToolbarPage(QWidget* parent)
    : QWidget{parent}
{}


QString QxToolbarsToolbarPage::pageTitle() const
{
    return m_pageTitle;
}

void QxToolbarsToolbarPage::setPageTitle(const QString& title)
{
    if (title == m_pageTitle)
        return;

    m_pageTitle = title;

    emit pageTitleChanged(m_pageTitle);
}
