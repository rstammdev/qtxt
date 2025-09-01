/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXCONFIRMATIONBOX_H
#define QXCONFIRMATIONBOX_H

#include <QMessageBox>


class QxConfirmationBox : public QMessageBox
{
    Q_OBJECT

public:
    explicit QxConfirmationBox(QWidget* parent = nullptr);
    ~QxConfirmationBox() = default;
};

#endif // QXCONFIRMATIONBOX_H
