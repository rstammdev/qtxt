/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLBARSDIALOG_H
#define QXTOOLBARSDIALOG_H

#include <QAction>
#include <QDialog>
#include <QPushButton>


class QxToolbarsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QxToolbarsDialog(QWidget* parent = nullptr);
    ~QxToolbarsDialog() = default;

private slots:
    void restoreDefaults();
    void saveAndClose();
    void saveAndContinue();

private:
    QAction* m_actionRestoreDefaultsCurrent;
    QAction* m_actionRestoreDefaultsAll;

    QPushButton* m_buttonApply;
};

#endif // QXTOOLBARSDIALOG_H
