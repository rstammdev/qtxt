/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolbarstoolbarpagebar.h"

#include <QFont>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QList>
#include <QRadioButton>
#include <QSize>
#include <QVBoxLayout>


QxToolbarsToolbarPageBar::QxToolbarsToolbarPageBar(QToolBar* bar, QWidget* parent)
    : QxToolbarsToolbarPage{parent}
    , m_bar{bar}
{
    QLabel* pageTitle = new QLabel;

    connect(this, &QxToolbarsToolbarPage::pageTitleChanged, pageTitle, &QLabel::setText);

    // Icon Size

    QRadioButton* buttonSmall = new QRadioButton(tr("&Small (16)"));
    buttonSmall->setToolTip(tr("Display icons in small size."));

    QRadioButton* buttonMedium = new QRadioButton(tr("&Medium (22)"));
    buttonMedium->setToolTip(tr("Display icons in medium size."));

    QRadioButton* buttonLarge = new QRadioButton(tr("&Large (32)"));
    buttonLarge->setToolTip(tr("Display icons in large size."));

    QRadioButton* buttonHuge = new QRadioButton(tr("&Huge (48)"));
    buttonHuge->setToolTip(tr("Display icons in huge size."));

    QRadioButton* buttonFollowIconSize = new QRadioButton(tr("&Follow Icon Size"));
    buttonFollowIconSize->setToolTip(tr("Follow the system icon size."));

    m_buttonsIconSize = new QButtonGroup;
    m_buttonsIconSize->addButton(buttonSmall, 16);
    m_buttonsIconSize->addButton(buttonMedium, 22);
    m_buttonsIconSize->addButton(buttonLarge, 32);
    m_buttonsIconSize->addButton(buttonHuge, 48);
    m_buttonsIconSize->addButton(buttonFollowIconSize, 0);

    QGridLayout* layoutIconSize = new QGridLayout;
    layoutIconSize->addWidget(buttonSmall, 0, 0);
    layoutIconSize->addWidget(buttonMedium, 0, 1);
    layoutIconSize->addWidget(buttonLarge, 1, 0);
    layoutIconSize->addWidget(buttonHuge, 1, 1);
    layoutIconSize->addWidget(buttonFollowIconSize, 2, 0, 1, 2);

    QGroupBox* groupIconSize = new QGroupBox(tr("Icon Size"));
    groupIconSize->setLayout(layoutIconSize);

    connect(m_buttonsIconSize, &QButtonGroup::buttonToggled, this, &QxToolbarsToolbarPageBar::stateChanged);

    // Visibility

    m_checkboxVisible = new QCheckBox(tr("Is shown"));

    QGridLayout* layoutVisibility = new QGridLayout;
    layoutVisibility->addWidget(m_checkboxVisible);

    QGroupBox* groupVisibility = new QGroupBox(tr("Visibility"));
    groupVisibility->setLayout(layoutVisibility);

    connect(m_checkboxVisible, &QCheckBox::checkStateChanged, this, &QxToolbarsToolbarPageBar::stateChanged);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(-1, -1, 0, 0);
    layout->addWidget(pageTitle);
    layout->addWidget(groupIconSize);
    layout->addWidget(groupVisibility);
    layout->addStretch();
    setLayout(layout);

    QFont fontTitle = pageTitle->font();
    fontTitle.setPointSize(int(fontTitle.pointSizeF() * 1.2));
    fontTitle.setBold(true);
    pageTitle->setFont(fontTitle);

    const QList<int> ids{16, 22, 32, 48};
    const int id = ids.contains(m_bar->iconSize().height()) ? m_bar->iconSize().height() : 0;
    m_buttonsIconSize->button(id)->setChecked(true);

    m_checkboxVisible->setChecked(m_bar->isVisible());
}


void QxToolbarsToolbarPageBar::restoreDefaults(bool current)
{
    Q_UNUSED(current)

    m_buttonsIconSize->button(0)->setChecked(true);

    m_checkboxVisible->setChecked(true);
}


void QxToolbarsToolbarPageBar::save()
{
    QSize size = QSize(-1, -1);
    if (m_buttonsIconSize->checkedId() > 0)
        size = QSize(m_buttonsIconSize->checkedId(), m_buttonsIconSize->checkedId());
    m_bar->setIconSize(size);

    m_bar->setVisible(m_checkboxVisible->isChecked());
}
