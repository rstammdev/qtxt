/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXZOOMBUTTON_H
#define QXZOOMBUTTON_H

#include <QToolButton>


class QxZoomButton : public QToolButton
{
    Q_OBJECT

public:
    explicit QxZoomButton(QWidget* parent = nullptr);
    ~QxZoomButton() = default;
};

#endif // QXZOOMBUTTON_H
