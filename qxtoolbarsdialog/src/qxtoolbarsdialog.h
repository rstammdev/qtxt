/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLBARSDIALOG_H
#define QXTOOLBARSDIALOG_H

#include <QDialog>


class QxToolbarsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QxToolbarsDialog(QWidget* parent = nullptr);
    ~QxToolbarsDialog() = default;
};

#endif // QXTOOLBARSDIALOG_H
