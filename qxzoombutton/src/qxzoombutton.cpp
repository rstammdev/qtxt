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
    , m_defaultZoom{100}
    , m_minimumZoom{50}
    , m_maximumZoom{300}
    , m_displayMode{DisplayMode::Percentage}
    , m_menuVisible{true}
{

    updateText();

    connect(this , &QxZoomButton::zoomChanged, this, &QxZoomButton::updateText);
    connect(this , &QxZoomButton::displayModeChanged, this, &QxZoomButton::updateText);
    connect(this , &QxZoomButton::defaultActionChanged, this, &QxZoomButton::updateText);

    connect(this, &QxZoomButton::clicked, this, &QxZoomButton::resetZoom);

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


int QxZoomButton::defaultZoom() const
{
    return m_defaultZoom;
}

void QxZoomButton::setDefaultZoom(int defaultZoom)
{
    if (defaultZoom == m_defaultZoom)
        return;

    m_defaultZoom = defaultZoom;
    emit defaultZoomChanged(m_defaultZoom);
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
    setZoom(m_defaultZoom);
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


bool QxZoomButton::isMenuVisible() const
{
    return m_menuVisible;
}

void QxZoomButton::setMenuVisible(bool visible)
{
    if (visible == m_menuVisible)
        return;

    m_menuVisible = visible;
    emit menuVisibleChanged(m_menuVisible);
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
