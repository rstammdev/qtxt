/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>


class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget* parent = nullptr);
    ~Dialog() = default;

private slots:
    void showConfirmationBoxWarning();
    void showConfirmationBoxCritical();
};

#endif // DIALOG_H
