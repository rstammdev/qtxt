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
