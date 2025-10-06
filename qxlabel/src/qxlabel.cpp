/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxlabel.h"


QxLabel::QxLabel(QWidget* parent, Qt::WindowFlags flags)
    : QLabel{parent, flags}
{}

QxLabel::QxLabel(const QString& text, QWidget* parent, Qt::WindowFlags flags)
    : QxLabel{parent, flags}
{
    setText(text);
}
