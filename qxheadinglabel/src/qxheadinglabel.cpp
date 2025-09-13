/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxheadinglabel.h"

#include <QFont>


QxHeadingLabel::QxHeadingLabel(QWidget* parent, Qt::WindowFlags flags)
    : QLabel{parent, flags}
    , m_fontPointSizeFactor{1.2}
    , m_fontBold{true}
    , m_fontDefaultPointSize{font().pointSizeF()}
{

}

QxHeadingLabel::QxHeadingLabel(const QString& text, QWidget* parent, Qt::WindowFlags flags)
    : QxHeadingLabel{parent, flags}
{
    setText(text);
}


qreal QxHeadingLabel::fontPointSizeFactor() const
{
    return m_fontPointSizeFactor;
}

void QxHeadingLabel::setFontPointSizeFactor(qreal factor)
{
    if (factor == m_fontPointSizeFactor)
        return;

    m_fontPointSizeFactor = factor;
    emit fontPropertyChanged();
}


bool QxHeadingLabel::isFontBold() const
{
    return m_fontBold;
}

void QxHeadingLabel::setFontBold(bool enable)
{
    if (enable == m_fontBold)
        return;

    m_fontBold = enable;
    emit fontPropertyChanged();
}
