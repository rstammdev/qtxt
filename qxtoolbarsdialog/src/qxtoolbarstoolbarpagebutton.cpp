/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolbarstoolbarpagebutton.h"

#include <QFont>
#include <QLabel>
#include <QVBoxLayout>


QxToolbarsToolbarPageButton::QxToolbarsToolbarPageButton(QToolButton* button, QWidget* parent)
    : QxToolbarsToolbarPage{parent}
    , m_button{button}
{
    QLabel* pageTitle = new QLabel;

    connect(this, &QxToolbarsToolbarPage::pageTitleChanged, pageTitle, &QLabel::setText);



    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(-1, -1, 0, 0);
    layout->addWidget(pageTitle);
    layout->addStretch();
    setLayout(layout);

    QFont fontTitle = pageTitle->font();
    fontTitle.setPointSize(int(fontTitle.pointSizeF() * 1.2));
    fontTitle.setBold(true);
    pageTitle->setFont(fontTitle);
}


void QxToolbarsToolbarPageButton::restoreDefaults(bool current)
{

}


void QxToolbarsToolbarPageButton::save()
{

}
