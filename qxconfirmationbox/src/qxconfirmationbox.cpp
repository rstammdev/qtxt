/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxconfirmationbox.h"


QxConfirmationBox::QxConfirmationBox(const QString& key, QWidget* parent)
    : QMessageBox{parent}
    , m_confirmationKey{key}
{

}
