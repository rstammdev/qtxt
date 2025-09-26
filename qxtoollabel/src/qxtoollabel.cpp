/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoollabel.h"


QxToolLabel::QxToolLabel(QWidget* parent, Qt::WindowFlags flags)
    : QLabel{parent, flags}
{

}

QxToolLabel::QxToolLabel(const QString& text, QWidget* parent, Qt::WindowFlags flags)
    : QxToolLabel{parent, flags}
{
    setText(text);
}
