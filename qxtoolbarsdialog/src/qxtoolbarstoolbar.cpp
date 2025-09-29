/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolbarstoolbar.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QTreeWidget>

#include "qxtoolbarstoolbarpage.h"
#include "qxtoolbarstoolbarpagebar.h"
#include "qxtoolbarstoolbarpagebutton.h"
#include "qxtoolbarstoolbarpagelabel.h"
#include "qxtoolbarstoolbarpageseparator.h"

using namespace Qt::Literals::StringLiterals;


QxToolbarsToolbar::QxToolbarsToolbar(QToolBar* toolbar, QWidget* parent)
    : QWidget{parent}
{
    // Pages

    QTreeWidget* treePages = new QTreeWidget;
    treePages->setHeaderHidden(true);
    treePages->setRootIsDecorated(false);

    m_stackedPages = new QStackedWidget;

    QxToolbarsToolbarPageBar* pageBar = new QxToolbarsToolbarPageBar(toolbar, this);
    pageBar->setPageTitle(toolbar->windowTitle());

    QTreeWidgetItem* treeItemRoot = new QTreeWidgetItem(treePages);
    treeItemRoot->setText(0, pageBar->pageTitle());
    treeItemRoot->setData(0, Qt::UserRole, m_stackedPages->addWidget(pageBar));
    treePages->expandItem(treeItemRoot);

    connect(pageBar, &QxToolbarsToolbarPage::stateChanged, this, &QxToolbarsToolbar::stateChanged);
    connect(this, &QxToolbarsToolbar::restoreDefaultsRequested, pageBar, &QxToolbarsToolbarPage::restoreDefaults);
    connect(this, &QxToolbarsToolbar::saveRequested, pageBar, &QxToolbarsToolbarPage::save);

    for (QAction* action : toolbar->actions()) {

        if (QWidget* widget = toolbar->widgetForAction(action)) {

            QTreeWidgetItem* treeItemBranch = new QTreeWidgetItem(treeItemRoot);
            treePages->expandItem(treeItemBranch);

            if (!action->isSeparator()) {

                if (QToolButton* button = qobject_cast<QToolButton*>(widget)) {

                    QxToolbarsToolbarPageButton* pageButton = new QxToolbarsToolbarPageButton(button, this);
                    pageButton->setPageTitle(button->text().replace("&&"_L1, "&"_L1));

                    treeItemBranch->setText(0, pageButton->pageTitle());
                    treeItemBranch->setData(0, Qt::UserRole, m_stackedPages->addWidget(pageButton));

                    connect(pageButton, &QxToolbarsToolbarPage::stateChanged, this, &QxToolbarsToolbar::stateChanged);
                    connect(this, &QxToolbarsToolbar::restoreDefaultsRequested, pageButton, &QxToolbarsToolbarPage::restoreDefaults);
                    connect(this, &QxToolbarsToolbar::saveRequested, pageButton, &QxToolbarsToolbarPage::save);
                }
                else if (QLabel* label = qobject_cast<QLabel*>(widget)) {

                    QxToolbarsToolbarPageLabel* pageLabel = new QxToolbarsToolbarPageLabel(label, this);
                    pageLabel->setPageTitle(label->text().replace("&&"_L1, "&"_L1));

                    treeItemBranch->setText(0, pageLabel->pageTitle());
                    treeItemBranch->setData(0, Qt::UserRole, m_stackedPages->addWidget(pageLabel));

                    connect(pageLabel, &QxToolbarsToolbarPage::stateChanged, this, &QxToolbarsToolbar::stateChanged);
                    connect(this, &QxToolbarsToolbar::restoreDefaultsRequested, pageLabel, &QxToolbarsToolbarPage::restoreDefaults);
                    connect(this, &QxToolbarsToolbar::saveRequested, pageLabel, &QxToolbarsToolbarPage::save);
                }
            }
            else {

                QxToolbarsToolbarPageSeparator* pageSeparator = new QxToolbarsToolbarPageSeparator(action, this);
                pageSeparator->setPageTitle(tr("--- separator ---"));

                treeItemBranch->setText(0, pageSeparator->pageTitle());
                treeItemBranch->setData(0, Qt::UserRole, m_stackedPages->addWidget(pageSeparator));

                connect(pageSeparator, &QxToolbarsToolbarPage::stateChanged, this, &QxToolbarsToolbar::stateChanged);
                connect(this, &QxToolbarsToolbar::restoreDefaultsRequested, pageSeparator, &QxToolbarsToolbarPage::restoreDefaults);
                connect(this, &QxToolbarsToolbar::saveRequested, pageSeparator, &QxToolbarsToolbarPage::save);
            }
        }
    }

    connect(treePages, &QTreeWidget::currentItemChanged, this, &QxToolbarsToolbar::setCurrentPage);

    //

    QHBoxLayout* layout = new QHBoxLayout;
    layout->setContentsMargins(QMargins());
    layout->addWidget(treePages, 1);
    layout->addWidget(m_stackedPages, 2);
    setLayout(layout);

    treePages->setCurrentItem(treePages->topLevelItem(0));
}


void QxToolbarsToolbar::setCurrentPage(QTreeWidgetItem* current)
{
    if (current)
        m_stackedPages->setCurrentIndex(current->data(0, Qt::UserRole).toInt());
}


void QxToolbarsToolbar::restoreDefaults(bool current)
{
    if (current && m_stackedPages->currentWidget())
        qobject_cast<QxToolbarsToolbarPage*>(m_stackedPages->currentWidget())->restoreDefaults(true);
    else
        emit restoreDefaultsRequested(false);
}
