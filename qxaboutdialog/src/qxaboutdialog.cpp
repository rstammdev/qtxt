/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxaboutdialog.h"

#include <QApplication>
#include <QVBoxLayout>


QxAboutDialog::QxAboutDialog(QWidget* parent, Qt::WindowFlags flags)
    : QDialog{parent, flags}
{
    // Header

    m_headerBox = new QxDialogHeaderBox;
    if (!QApplication::applicationName().isEmpty())
        m_headerBox->setTitle(QApplication::applicationName());
    if (!QApplication::applicationVersion().isEmpty())
        m_headerBox->setSubTitle(tr("v%1").arg(QApplication::applicationVersion()));

    // Tabs

    m_tabBox = new QTabWidget;

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(m_headerBox);
    layout->addWidget(m_tabBox);
    setLayout(layout);
}


QxDialogHeaderBox* QxAboutDialog::header() const
{
    return m_headerBox;
}


QTabWidget* QxAboutDialog::tabs() const
{
    return m_tabBox;
}
