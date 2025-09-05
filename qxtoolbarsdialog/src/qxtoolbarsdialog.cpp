/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolbarsdialog.h"

#include <QActionGroup>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QList>
#include <QListWidget>
#include <QMenu>
#include <QToolBar>
#include <QToolButton>
#include <QVBoxLayout>

#include "qxtoolbarstoolbar.h"

using namespace Qt::Literals::StringLiterals;


QxToolbarsDialog::QxToolbarsDialog(QWidget* parent)
    : QDialog{parent}
{
    // Pages

    QListWidget* listPages = new QListWidget;

    m_stackedPages = new QStackedWidget;

    const QList<QToolBar*> toolbars = parent->findChildren<QToolBar*>();
    for (const auto toolbar : toolbars) {

        listPages->addItem(toolbar->windowTitle());

        QxToolbarsToolbar* toolbarsToolbar = new QxToolbarsToolbar(toolbar, this);
        m_stackedPages->addWidget(toolbarsToolbar);
    }

    QHBoxLayout* layoutPageBox = new QHBoxLayout;
    layoutPageBox->addWidget(listPages, 1);
    layoutPageBox->addWidget(m_stackedPages, 3);

    connect(listPages, &QListWidget::currentRowChanged, m_stackedPages, &QStackedWidget::setCurrentIndex);

    // Buttons

    QToolButton* buttonRestoreDefaults = new QToolButton;
    buttonRestoreDefaults->setText(tr("&Defaults"));
    buttonRestoreDefaults->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentRevert));
    buttonRestoreDefaults->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QActionGroup* actionsRestoreDefaults = new QActionGroup(buttonRestoreDefaults);

    m_actionRestoreDefaultsCurrent = new QAction(tr("Restore this &page only"), actionsRestoreDefaults);
    m_actionRestoreDefaultsCurrent->setCheckable(true);
    actionsRestoreDefaults->addAction(m_actionRestoreDefaultsCurrent);

    m_actionRestoreDefaultsAll = new QAction(tr("Restore &all settings"), actionsRestoreDefaults);
    m_actionRestoreDefaultsAll->setCheckable(true);
    actionsRestoreDefaults->addAction(m_actionRestoreDefaultsAll);

    QMenu* menuRestoreDefaults = new QMenu(buttonRestoreDefaults);
    menuRestoreDefaults->addActions(actionsRestoreDefaults->actions());

    buttonRestoreDefaults->setMenu(menuRestoreDefaults);
    buttonRestoreDefaults->setPopupMode(QToolButton::MenuButtonPopup);

    QDialogButtonBox* buttonBox = new QDialogButtonBox;
    buttonBox->addButton(buttonRestoreDefaults, QDialogButtonBox::ResetRole);
    buttonBox->addButton(QDialogButtonBox::Ok);
    m_buttonApply = buttonBox->addButton(QDialogButtonBox::Apply);
    buttonBox->addButton(QDialogButtonBox::Cancel);

    connect(buttonRestoreDefaults, &QToolButton::clicked, this, &QxToolbarsDialog::restoreDefaults);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QxToolbarsDialog::saveAndClose);
    connect(m_buttonApply, &QPushButton::clicked, this, &QxToolbarsDialog::saveAndContinue);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QxToolbarsDialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(layoutPageBox);
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle(tr("Configure Toolbars"));
    setMinimumSize(1024, 576);

    listPages->setCurrentRow(0);

    m_actionRestoreDefaultsCurrent->setChecked(true);

    m_buttonApply->setEnabled(false);
}


void QxToolbarsDialog::restoreDefaults()
{

    m_actionRestoreDefaultsCurrent->setChecked(true);
}


void QxToolbarsDialog::saveAndClose()
{

    accept();
}


void QxToolbarsDialog::saveAndContinue()
{

    m_buttonApply->setEnabled(false);
}
