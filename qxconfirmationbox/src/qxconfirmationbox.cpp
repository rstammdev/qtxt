/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxconfirmationbox.h"


QMessageBox::StandardButton QxConfirmationBox::continueCancel(QWidget* parent, const Icon icon, const QString& title, const QString& text, const QString& informativeText, const QString& key)
{

    return QMessageBox::NoButton;
}


QxConfirmationBox::QxConfirmationBox(const QString& key, QWidget* parent)
    : QMessageBox{parent}
    , m_confirmationKey{key}
{

}
