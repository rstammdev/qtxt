/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxcomponentsdialog.h"

#include <QApplication>
#include <QClipboard>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QVBoxLayout>


QxComponentsDialog::QxComponentsDialog(QWidget* parent)
    : QDialog{parent}
{
    // Text

    m_textBox = new QPlainTextEdit;
    m_textBox->setFocusPolicy(Qt::NoFocus);
    m_textBox->setReadOnly(true);

    // Buttons

    QPushButton* buttonCopyToClipboard = new QPushButton(tr("Copy to Clipboard"));
    buttonCopyToClipboard->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::EditCopy));

    QDialogButtonBox* buttonBox = new QDialogButtonBox;
    buttonBox->addButton(buttonCopyToClipboard, QDialogButtonBox::ActionRole);
    buttonBox->addButton(QDialogButtonBox::Close);

    connect(buttonCopyToClipboard, &QPushButton::clicked, this, &QxComponentsDialog::copyToClipboard);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QxComponentsDialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(m_textBox);
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle(tr("Components"));
    setMinimumSize(640, 240);
}


void QxComponentsDialog::copyToClipboard()
{
    if (!m_textBox->toPlainText().isEmpty())
        QApplication::clipboard()->setText(m_textBox->toPlainText());
}
