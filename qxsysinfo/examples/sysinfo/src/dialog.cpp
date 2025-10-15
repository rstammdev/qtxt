/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "dialog.h"

#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLabel>
#include <QVBoxLayout>

#include <qxsysinfo.h>


Dialog::Dialog(QWidget* parent)
    : QDialog{parent}
{
    // System information

    QLabel* buildQtVersion = new QLabel(QxSysInfo::buildQtVersion());

    QLabel* currentQtVersion = new QLabel(QxSysInfo::currentQtVersion());

    QLabel* prettyProductName = new QLabel(QxSysInfo::prettyProductName());

    QLabel* prettyPlatformName = new QLabel(QxSysInfo::prettyPlatformName());

    QLabel* currentCpuArchitecture = new QLabel(QxSysInfo::currentCpuArchitecture());

    QFormLayout* layoutSysInfo = new QFormLayout;
    layoutSysInfo->addRow(tr("Build Qt Version:"), buildQtVersion);
    layoutSysInfo->addRow(tr("Current Qt Version:"), currentQtVersion);
    layoutSysInfo->addRow(tr("Pretty Product Name:"), prettyProductName);
    layoutSysInfo->addRow(tr("Pretty Platform Name:"), prettyPlatformName);
    layoutSysInfo->addRow(tr("Current CPU Architecture:"), currentCpuArchitecture);

    // Button

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &Dialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(layoutSysInfo);
    layout->addStretch();
    layout->addWidget(buttonBox);
    setLayout(layout);

    layoutSysInfo->setHorizontalSpacing(layoutSysInfo->horizontalSpacing() * 2);

    resize(640, 480);
}
