/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "dialog.h"

#include <QDialogButtonBox>
#include <QVBoxLayout>

#include <qxdialogheaderbox.h>

using namespace Qt::Literals::StringLiterals;


Dialog::Dialog(QWidget* parent)
    : QDialog{parent}
{
    // Header

    QxDialogHeaderBox* headerBox = new QxDialogHeaderBox(this);
    headerBox->setTitle("DialogHeaderBox"_L1);
    headerBox->setSubTitle("v1.2.3"_L1);
    headerBox->setDescription("This is an example of QxDialogHeaderBox in action."_L1);
    headerBox->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::DialogInformation));

    // Button

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &Dialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(headerBox);
    layout->addStretch();
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle("Example of QxDialogHeaderBox"_L1);
    setMinimumSize(320, 240);
}
