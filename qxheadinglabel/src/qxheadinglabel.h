/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXHEADINGLABEL_H
#define QXHEADINGLABEL_H

#include <QLabel>


class QxHeadingLabel : public QLabel
{
    Q_OBJECT

public:
    explicit QxHeadingLabel(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
};

#endif // QXHEADINGLABEL_H
