/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoollabel.h"

#include <QFont>


QxToolLabel::QxToolLabel(QWidget* parent, Qt::WindowFlags flags)
    : QLabel{parent, flags}
{

}

QxToolLabel::QxToolLabel(const QString& text, QWidget* parent, Qt::WindowFlags flags)
    : QxToolLabel{parent, flags}
{
    setText(text);
}


bool QxToolLabel::fontBold() const
{
    return font().bold();
}

void QxToolLabel::setFontBold(const bool enable)
{
    QFont font = this->font();
    font.setBold(enable);

    setFont(font);
}


bool QxToolLabel::fontItalic() const
{
    return font().italic();
}

void QxToolLabel::setFontItalic(const bool enable)
{
    QFont font = this->font();
    font.setItalic(enable);

    setFont(font);
}


bool QxToolLabel::fontUnderline() const
{
    return font().underline();
}

void QxToolLabel::setFontUnderline(const bool enable)
{
    QFont font = this->font();
    font.setUnderline(enable);

    setFont(font);
}
