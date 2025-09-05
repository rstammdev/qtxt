/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLBARSTOOLBAR_H
#define QXTOOLBARSTOOLBAR_H

#include <QToolBar>
#include <QWidget>


class QxToolbarsToolbar : public QWidget
{
    Q_OBJECT

public:
    explicit QxToolbarsToolbar(QToolBar* toolbar, QWidget* parent = nullptr);
    ~QxToolbarsToolbar() = default;

public slots:
    void restoreDefaults(bool current);

signals:
    void stateChanged();
};

#endif // QXTOOLBARSTOOLBAR_H
