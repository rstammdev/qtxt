/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolbarstoolbarpagelabel.h"

#include <QGridLayout>
#include <QGroupBox>
#include <QVBoxLayout>

#include <qxlabel.h>


QxToolbarsToolbarPageLabel::QxToolbarsToolbarPageLabel(QLabel* label, QWidget* parent)
    : QxToolbarsToolbarPage{parent}
    , m_label{label}
{
    QxLabel* pageTitle = new QxLabel;
    pageTitle->setFontBold(true);
    pageTitle->setFontPointSizeF(pageTitle->fontPointSize() * 1.2);

    connect(this, &QxToolbarsToolbarPage::pageTitleChanged, pageTitle, &QxLabel::setText);

    // Visibility

    m_checkboxVisible = new QCheckBox(tr("Is shown"));

    QGridLayout* layoutVisibility = new QGridLayout;
    layoutVisibility->addWidget(m_checkboxVisible);

    QGroupBox* groupVisibility = new QGroupBox(tr("Visibility"));
    groupVisibility->setLayout(layoutVisibility);

    connect(m_checkboxVisible, &QCheckBox::checkStateChanged, this, &QxToolbarsToolbarPageLabel::stateChanged);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(-1, -1, 0, 0);
    layout->addWidget(pageTitle);
    layout->addWidget(groupVisibility);
    layout->addStretch();
    setLayout(layout);

    m_checkboxVisible->setChecked(m_label->isVisible());

    // TODO: Toolbuttons cannot be hidden
    m_checkboxVisible->setEnabled(false);
}


void QxToolbarsToolbarPageLabel::restoreDefaults(bool current)
{
    Q_UNUSED(current)

    m_checkboxVisible->setChecked(true);
}


void QxToolbarsToolbarPageLabel::save()
{
    m_label->setVisible(m_checkboxVisible->isChecked());
}
