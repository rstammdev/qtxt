/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxcomponentsdialog.h"

#include <QDialogButtonBox>
#include <QVBoxLayout>


QxComponentsDialog::QxComponentsDialog(QWidget* parent)
    : QDialog{parent}
{
    // Text

    m_textBox = new QPlainTextEdit;
    m_textBox->setFocusPolicy(Qt::NoFocus);
    m_textBox->setReadOnly(true);

    // Button

    QDialogButtonBox* buttonBox = new QDialogButtonBox;
    buttonBox->addButton(QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &QxComponentsDialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(m_textBox);
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle(tr("Components"));
    setMinimumSize(640, 240);
}
