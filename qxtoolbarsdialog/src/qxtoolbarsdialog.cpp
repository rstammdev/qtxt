/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolbarsdialog.h"


QxToolbarsDialog::QxToolbarsDialog(QWidget* parent)
    : QDialog{parent}
{

    setWindowTitle(tr("Configure Toolbars"));
    setMinimumSize(1024, 576);
}
