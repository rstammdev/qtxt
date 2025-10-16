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

    QFormLayout* layoutSysInfo = new QFormLayout;
    layoutSysInfo->addRow(tr("Build Qt Version:"), new QLabel(QxSysInfo::buildQtVersion()));
    layoutSysInfo->addRow(tr("Current Qt Version:"), new QLabel(QxSysInfo::currentQtVersion()));
    layoutSysInfo->addRow(tr("Pretty Product Name:"), new QLabel(QxSysInfo::prettyProductName()));
    layoutSysInfo->addRow(tr("Pretty Platform Name:"), new QLabel(QxSysInfo::prettyPlatformName()));
    layoutSysInfo->addRow(tr("Current CPU Architecture:"), new QLabel(QxSysInfo::currentCpuArchitecture()));
    layoutSysInfo->addRow(tr("Build Architecture String:"), new QLabel(QxSysInfo::buildAbi()));
    layoutSysInfo->addRow(tr("Kernel Type:"), new QLabel(QxSysInfo::kernelType()));
    layoutSysInfo->addRow(tr("Kernel Version:"), new QLabel(QxSysInfo::kernelVersion()));

    // Button

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &Dialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(layoutSysInfo);
    layout->addStretch();
    layout->addWidget(buttonBox);
    setLayout(layout);

    resize(640, 480);
}
