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
    , m_curvedZoomFactors{0.3, 0.5, 0.67, 0.8, 0.9, 1.0, 1.1, 1.2, 1.33, 1.5, 1.7, 2.0, 2.4, 3.0, 4.0, 5.0}
    , m_linearZoomStep{25}
    , m_customZoomSteps{}
    , m_menuVisible{true}
    , m_curvedZoomSteps{}
{

    connect(this, &QxZoomButton::zoomChanged, this, &QxZoomButton::updateText);
    connect(this, &QxZoomButton::defaultActionChanged, this, &QxZoomButton::updateText);
    connect(this, &QxZoomButton::clicked, this, &QxZoomButton::resetZoom);
    connect(this, &QxZoomButton::curvedZoomFactorsChanged, this, &QxZoomButton::createCurvedZoomSteps);

    createCurvedZoomSteps();

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


QList<qreal> QxZoomButton::curvedZoomFactors() const
{
    return m_curvedZoomFactors;
}

void QxZoomButton::setCurvedZoomFactors(QList<qreal> factors)
{
    if (factors == m_curvedZoomFactors)
        return;

    m_curvedZoomFactors = factors;
    emit curvedZoomFactorsChanged(m_curvedZoomFactors);
}


int QxZoomButton::linearZoomStep() const
{
    return m_linearZoomStep;
}

void QxZoomButton::setLinearZoomStep(int step)
{
    if (step == m_linearZoomStep)
        return;

    m_linearZoomStep = step;
    emit linearZoomStepChanged(m_linearZoomStep);
}


QList<int> QxZoomButton::customZoomSteps() const
{
    return m_customZoomSteps;
}

void QxZoomButton::setCustomZoomSteps(QList<int> steps)
{
    if (steps == m_customZoomSteps)
        return;

    m_customZoomSteps = steps;
    emit customZoomStepsChanged(m_customZoomSteps);
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


void QxZoomButton::createCurvedZoomSteps()
{
    const QList<qreal> factors = m_curvedZoomFactors;
    for (const qreal factor : factors)
        m_curvedZoomSteps << int(factor * 100);
}


void QxZoomButton::updateText()
{

}
