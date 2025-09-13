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
    Q_PROPERTY(bool fontBold READ isFontBold WRITE setFontBold NOTIFY fontPropertyChanged)

public:
    explicit QxHeadingLabel(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    explicit QxHeadingLabel(const QString& text, QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    qreal fontPointSizeFactor() const;
    bool isFontBold() const;

public slots:
    void setFontPointSizeFactor(qreal factor);
    void setFontBold(bool enable);

signals:
    void fontPropertyChanged();

private:
    qreal m_fontPointSizeFactor;
    bool m_fontBold;

    qreal m_fontDefaultPointSize;
};

#endif // QXHEADINGLABEL_H
