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
    Q_PROPERTY(int defaultZoom READ defaultZoom WRITE setDefaultZoom NOTIFY defaultZoomChanged)
    Q_PROPERTY(int minimumZoom READ minimumZoom WRITE setMinimumZoom NOTIFY minimumZoomChanged)
    Q_PROPERTY(int maximumZoom READ maximumZoom WRITE setMaximumZoom NOTIFY maximumZoomChanged)
    Q_PROPERTY(int zoomStep READ zoomStep WRITE setZoomStep NOTIFY zoomStepChanged)
    Q_PROPERTY(StepMode stepMode READ stepMode WRITE setStepMode NOTIFY stepModeChanged)
    Q_PROPERTY(DisplayMode displayMode READ displayMode WRITE setDisplayMode NOTIFY displayModeChanged)
    Q_PROPERTY(bool menuVisible READ isMenuVisible WRITE setMenuVisible NOTIFY menuVisibleChanged)

public:
    enum StepMode {
        CurvedSteps,
        LinearSteps,
        CustomSteps
    };
    Q_ENUM(StepMode)

    enum DisplayMode {
        Percentage,
        DefaultActionIcon,
        DefaultActionText
    };
    Q_ENUM(DisplayMode)

    explicit QxZoomButton(QWidget* parent = nullptr);
    ~QxZoomButton() = default;

    [[nodiscard]] int zoom() const;
    [[nodiscard]] int defaultZoom() const;
    [[nodiscard]] int minimumZoom() const;
    [[nodiscard]] int maximumZoom() const;
    [[nodiscard]] int zoomStep() const;

    [[nodiscard]] StepMode stepMode() const;
    [[nodiscard]] DisplayMode displayMode() const;
    [[nodiscard]] bool isMenuVisible() const;

public slots:
    void setZoom(int zoom);
    void setDefaultZoom(int defaultZoom);
    void setMinimumZoom(int minimum);
    void setMaximumZoom(int maximum);
    void setZoomStep(int step);

    void zoomIn();
    void zoomOut();
    void resetZoom();

    void setStepMode(QxZoomButton::StepMode mode);
    void setDisplayMode(QxZoomButton::DisplayMode mode);
    void setMenuVisible(bool visible);

    void setDefaultAction(QAction* action);

signals:
    void zoomChanged(int zoom);
    void defaultZoomChanged(int defaultZoom);
    void minimumZoomChanged(int minimum);
    void maximumZoomChanged(int maximum);
    void zoomStepChanged(int step);

    void stepModeChanged(QxZoomButton::StepMode mode);
    void displayModeChanged(QxZoomButton::DisplayMode mode);
    void menuVisibleChanged(bool visible);

    void defaultActionChanged();

private slots:
    void updateText();

private:
    int m_zoom;
    int m_defaultZoom;
    int m_minimumZoom;
    int m_maximumZoom;
    int m_zoomStep;

    StepMode m_stepMode;
    DisplayMode m_displayMode;
    bool m_menuVisible;
};

#endif // QXZOOMBUTTON_H
