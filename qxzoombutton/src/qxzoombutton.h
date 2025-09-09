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


public:
    explicit QxZoomButton(QWidget* parent = nullptr);
    ~QxZoomButton() = default;

    [[nodiscard]] int zoom() const;

public slots:
    void setZoom(int zoom);

signals:
    void zoomChanged(int zoom);

private:
    int m_zoom;
};

#endif // QXZOOMBUTTON_H
