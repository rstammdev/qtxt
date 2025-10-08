/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxdialogheaderbox.h"

#include <QFontMetrics>
#include <QGridLayout>


QxDialogHeaderBox::QxDialogHeaderBox(QWidget* parent, Qt::WindowFlags flags)
    : QWidget{parent, flags}
{
    m_labelIcon = new QLabel;
    m_labelIcon->setAlignment(Qt::AlignmentFlag::AlignCenter);
    m_labelIcon->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_labelTitle = new QLabel;
    m_labelTitle->setAlignment(Qt::AlignmentFlag::AlignLeading | Qt::AlignmentFlag::AlignBottom);
    m_labelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    m_labelDescription = new QLabel;
    m_labelDescription->setAlignment(Qt::AlignmentFlag::AlignLeading | Qt::AlignmentFlag::AlignTop);
    m_labelDescription->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    //

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(m_labelIcon, 0, 0, 2, 1);
    layout->addWidget(m_labelTitle, 0, 1);
    layout->addWidget(m_labelDescription, 1, 1);
    layout->setColumnStretch(1, 1);
    layout->setHorizontalSpacing(layout->horizontalSpacing() * 2);
    setLayout(layout);
}


QIcon QxDialogHeaderBox::icon() const
{
    return m_icon;
}

void QxDialogHeaderBox::setIcon(const QIcon& icon)
{
    if (icon.cacheKey() == m_icon.cacheKey())
        return;

    m_icon = icon;

    updateLayout();

    emit changed();
}


QString QxDialogHeaderBox::title() const
{
    return m_title;
}

void QxDialogHeaderBox::setTitle(const QString& title)
{
    if (title == m_title)
        return;

    m_title = title;

    updateLayout();

    emit changed();
}


QString QxDialogHeaderBox::subTitle() const
{
    return m_subTitle;
}

void QxDialogHeaderBox::setSubTitle(const QString& subTitle)
{
    if (subTitle == m_subTitle)
        return;

    m_subTitle = subTitle;

    updateLayout();

    emit changed();
}


QString QxDialogHeaderBox::description() const
{
    return m_description;
}

void QxDialogHeaderBox::setDescription(const QString& description)
{
    if (description == m_description)
        return;

    m_description = description;

    updateLayout();

    emit changed();
}


void QxDialogHeaderBox::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    QFontMetrics fm(m_labelDescription->font());
    m_labelDescription->setText(fm.elidedText(m_description, Qt::ElideMiddle, m_labelDescription->width()));
}


void QxDialogHeaderBox::updateLayout()
{
    QString title;

    if (!m_title.isEmpty())
        title.append(tr("<strong style=\"font-size: large;\">%1</strong>").arg(m_title));
    if (!m_title.isEmpty() && !m_subTitle.isEmpty())
        title.append(tr(" &nbsp; "));
    if (!m_subTitle.isEmpty())
        title.append(m_subTitle);

    if (!title.isEmpty()) {
        m_labelTitle->setText(title);
        m_labelTitle->setVisible(true);
    }
    else {
        m_labelTitle->clear();
        m_labelTitle->setVisible(false);
    }

    if (!m_description.isEmpty()) {
        m_labelDescription->setText(m_description);
        m_labelDescription->setVisible(true);
    }
    else {
        m_labelDescription->clear();
        m_labelDescription->setVisible(false);
    }

    if (!m_icon.isNull()) {
        const int height = layout()->sizeHint().height();
        m_labelIcon->setPixmap(m_icon.pixmap(height, height));
        m_labelIcon->setVisible(true);
    }
    else {
        m_labelIcon->clear();
        m_labelIcon->setVisible(false);
    }
}
