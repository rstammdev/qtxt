/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "dialog.h"

#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;


Dialog::Dialog(QWidget* parent)
    : QDialog{parent}
{
    //

    QVBoxLayout* layout = new QVBoxLayout;
    setLayout(layout);

    setWindowTitle("Example of QxDialogHeaderBox"_L1);
    setMinimumSize(320, 240);
}
