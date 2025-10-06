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
