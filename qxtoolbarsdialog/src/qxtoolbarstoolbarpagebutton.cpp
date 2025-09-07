/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolbarstoolbarpagebutton.h"

#include <QFont>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>


QxToolbarsToolbarPageButton::QxToolbarsToolbarPageButton(QToolButton* button, QWidget* parent)
    : QxToolbarsToolbarPage{parent}
    , m_button{button}
{
    QLabel* pageTitle = new QLabel;

    connect(this, &QxToolbarsToolbarPage::pageTitleChanged, pageTitle, &QLabel::setText);



    // Visibility

    m_checkboxVisible = new QCheckBox(tr("Is shown"));

    QGridLayout* layoutVisibility = new QGridLayout;
    layoutVisibility->addWidget(m_checkboxVisible);

    QGroupBox* groupVisibility = new QGroupBox(tr("Visibility"));
    groupVisibility->setLayout(layoutVisibility);

    connect(m_checkboxVisible, &QCheckBox::checkStateChanged, this, &QxToolbarsToolbarPageButton::stateChanged);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(-1, -1, 0, 0);
    layout->addWidget(pageTitle);
    layout->addWidget(groupVisibility);
    layout->addStretch();
    setLayout(layout);

    QFont fontTitle = pageTitle->font();
    fontTitle.setPointSize(int(fontTitle.pointSizeF() * 1.2));
    fontTitle.setBold(true);
    pageTitle->setFont(fontTitle);

    m_checkboxVisible->setChecked(m_button->isVisible());

    // TODO: Toolbuttons cannot be hidden
    m_checkboxVisible->setEnabled(false);
}


void QxToolbarsToolbarPageButton::restoreDefaults(bool current)
{
    Q_UNUSED(current)

    m_checkboxVisible->setChecked(true);
}


void QxToolbarsToolbarPageButton::save()
{

    // TODO: Toolbuttons cannot be hidden
    m_button->setVisible(m_checkboxVisible->isChecked());
}
