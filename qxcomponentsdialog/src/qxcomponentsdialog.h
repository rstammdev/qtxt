/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXCOMPONENTSDIALOG_H
#define QXCOMPONENTSDIALOG_H

#include <QDialog>


class QxComponentsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QxComponentsDialog(QWidget* parent = nullptr);
    ~QxComponentsDialog() = default;
};

#endif // QXCOMPONENTSDIALOG_H
