/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXPANELUNIT_H
#define QXPANELUNIT_H

#include <QWidget>


class QxPanelUnit : public QWidget
{
    Q_OBJECT

public:
    explicit QxPanelUnit(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
};

#endif // QXPANELUNIT_H
