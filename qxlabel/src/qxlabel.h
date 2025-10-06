/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXLABEL_H
#define QXLABEL_H

#include <QLabel>


class QxLabel : public QLabel
{
    Q_OBJECT

public:
    explicit QxLabel(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    explicit QxLabel(const QString& text, QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    bool fontBold() const;

public slots:
    void setFontBold(const bool enable);
};

#endif // QXLABEL_H
