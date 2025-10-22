/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLGROUP_H
#define QXTOOLGROUP_H

#include <QIcon>
#include <QWidget>


class QxToolGroup : public QWidget
{
    Q_OBJECT

public:
    explicit QxToolGroup(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
};

#endif // QXTOOLGROUP_H
