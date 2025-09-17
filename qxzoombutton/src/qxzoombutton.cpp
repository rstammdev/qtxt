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
    , m_zoom{0}
    , m_defaultZoom{100}
    , m_menuVisible{true}
{

    connect(this, &QxZoomButton::zoomChanged, this, &QxZoomButton::updateText);
    connect(this, &QxZoomButton::defaultActionChanged, this, &QxZoomButton::updateText);
    connect(this, &QxZoomButton::clicked, this, &QxZoomButton::resetZoom);

    resetZoom();
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


void QxZoomButton::setDefaultAction(QAction* action)
{
    if (action == defaultAction())
        return;

    QToolButton::setDefaultAction(action);
    emit defaultActionChanged();
}


void QxZoomButton::wheelEvent(QWheelEvent* event)
{
    if (event->angleDelta().y() > 0)
        zoomIn();
    else if (event->angleDelta().y() < 0)
        zoomOut();

    event->accept();
}


void QxZoomButton::updateText()
{

}
