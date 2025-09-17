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
    Q_PROPERTY(QList<qreal> curvedZoomFactors READ curvedZoomFactors WRITE setCurvedZoomFactors NOTIFY curvedZoomFactorsChanged)
    Q_PROPERTY(int linearZoomStep READ linearZoomStep WRITE setLinearZoomStep NOTIFY linearZoomStepChanged)
    Q_PROPERTY(QList<int> customZoomSteps READ customZoomSteps WRITE setCustomZoomSteps NOTIFY customZoomStepsChanged)
    Q_PROPERTY(bool menuVisible READ isMenuVisible WRITE setMenuVisible NOTIFY menuVisibleChanged)

public:
    explicit QxZoomButton(QWidget* parent = nullptr);
    ~QxZoomButton() = default;

    [[nodiscard]] int zoom() const;
    [[nodiscard]] int defaultZoom() const;
    [[nodiscard]] QList<qreal> curvedZoomFactors() const;
    [[nodiscard]] int linearZoomStep() const;
    [[nodiscard]] QList<int> customZoomSteps() const;
    [[nodiscard]] bool isMenuVisible() const;

public slots:
    void setZoom(int zoom);
    void setDefaultZoom(int defaultZoom);
    void setCurvedZoomFactors(QList<qreal> factors);
    void setLinearZoomStep(int step);
    void setCustomZoomSteps(QList<int> steps);
    void setMenuVisible(bool visible);

    void zoomIn();
    void zoomOut();
    void resetZoom();

    void setDefaultAction(QAction* action);

signals:
    void zoomChanged(int zoom);
    void defaultZoomChanged(int defaultZoom);
    void curvedZoomFactorsChanged(QList<qreal> factors);
    void linearZoomStepChanged(int step);
    void customZoomStepsChanged(QList<int> steps);
    void menuVisibleChanged(bool visible);

    void defaultActionChanged();

protected:
    void wheelEvent(QWheelEvent* event) override;

private slots:
    void updateText();

private:
    int m_zoom;
    int m_defaultZoom;
    QList<qreal> m_curvedZoomFactors;
    int m_linearZoomStep;
    QList<int> m_customZoomSteps;
    bool m_menuVisible;

    QList<int> m_curvedZoomSteps;

    void createCurvedZoomSteps();

    int getNewZoom(int stepIndex);
};

#endif // QXZOOMBUTTON_H
