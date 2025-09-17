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
    , m_zoomFactor{1.0}
    , m_zoomFactors{0.3, 0.5, 0.67, 0.8, 0.9, 1.0, 1.1, 1.2, 1.33, 1.5, 1.7, 2.0, 2.4, 3.0, 4.0, 5.0}
    , m_menuVisible{true}
{

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
    if (m_zoomFactors.indexOf(factor) < 0)
        qWarning("QxZoomButton::setDefaultZoomFactor(): given factor is not included in the factor list");

    if (factor == m_defaultZoomFactor)
        return;

    m_defaultZoomFactor = factor;
    emit defaultZoomFactorChanged(m_defaultZoomFactor);
}

void QxZoomButton::resetDefaultZoomFactor()
{

}


qreal QxZoomButton::zoomFactor() const
{
    return m_zoomFactor;
}

void QxZoomButton::setZoomFactor(const qreal factor)
{
    if (factor == m_zoomFactor)
        return;

    m_zoomFactor = factor;
    updateText();
    emit zoomFactorChanged(m_zoomFactor);
}

void QxZoomButton::resetZoomFactor()
{
    setZoomFactor(m_defaultZoomFactor);
}


QList<qreal> QxZoomButton::zoomFactors() const
{
    return m_zoomFactors;
}

void QxZoomButton::setZoomFactors(const QList<qreal>& factors)
{
    if (factors == m_zoomFactors)
        return;

    m_zoomFactors = factors;
    emit zoomFactorsChanged();
}


bool QxZoomButton::isMenuVisible() const
{
    return m_menuVisible;
}

void QxZoomButton::setMenuVisible(const bool visible)
{
    if (visible == m_menuVisible)
        return;

    m_menuVisible = visible;
    emit menuVisibleChanged();
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
