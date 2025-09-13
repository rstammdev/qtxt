/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "dialog.h"

#include <QDialogButtonBox>
#include <QLabel>
#include <QVBoxLayout>

#include <qxheadinglabel.h>


Dialog::Dialog(QWidget* parent)
    : QDialog{parent}
{
    // Labels

    QxHeadingLabel* headingLabel = new QxHeadingLabel(tr("QxHeadingLabel"));

    QxHeadingLabel* headingLabelLarger = new QxHeadingLabel(tr("QxHeadingLabel Larger Font Size"));
    headingLabelLarger->setFontPointSizeFactor(1.4);

    QxHeadingLabel* headingLabelNormal = new QxHeadingLabel(tr("QxHeadingLabel Normal Font Size & Weight"));
    headingLabelNormal->setFontPointSizeFactor(1.0);
    headingLabelNormal->setFontBold(false);

    QLabel* label = new QLabel(tr("QLabel"));

    QLabel* labelRichText = new QLabel(tr("<strong style=\"font-size: large;\">QLabel Rich Text</strong>"));

    // Button

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &Dialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(headingLabel);
    layout->addWidget(headingLabelLarger);
    layout->addWidget(headingLabelNormal);
    layout->addWidget(label);
    layout->addWidget(labelRichText);
    layout->addStretch();
    layout->addWidget(buttonBox);

    setMinimumSize(640, 480);
}
