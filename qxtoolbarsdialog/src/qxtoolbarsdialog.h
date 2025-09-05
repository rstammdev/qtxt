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
#include <QPushButton>


class QxToolbarsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QxToolbarsDialog(QWidget* parent = nullptr);
    ~QxToolbarsDialog() = default;

private slots:
    void saveAndContinue();

private:
    QPushButton* m_buttonApply;
};

#endif // QXTOOLBARSDIALOG_H
