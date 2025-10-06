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

#include <qxlabel.h>


Dialog::Dialog(QWidget* parent)
    : QDialog{parent}
{
    // Labels

    QxLabel* labelDefault = new QxLabel(tr("Default Style"));

    // Button

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &Dialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(labelDefault);
    layout->addStretch();
    layout->addWidget(buttonBox);

    resize(640, 480);
}
