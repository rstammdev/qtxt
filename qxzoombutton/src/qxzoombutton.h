/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXZOOMBUTTON_H
#define QXZOOMBUTTON_H

#include <QToolButton>
#include <QWheelEvent>


class QxZoomButton : public QToolButton
{
    Q_OBJECT
    Q_PROPERTY(int defaultZoomFactor READ defaultZoomFactor WRITE setDefaultZoomFactor RESET resetDefaultZoomFactor NOTIFY defaultZoomFactorChanged)
    Q_PROPERTY(int zoom READ zoom WRITE setZoom RESET resetZoom NOTIFY zoomChanged)
    Q_PROPERTY(bool menuVisible READ isMenuVisible WRITE setMenuVisible NOTIFY menuVisibleChanged)

public:
    explicit QxZoomButton(QWidget* parent = nullptr);
    ~QxZoomButton() = default;

    [[nodiscard]] qreal defaultZoomFactor() const;
    [[nodiscard]] int zoom() const;
    [[nodiscard]] bool isMenuVisible() const;

public slots:
    void setDefaultZoomFactor(const qreal factor);
    void resetDefaultZoomFactor();
    void setZoom(int zoom);
    void setMenuVisible(bool visible);

    void zoomIn();
    void zoomOut();
    void resetZoom();

    void setDefaultAction(QAction* action);

signals:
    void defaultZoomFactorChanged(qreal factor);
    void zoomChanged(int zoom);
    void menuVisibleChanged(bool visible);

    void defaultActionChanged();

protected:
    void wheelEvent(QWheelEvent* event) override;

private slots:
    void updateText();

private:
    qreal m_defaultZoomFactor;
    int m_zoom;
    bool m_menuVisible;

    int getNewZoom(int stepIndex);
};

#endif // QXZOOMBUTTON_H
