/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolbarsdialog.h"

#include <QDialogButtonBox>
#include <QVBoxLayout>


QxToolbarsDialog::QxToolbarsDialog(QWidget* parent)
    : QDialog{parent}
{

    // Buttons

    QDialogButtonBox* buttonBox = new QDialogButtonBox;
    buttonBox->addButton(QDialogButtonBox::Ok);
    m_buttonApply = buttonBox->addButton(QDialogButtonBox::Apply);
    buttonBox->addButton(QDialogButtonBox::Cancel);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QxToolbarsDialog::saveAndClose);
    connect(m_buttonApply, &QPushButton::clicked, this, &QxToolbarsDialog::saveAndContinue);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QxToolbarsDialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addStretch();
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle(tr("Configure Toolbars"));
    setMinimumSize(1024, 576);

    m_buttonApply->setEnabled(false);
}


void QxToolbarsDialog::saveAndClose()
{

    accept();
}


void QxToolbarsDialog::saveAndContinue()
{

    m_buttonApply->setEnabled(false);
}
