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
#include <QRadioButton>
#include <QVBoxLayout>


QxToolbarsToolbarPageButton::QxToolbarsToolbarPageButton(QToolButton* button, QWidget* parent)
    : QxToolbarsToolbarPage{parent}
    , m_button{button}
{
    QLabel* pageTitle = new QLabel;

    connect(this, &QxToolbarsToolbarPage::pageTitleChanged, pageTitle, &QLabel::setText);

    // Style

    QRadioButton* buttonIconOnly = new QRadioButton(tr("&Icon Only"));
    buttonIconOnly->setToolTip(tr("Only display the icon."));

    QRadioButton* buttonTextOnly = new QRadioButton(tr("&Text Only"));
    buttonTextOnly->setToolTip(tr("Only display the text."));

    QRadioButton* buttonTextBesideIcon = new QRadioButton(tr("Text &Beside Icon"));
    buttonTextBesideIcon->setToolTip(tr("The text appears beside the icon."));

    QRadioButton* buttonTextUnderIcon = new QRadioButton(tr("Text &Under Icon"));
    buttonTextUnderIcon->setToolTip(tr("The text appears under the icon."));

    QRadioButton* buttonFollowStyle = new QRadioButton(tr("&Follow Style"));
    buttonFollowStyle->setToolTip(tr("Follow the system style."));

    m_buttonsStyle = new QButtonGroup;
    m_buttonsStyle->addButton(buttonIconOnly, Qt::ToolButtonIconOnly);
    m_buttonsStyle->addButton(buttonTextOnly, Qt::ToolButtonTextOnly);
    m_buttonsStyle->addButton(buttonTextBesideIcon, Qt::ToolButtonTextBesideIcon);
    m_buttonsStyle->addButton(buttonTextUnderIcon, Qt::ToolButtonTextUnderIcon);
    m_buttonsStyle->addButton(buttonFollowStyle, Qt::ToolButtonFollowStyle);

    QGridLayout* layoutStyle = new QGridLayout;
    layoutStyle->addWidget(buttonIconOnly, 0, 0);
    layoutStyle->addWidget(buttonTextOnly, 1, 0);
    layoutStyle->addWidget(buttonTextBesideIcon, 0, 1);
    layoutStyle->addWidget(buttonTextUnderIcon, 1, 1);
    layoutStyle->addWidget(buttonFollowStyle, 2, 0, 1, 2);

    QGroupBox* groupStyle = new QGroupBox(tr("Style"));
    groupStyle->setLayout(layoutStyle);

    connect(m_buttonsStyle, &QButtonGroup::buttonToggled, this, &QxToolbarsToolbarPageButton::stateChanged);

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
    layout->addWidget(groupStyle);
    layout->addWidget(groupVisibility);
    layout->addStretch();
    setLayout(layout);

    QFont fontTitle = pageTitle->font();
    fontTitle.setPointSize(int(fontTitle.pointSizeF() * 1.2));
    fontTitle.setBold(true);
    pageTitle->setFont(fontTitle);

    m_buttonsStyle->button(m_button->toolButtonStyle())->setChecked(true);

    m_checkboxVisible->setChecked(m_button->isVisible());

    // TODO: Toolbuttons cannot be hidden
    m_checkboxVisible->setEnabled(false);
}


void QxToolbarsToolbarPageButton::restoreDefaults(bool current)
{
    Q_UNUSED(current)

    m_buttonsStyle->button(Qt::ToolButtonFollowStyle)->setChecked(true);

    m_checkboxVisible->setChecked(true);
}


void QxToolbarsToolbarPageButton::save()
{
    m_button->setToolButtonStyle(static_cast<Qt::ToolButtonStyle>(m_buttonsStyle->checkedId()));

    // TODO: Toolbuttons cannot be hidden
    m_button->setVisible(m_checkboxVisible->isChecked());
}
