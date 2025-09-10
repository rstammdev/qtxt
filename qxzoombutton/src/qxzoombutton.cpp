/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxzoombutton.h"


QxZoomButton::QxZoomButton(QWidget* parent)
    : QToolButton{parent}
    , m_zoom{100}
    , m_minimumZoom{50}
    , m_maximumZoom{300}
{

    connect(this , &QxZoomButton::displayModeChanged, this, &QxZoomButton::updateText);
    connect(this , &QxZoomButton::defaultActionChanged, this, &QxZoomButton::updateText);
}


int QxZoomButton::zoom() const
{
    return m_zoom;
}

void QxZoomButton::setZoom(int zoom)
{
    if (zoom == m_zoom)
        return;

    m_zoom = zoom;
    emit zoomChanged(m_zoom);
}


int QxZoomButton::minimumZoom() const
{
    return m_minimumZoom;
}

void QxZoomButton::setMinimumZoom(int minimum)
{
    if (minimum == m_minimumZoom)
        return;

    m_minimumZoom = minimum;
    emit minimumZoomChanged(m_minimumZoom);
}


int QxZoomButton::maximumZoom() const
{
    return m_maximumZoom;
}

void QxZoomButton::setMaximumZoom(int maximum)
{
    if (maximum == m_maximumZoom)
        return;

    m_maximumZoom = maximum;
    emit maximumZoomChanged(m_maximumZoom);
}


void QxZoomButton::zoomIn()
{

}


void QxZoomButton::zoomOut()
{

}


void QxZoomButton::resetZoom()
{
    setZoom(100);
}


QxZoomButton::DisplayMode QxZoomButton::displayMode() const
{
    return m_displayMode;
}

void QxZoomButton::setDisplayMode(DisplayMode mode)
{
    if (mode == m_displayMode)
        return;

    m_displayMode = mode;
    emit displayModeChanged(m_displayMode);
}


void QxZoomButton::setDefaultAction(QAction* action)
{
    if (action == defaultAction())
        return;

    QToolButton::setDefaultAction(action);
    emit defaultActionChanged();
}


void QxZoomButton::updateText()
{
    QString text = QString();
    QIcon icon = QIcon();

    if (m_displayMode == DisplayMode::Percentage)
        text = tr("%1%").arg(m_zoom);
    else if (m_displayMode == DisplayMode::DefaultActionText && defaultAction())
        text = defaultAction()->text();
    else if (m_displayMode == DisplayMode::DefaultActionIcon && defaultAction())
        icon = defaultAction()->icon();

    setText(text);
    setIcon(icon);
}
