/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLBARSTOOLBARPAGE_H
#define QXTOOLBARSTOOLBARPAGE_H

#include <QWidget>


class QxToolbarsToolbarPage : public QWidget
{
    Q_OBJECT

public:
    explicit QxToolbarsToolbarPage(QWidget* parent = nullptr);
    ~QxToolbarsToolbarPage() = default;
};

#endif // QXTOOLBARSTOOLBARPAGE_H
