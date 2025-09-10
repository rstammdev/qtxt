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

    Q_PROPERTY(int zoom READ zoom WRITE setZoom RESET resetZoom NOTIFY zoomChanged)
    Q_PROPERTY(int minimumZoom READ minimumZoom WRITE setMinimumZoom NOTIFY minimumZoomChanged)
    Q_PROPERTY(int maximumZoom READ maximumZoom WRITE setMaximumZoom NOTIFY maximumZoomChanged)
    Q_PROPERTY(DisplayMode displayMode READ displayMode WRITE setDisplayMode NOTIFY displayModeChanged)

public:
    enum DisplayMode {
        Percentage,
        DefaultActionIcon,
        DefaultActionText
    };
    Q_ENUM(DisplayMode)

    explicit QxZoomButton(QWidget* parent = nullptr);
    ~QxZoomButton() = default;

    [[nodiscard]] int zoom() const;
    [[nodiscard]] int minimumZoom() const;
    [[nodiscard]] int maximumZoom() const;

    [[nodiscard]] DisplayMode displayMode() const;

public slots:
    void setZoom(int zoom);
    void setMinimumZoom(int minimum);
    void setMaximumZoom(int maximum);

    void zoomIn();
    void zoomOut();
    void resetZoom();

    void setDisplayMode(QxZoomButton::DisplayMode mode);

    void setDefaultAction(QAction* action);

signals:
    void zoomChanged(int zoom);
    void minimumZoomChanged(int minimum);
    void maximumZoomChanged(int maximum);

    void displayModeChanged(QxZoomButton::DisplayMode mode);

    void defaultActionChanged();

private slots:
    void updateText();

private:
    int m_zoom;
    int m_minimumZoom;
    int m_maximumZoom;

    DisplayMode m_displayMode;
};

#endif // QXZOOMBUTTON_H
