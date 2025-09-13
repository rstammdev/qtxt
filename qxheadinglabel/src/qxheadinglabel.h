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
    Q_PROPERTY(qreal fontPointSizeFactor READ fontPointSizeFactor WRITE setFontPointSizeFactor NOTIFY fontPropertyChanged)

public:
    explicit QxHeadingLabel(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    explicit QxHeadingLabel(const QString& text, QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    qreal fontPointSizeFactor() const;

public slots:
    void setFontPointSizeFactor(qreal factor);

signals:
    void fontPropertyChanged();

private:
    qreal m_fontPointSizeFactor;
};

#endif // QXHEADINGLABEL_H
