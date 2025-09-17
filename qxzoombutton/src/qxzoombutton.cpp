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
    , m_defaultZoomFactor{1.0}
    , m_zoom{0}
    , m_menuVisible{true}
{

    connect(this, &QxZoomButton::zoomChanged, this, &QxZoomButton::updateText);
    connect(this, &QxZoomButton::defaultActionChanged, this, &QxZoomButton::updateText);
    connect(this, &QxZoomButton::clicked, this, &QxZoomButton::resetZoom);

    resetZoom();
}


qreal QxZoomButton::defaultZoomFactor() const
{
    return m_defaultZoomFactor;
}

void QxZoomButton::setDefaultZoomFactor(const qreal factor)
{
    if (factor == m_defaultZoomFactor)
        return;

    m_defaultZoomFactor = factor;
    emit defaultZoomFactorChanged(m_defaultZoomFactor);
}

void QxZoomButton::resetDefaultZoomFactor()
{

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
