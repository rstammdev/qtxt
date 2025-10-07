/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLLABEL_H
#define QXTOOLLABEL_H

#include <qxlabel.h>


class QxToolLabel : public QxLabel
{
    Q_OBJECT

public:
    explicit QxToolLabel(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    explicit QxToolLabel(const QString& text, QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
};

#endif // QXTOOLLABEL_H
