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

    Q_PROPERTY(int zoom READ zoom WRITE setZoom RESET resetZoom NOTIFY zoomChanged)
    Q_PROPERTY(int defaultZoom READ defaultZoom WRITE setDefaultZoom NOTIFY defaultZoomChanged)
    Q_PROPERTY(bool menuVisible READ isMenuVisible WRITE setMenuVisible NOTIFY menuVisibleChanged)

public:
    explicit QxZoomButton(QWidget* parent = nullptr);
    ~QxZoomButton() = default;

    [[nodiscard]] int zoom() const;
    [[nodiscard]] int defaultZoom() const;
    [[nodiscard]] bool isMenuVisible() const;

public slots:
    void setZoom(int zoom);
    void setDefaultZoom(int defaultZoom);
    void setMenuVisible(bool visible);

    void zoomIn();
    void zoomOut();
    void resetZoom();

    void setDefaultAction(QAction* action);

signals:
    void zoomChanged(int zoom);
    void defaultZoomChanged(int defaultZoom);
    void menuVisibleChanged(bool visible);

    void defaultActionChanged();

protected:
    void wheelEvent(QWheelEvent* event) override;

private slots:
    void updateText();

private:
    int m_zoom;
    int m_defaultZoom;
    bool m_menuVisible;

    int getNewZoom(int stepIndex);
};

#endif // QXZOOMBUTTON_H
