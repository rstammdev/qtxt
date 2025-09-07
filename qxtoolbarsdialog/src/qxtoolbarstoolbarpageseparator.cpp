/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoolbarstoolbarpageseparator.h"


QxToolbarsToolbarPageSeparator::QxToolbarsToolbarPageSeparator(QAction* separator, QWidget* parent)
    : QxToolbarsToolbarPage{parent}
    , m_separator{separator}
{

}


void QxToolbarsToolbarPageSeparator::restoreDefaults(bool current)
{
    Q_UNUSED(current)

}
