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


class QxZoomButton : public QToolButton
{
    Q_OBJECT

    Q_PROPERTY(int zoom READ zoom WRITE setZoom NOTIFY zoomChanged)
    Q_PROPERTY(int minimumZoom READ minimumZoom WRITE setMinimumZoom NOTIFY minimumZoomChanged)

public:
    explicit QxZoomButton(QWidget* parent = nullptr);
    ~QxZoomButton() = default;

    [[nodiscard]] int zoom() const;
    [[nodiscard]] int minimumZoom() const;

public slots:
    void setZoom(int zoom);
    void setMinimumZoom(int minimum);

signals:
    void zoomChanged(int zoom);
    void minimumZoomChanged(int minimum);

private:
    int m_zoom;
    int m_minimumZoom;
};

#endif // QXZOOMBUTTON_H
