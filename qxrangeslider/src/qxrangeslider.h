/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXRANGESLIDER_H
#define QXRANGESLIDER_H

#include <QSlider>


class QxRangeSlider : public QSlider
{
    Q_OBJECT

public:
    explicit QxRangeSlider(QWidget* parent = nullptr);
    explicit QxRangeSlider(Qt::Orientation orientation, QWidget* parent = nullptr);
};

#endif // QXRANGESLIDER_H
