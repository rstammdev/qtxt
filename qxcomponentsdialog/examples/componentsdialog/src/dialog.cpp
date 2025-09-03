/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "dialog.h"

using namespace Qt::Literals::StringLiterals;

#include <QDialogButtonBox>
#include <QVBoxLayout>


Dialog::Dialog(QWidget* parent)
    : QDialog{parent}
{

    // Button

    QDialogButtonBox* buttonBox = new QDialogButtonBox;
    buttonBox->addButton(QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &Dialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addStretch();
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle("Example of QxComponentsDialog"_L1);
    setMinimumSize(320, 240);
}
