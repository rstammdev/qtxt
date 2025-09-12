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
    , m_minimumZoom{50}
    , m_maximumZoom{300}
    , m_curvedZoomFactors{0.3, 0.5, 0.67, 0.8, 0.9, 1.0, 1.1, 1.2, 1.33, 1.5, 1.7, 2.0, 2.4, 3.0, 4.0, 5.0}
    , m_linearZoomStep{25}
    , m_customZoomSteps{}
    , m_stepMode{StepMode::CurvedSteps}
    , m_displayMode{DisplayMode::Percentage}
    , m_menuVisible{true}
    , m_curvedZoomSteps{}
{

    connect(this, &QxZoomButton::zoomChanged, this, &QxZoomButton::updateText);
    connect(this, &QxZoomButton::displayModeChanged, this, &QxZoomButton::updateText);
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


QxZoomButton::StepMode QxZoomButton::stepMode() const
{
    return m_stepMode;
}

void QxZoomButton::setStepMode(StepMode mode)
{
    if (mode == m_stepMode)
        return;

    m_stepMode = mode;
    emit stepModeChanged(m_stepMode);
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


void QxZoomButton::zoomIn()
{
    int zoom{0};

    if (m_stepMode == StepMode::CurvedSteps)
        zoom = getNewZoom(1);
    else if (m_stepMode == StepMode::LinearSteps)
        zoom = m_zoom + m_linearZoomStep;
    else if (m_stepMode == StepMode::CustomSteps)
        zoom = getNewZoom(1);

    if (zoom >= m_minimumZoom && zoom <= m_maximumZoom)
        setZoom(zoom);
}


void QxZoomButton::zoomOut()
{
    int zoom{0};

    if (m_stepMode == StepMode::CurvedSteps)
        zoom = getNewZoom(-1);
    else if (m_stepMode == StepMode::LinearSteps)
        zoom = m_zoom - m_linearZoomStep;
    else if (m_stepMode == StepMode::CustomSteps)
        zoom = getNewZoom(-1);

    if (zoom >= m_minimumZoom && zoom <= m_maximumZoom)
        setZoom(zoom);
}


int QxZoomButton::getNewZoom(int stepIndex)
{
    int zoom{0};

    if (m_stepMode == StepMode::CurvedSteps) {

        const int newIndex = m_curvedZoomSteps.indexOf(m_zoom) + stepIndex;

        if (newIndex >= 0 && newIndex < m_curvedZoomSteps.count())
            zoom = m_curvedZoomSteps.at(newIndex);
    }
    else if (m_stepMode == StepMode::CustomSteps) {

        const int newIndex = m_customZoomSteps.indexOf(m_zoom) + stepIndex;

        if (newIndex >= 0 && newIndex < m_customZoomSteps.count())
            zoom = m_customZoomSteps.at(newIndex);
    }

    return zoom;
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
    QString text;
    QIcon icon;

    if (m_displayMode == DisplayMode::Percentage)
        text = tr("%1%").arg(m_zoom);
    else if (m_displayMode == DisplayMode::DefaultActionText && defaultAction())
        text = defaultAction()->text();
    else if (m_displayMode == DisplayMode::DefaultActionIcon && defaultAction())
        icon = defaultAction()->icon();

    setText(text);
    setIcon(icon);
}
