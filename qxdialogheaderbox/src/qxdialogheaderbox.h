/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXDIALOGHEADERBOX_H
#define QXDIALOGHEADERBOX_H

#include <QWidget>


class QxDialogHeaderBox : public QWidget
{
    Q_OBJECT

public:
    explicit QxDialogHeaderBox(QWidget* parent = nullptr);
    ~QxDialogHeaderBox() = default;
};

#endif // QXDIALOGHEADERBOX_H
