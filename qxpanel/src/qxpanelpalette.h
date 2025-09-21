/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXPANELPALETTE_H
#define QXPANELPALETTE_H

#include <QDockWidget>


class QxPanelPalette : public QDockWidget
{
    Q_OBJECT

public:
    explicit QxPanelPalette(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    explicit QxPanelPalette(const QString& text, QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
};

#endif // QXPANELPALETTE_H
