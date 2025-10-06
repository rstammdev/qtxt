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

    QxLabel* labelBold = new QxLabel(tr("Bold Font Style"));
    labelBold->setFontBold(true);

    QxLabel* labelItalic = new QxLabel(tr("Italic Font Style"));
    labelItalic->setFontItalic(true);

    QxLabel* labelUnderline = new QxLabel(tr("Underline Font Style"));
    labelUnderline->setFontUnderline(true);

    QxLabel* labelLarge = new QxLabel(tr("Large Font Style"));
    labelLarge->setFontPointSizeF(labelLarge->fontPointSizeF() * 1.2);

    // Button

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &Dialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(labelDefault);
    layout->addWidget(labelBold);
    layout->addWidget(labelItalic);
    layout->addWidget(labelUnderline);
    layout->addWidget(labelLarge);
    layout->addStretch();
    layout->addWidget(buttonBox);

    resize(640, 480);
}
