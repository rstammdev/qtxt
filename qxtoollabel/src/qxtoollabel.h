/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLLABEL_H
#define QXTOOLLABEL_H

#include <QLabel>


class QxToolLabel : public QLabel
{
    Q_OBJECT

public:
    explicit QxToolLabel(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    explicit QxToolLabel(const QString& text, QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    bool fontBold() const;
    bool fontItalic() const;

public slots:
    void setFontBold(const bool enable);
    void setFontItalic(const bool enable);
};

#endif // QXTOOLLABEL_H
