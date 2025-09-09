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
