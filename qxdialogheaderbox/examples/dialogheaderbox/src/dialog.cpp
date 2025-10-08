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


Dialog::Dialog(QWidget* parent)
    : QDialog{parent}
{
    // Header

    QxDialogHeaderBox* headerBoxFull = new QxDialogHeaderBox(this);
    headerBoxFull->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::DialogInformation));
    headerBoxFull->setTitle(tr("DialogHeaderBox"));
    headerBoxFull->setSubTitle(tr("v1.2.3"));
    headerBoxFull->setDescription(tr("This is an example of QxDialogHeaderBox in action."));

    QxDialogHeaderBox* headerBoxTitleDescription = new QxDialogHeaderBox(this);
    headerBoxTitleDescription->setTitle(tr("DialogHeaderBox"));
    headerBoxTitleDescription->setSubTitle(tr("v1.2.3"));
    headerBoxTitleDescription->setDescription(tr("This is an example of QxDialogHeaderBox without an icon."));

    QxDialogHeaderBox* headerBoxTitle = new QxDialogHeaderBox(this);
    headerBoxTitle->setTitle(tr("DialogHeaderBox"));

    // Button

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &Dialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(headerBoxFull);
    layout->addWidget(headerBoxTitleDescription);
    layout->addWidget(headerBoxTitle);
    layout->addStretch();
    layout->addWidget(buttonBox);
    setLayout(layout);

    resize(640, 480);
}
