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
    Q_PROPERTY(int minimumZoom READ minimumZoom WRITE setMinimumZoom NOTIFY minimumZoomChanged)
    Q_PROPERTY(int maximumZoom READ maximumZoom WRITE setMaximumZoom NOTIFY maximumZoomChanged)
    Q_PROPERTY(QList<qreal> curvedZoomFactors READ curvedZoomFactors WRITE setCurvedZoomFactors NOTIFY curvedZoomFactorsChanged)
    Q_PROPERTY(int linearZoomStep READ linearZoomStep WRITE setLinearZoomStep NOTIFY linearZoomStepChanged)
    Q_PROPERTY(QList<int> customZoomSteps READ customZoomSteps WRITE setCustomZoomSteps NOTIFY customZoomStepsChanged)
    Q_PROPERTY(DisplayMode displayMode READ displayMode WRITE setDisplayMode NOTIFY displayModeChanged)
    Q_PROPERTY(bool menuVisible READ isMenuVisible WRITE setMenuVisible NOTIFY menuVisibleChanged)

public:
    enum DisplayMode {
        Percentage,
        DefaultActionText,
        DefaultActionIcon
    };
    Q_ENUM(DisplayMode)

    explicit QxZoomButton(QWidget* parent = nullptr);
    ~QxZoomButton() = default;

    [[nodiscard]] int zoom() const;
    [[nodiscard]] int defaultZoom() const;
    [[nodiscard]] int minimumZoom() const;
    [[nodiscard]] int maximumZoom() const;
    [[nodiscard]] QList<qreal> curvedZoomFactors() const;
    [[nodiscard]] int linearZoomStep() const;
    [[nodiscard]] QList<int> customZoomSteps() const;
    [[nodiscard]] DisplayMode displayMode() const;
    [[nodiscard]] bool isMenuVisible() const;

public slots:
    void setZoom(int zoom);
    void setDefaultZoom(int defaultZoom);
    void setMinimumZoom(int minimum);
    void setMaximumZoom(int maximum);
    void setCurvedZoomFactors(QList<qreal> factors);
    void setLinearZoomStep(int step);
    void setCustomZoomSteps(QList<int> steps);
    void setDisplayMode(QxZoomButton::DisplayMode mode);
    void setMenuVisible(bool visible);

    void zoomIn();
    void zoomOut();
    void resetZoom();

    void setDefaultAction(QAction* action);

signals:
    void zoomChanged(int zoom);
    void defaultZoomChanged(int defaultZoom);
    void minimumZoomChanged(int minimum);
    void maximumZoomChanged(int maximum);
    void curvedZoomFactorsChanged(QList<qreal> factors);
    void linearZoomStepChanged(int step);
    void customZoomStepsChanged(QList<int> steps);
    void displayModeChanged(QxZoomButton::DisplayMode mode);
    void menuVisibleChanged(bool visible);

    void defaultActionChanged();

protected:
    void wheelEvent(QWheelEvent* event) override;

private slots:
    void updateText();

private:
    int m_zoom;
    int m_defaultZoom;
    int m_minimumZoom;
    int m_maximumZoom;
    QList<qreal> m_curvedZoomFactors;
    int m_linearZoomStep;
    QList<int> m_customZoomSteps;
    DisplayMode m_displayMode;
    bool m_menuVisible;

    QList<int> m_curvedZoomSteps;

    void createCurvedZoomSteps();

    int getNewZoom(int stepIndex);
};

#endif // QXZOOMBUTTON_H
