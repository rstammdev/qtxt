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
#include <QSettings>
#include <QVBoxLayout>

#include <qxconfirmationbox.h>

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

    // Buttons

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);
    QPushButton* buttonReset = buttonBox->addButton(QDialogButtonBox::Reset);

    connect(buttonReset, &QPushButton::clicked, this, &Dialog::resetSettings);
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
    QMessageBox::StandardButton clicked = QxConfirmationBox::continueCancelWarning(this,
        "Example of QxConfirmationBox"_L1,
        "QxConfirmationBox::continueCancelWarning <strong>with</strong> informative text and key."_L1,
        "Are you sure you want to continue?"_L1,
        "Confirmations/Warning"_L1);

    showResultBox(clicked);
}


void Dialog::showConfirmationBoxCritical()
{
    QMessageBox::StandardButton clicked = QxConfirmationBox::continueCancelCritical(this,
        "Example of QxConfirmationBox"_L1,
        "QxConfirmationBox::continueCancelCritical <strong>without</strong> informative text and key.<br>Are you sure you want to continue?"_L1);

    showResultBox(clicked);
}


void Dialog::showResultBox(QMessageBox::StandardButton clicked)
{
    QString text;

    if (clicked == QMessageBox::Ok)
        text = "QMessageBox::Ok"_L1;
    else if (clicked == QMessageBox::Cancel)
        text = "QMessageBox::Cancel"_L1;
    else if (clicked == QMessageBox::NoButton)
        text = "QMessageBox::NoButton"_L1;
    else
        text = "Unknown"_L1;

    QMessageBox messageBox;
    messageBox.setWindowTitle("Result"_L1);
    messageBox.setText(QString("Standard button <strong>%1</strong> returned").arg(text));
    messageBox.setStandardButtons(QMessageBox::Ok);
    messageBox.setDefaultButton(QMessageBox::Ok);
    messageBox.exec();
}


void Dialog::resetSettings()
{
    QSettings settings;

    settings.clear();
}
