/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLBARSTOOLBARPAGEBAR_H
#define QXTOOLBARSTOOLBARPAGEBAR_H

#include "qxtoolbarstoolbarpage.h"

#include <QWidget>


class QxToolbarsToolbarPageBar : public QxToolbarsToolbarPage
{
    Q_OBJECT

public:
    explicit QxToolbarsToolbarPageBar(QWidget* parent = nullptr);
    ~QxToolbarsToolbarPageBar() = default;
};

#endif // QXTOOLBARSTOOLBARPAGEBAR_H
