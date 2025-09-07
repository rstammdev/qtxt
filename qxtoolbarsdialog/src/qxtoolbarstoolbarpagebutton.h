/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLBARSTOOLBARPAGEBUTTON_H
#define QXTOOLBARSTOOLBARPAGEBUTTON_H

#include "qxtoolbarstoolbarpage.h"

#include <QWidget>


class QxToolbarsToolbarPageButton : public QxToolbarsToolbarPage
{
    Q_OBJECT

public:
    explicit QxToolbarsToolbarPageButton(QWidget* parent = nullptr);
    ~QxToolbarsToolbarPageButton() = default;
};

#endif // QXTOOLBARSTOOLBARPAGEBUTTON_H
