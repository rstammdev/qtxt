/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxtoollabel.h"

#include <QMargins>
#include <QStyle>
#include <QStyleOptionToolButton>


QxToolLabel::QxToolLabel(QWidget* parent, Qt::WindowFlags flags)
    : QxLabel{parent, flags}
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
