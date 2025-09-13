/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxheadinglabel.h"


QxHeadingLabel::QxHeadingLabel(QWidget* parent, Qt::WindowFlags flags)
    : QLabel{parent, flags}
{

}

QxHeadingLabel::QxHeadingLabel(const QString& text, QWidget* parent, Qt::WindowFlags flags)
    : QxHeadingLabel{parent, flags}
{
    setText(text);
}
