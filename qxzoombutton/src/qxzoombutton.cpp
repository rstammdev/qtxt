/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxzoombutton.h"

using namespace Qt::Literals::StringLiterals;


QxZoomButton::QxZoomButton(QWidget* parent)
    : QToolButton{parent}
    , m_defaultZoomFactor{1.0}
    , m_zoomFactor{1.0}
    , m_zoomFactors{0.3, 0.5, 0.67, 0.8, 0.9, 1.0, 1.1, 1.2, 1.33, 1.5, 1.7, 2.0, 2.4, 3.0, 4.0, 5.0}
    , m_menuVisible{true}
    , m_text{tr("%1%")}
    , m_menuZoomFactors{new QMenu(this)}
{
    connect(this, &QxZoomButton::clicked, this, &QxZoomButton::resetZoomFactor);

    updateText();
    updateMenu();
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
    setDefaultZoomFactor(1.0);
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
    updateMenu();
    emit menuVisibleChanged();
}


void QxZoomButton::zoomIn()
{
    int index = m_zoomFactors.indexOf(m_zoomFactor);

    if (index >= 0)
        index += 1;
    else {
        index = 0;
        for ( ; index < m_zoomFactors.count(); index++)
            if (m_zoomFactors.at(index) >= m_zoomFactor)
                break;
    }

    setZoomFactorByIndex(index);
}


void QxZoomButton::zoomOut()
{
    int index = m_zoomFactors.indexOf(m_zoomFactor);

    if (index >= 0)
        index -= 1;
    else {
        index = m_zoomFactors.count() - 1;
        for ( ; index >= 0; index--)
            if (m_zoomFactors.at(index) <= m_zoomFactor)
                break;
    }

    setZoomFactorByIndex(index);
}


void QxZoomButton::setZoomFactorByIndex(const int index)
{
    if (index >= 0 && index < m_zoomFactors.count())
        setZoomFactor(m_zoomFactors.at(index));
}

void QxZoomButton::resetZoom()
{
    resetZoomFactor();
}


void QxZoomButton::setDefaultAction(QAction* action)
{
    if (action == defaultAction())
        return;

    QToolButton::setDefaultAction(action);

    m_text = action->text();
    m_iconText = action->iconText();
    updateText();
}


void QxZoomButton::setText(const QString& text)
{
    if (text == QxZoomButton::text())
        return;

    QToolButton::setText(text);

    m_text = text;
    m_iconText = QString();
    updateText();
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
    const int percentage = int(m_zoomFactor * 100);
    QString text = !m_iconText.isEmpty() ? m_iconText : m_text;

    if (text.contains("%1"_L1))
        text = QString(text).arg(percentage);

    QToolButton::setText(text);
}


void QxZoomButton::updateMenu()
{
    if (m_menuVisible) {
        setMenu(m_menuZoomFactors);
        setPopupMode(QToolButton::MenuButtonPopup);
    }
    else {
        setMenu(nullptr);
        setPopupMode(QToolButton::DelayedPopup);
    }
}
