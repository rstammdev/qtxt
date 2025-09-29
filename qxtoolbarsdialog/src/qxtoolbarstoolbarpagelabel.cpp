/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolbarstoolbarpagelabel.h"

#include <QVBoxLayout>

#include <qxheadinglabel.h>


QxToolbarsToolbarPageLabel::QxToolbarsToolbarPageLabel(QLabel* label, QWidget* parent)
    : QxToolbarsToolbarPage{parent}
    , m_label{label}
{
    QxHeadingLabel* pageTitle = new QxHeadingLabel;

    connect(this, &QxToolbarsToolbarPage::pageTitleChanged, pageTitle, &QxHeadingLabel::setText);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(-1, -1, 0, 0);
    layout->addWidget(pageTitle);
    layout->addStretch();
    setLayout(layout);
}


void QxToolbarsToolbarPageLabel::restoreDefaults(bool current)
{
    Q_UNUSED(current)
}
