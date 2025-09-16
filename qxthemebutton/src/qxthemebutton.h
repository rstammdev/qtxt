/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTHEMEBUTTON_H
#define QXTHEMEBUTTON_H

#include <QToolButton>


class QxThemeButton : public QToolButton
{
    Q_OBJECT

public:
    explicit QxThemeButton(QWidget* parent = nullptr);
};

#endif // QXTHEMEBUTTON_H
