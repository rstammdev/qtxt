/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXSTATUSBUTTON_H
#define QXSTATUSBUTTON_H

#include <QToolButton>


class QxStatusButton : public QToolButton
{
    Q_OBJECT

public:
    explicit QxStatusButton(QWidget* parent = nullptr);
};

#endif // QXSTATUSBUTTON_H
