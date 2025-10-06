/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxlabel.h"

#include <QFont>


QxLabel::QxLabel(QWidget* parent, Qt::WindowFlags flags)
    : QLabel{parent, flags}
{}

QxLabel::QxLabel(const QString& text, QWidget* parent, Qt::WindowFlags flags)
    : QxLabel{parent, flags}
{
    setText(text);
}


bool QxLabel::fontBold() const
{
    return font().bold();
}

void QxLabel::setFontBold(const bool enable)
{
    QFont font = this->font();
    font.setBold(enable);
    setFont(font);
}


bool QxLabel::fontItalic() const
{
    return font().italic();
}

void QxLabel::setFontItalic(const bool enable)
{
    QFont font = this->font();
    font.setItalic(enable);
    setFont(font);
}


bool QxLabel::fontStrikeOut() const
{
    return font().strikeOut();
}

void QxLabel::setFontStrikeOut(const bool enable)
{
    QFont font = this->font();
    font.setStrikeOut(enable);
    setFont(font);
}


bool QxLabel::fontUnderline() const
{
    return font().underline();
}

void QxLabel::setFontUnderline(const bool enable)
{
    QFont font = this->font();
    font.setUnderline(enable);
    setFont(font);
}


int QxLabel::fontPixelSize() const
{
    return font().pixelSize();
}

void QxLabel::setFontPixelSize(const int size)
{
    QFont font = this->font();
    font.setPixelSize(size);
    setFont(font);
}


int QxLabel::fontPointSize() const
{
    return font().pointSize();
}

void QxLabel::setFontPointSize(const int size)
{
    QFont font = this->font();
    font.setPointSize(size);
    setFont(font);
}


qreal QxLabel::fontPointSizeF() const
{
    return font().pointSizeF();
}

void QxLabel::setFontPointSizeF(const qreal size)
{
    QFont font = this->font();
    font.setPointSizeF(size);
    setFont(font);
}
