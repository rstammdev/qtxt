/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "dialog.h"

#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;


Dialog::Dialog(QWidget* parent)
    : QDialog{parent}
{
    QPushButton* buttonWarning = new QPushButton("Warning"_L1);
    QPushButton* buttonCritical = new QPushButton("Critical"_L1);

    QHBoxLayout* layoutButtons = new QHBoxLayout;
    layoutButtons->addWidget(buttonWarning);
    layoutButtons->addWidget(buttonCritical);

    connect(buttonWarning, &QPushButton::clicked, this, &Dialog::showConfirmationBoxWarning);
    connect(buttonCritical, &QPushButton::clicked, this, &Dialog::showConfirmationBoxCritical);

    // Button

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &Dialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addStretch();
    layout->addLayout(layoutButtons);
    layout->addStretch();
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle("Example of QxConfirmationBox"_L1);
    setMinimumSize(320, 240);
}


void Dialog::showConfirmationBoxWarning()
{

}


void Dialog::showConfirmationBoxCritical()
{

}
