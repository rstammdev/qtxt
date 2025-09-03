/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxcomponentsdialog.h"


QxComponentsDialog::QxComponentsDialog(QWidget* parent)
    : QDialog{parent}
{

    setWindowTitle(tr("Components"));
    setMinimumSize(640, 240);
}
