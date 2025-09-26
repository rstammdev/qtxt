/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoollabel.h"

#include <QFont>
#include <QMargins>
#include <QStyle>
#include <QStyleOptionToolButton>


QxToolLabel::QxToolLabel(QWidget* parent, Qt::WindowFlags flags)
    : QLabel{parent, flags}
{
    QStyleOptionToolButton option;
    option.initFrom(this);

    QMargins margins = style()->pixelMetric(QStyle::PM_ToolBarItemMargin, &option, this) * QMargins( 1, 1, 1, 1);
    setContentsMargins(margins);

    setAlignment(Qt::AlignCenter);
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
