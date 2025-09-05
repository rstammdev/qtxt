/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolbarstoolbar.h"

#include <QHBoxLayout>
#include <QTreeWidget>


QxToolbarsToolbar::QxToolbarsToolbar(QToolBar* toolbar, QWidget* parent)
    : QWidget{parent}
{
    // Pages

    QTreeWidget* treePages = new QTreeWidget;
    treePages->setHeaderHidden(true);
    treePages->setRootIsDecorated(false);

    m_stackedPages = new QStackedWidget;

    QTreeWidgetItem* treeItemRoot = new QTreeWidgetItem(treePages);
    treeItemRoot->setText(0, toolbar->windowTitle());
    treeItemRoot->setData(0, Qt::UserRole, m_stackedPages->addWidget(new QWidget));
    treePages->expandItem(treeItemRoot);



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

}
