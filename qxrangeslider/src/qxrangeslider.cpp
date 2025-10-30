/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxrangeslider.h"


QxRangeSlider::QxRangeSlider(QWidget* parent)
    : QxRangeSlider{Qt::Vertical, parent}
{}

QxRangeSlider::QxRangeSlider(Qt::Orientation orientation, QWidget* parent)
    : QSlider{orientation, parent}
{

}
