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
    Q_PROPERTY(qreal zoomFactor READ zoomFactor WRITE setZoomFactor RESET resetZoomFactor NOTIFY zoomFactorChanged)
    Q_PROPERTY(QList<qreal> zoomFactors READ zoomFactors WRITE setZoomFactors NOTIFY zoomFactorsChanged)
    Q_PROPERTY(bool menuVisible READ isMenuVisible WRITE setMenuVisible NOTIFY menuVisibleChanged)

public:
    explicit QxZoomButton(QWidget* parent = nullptr);
    ~QxZoomButton() = default;

    [[nodiscard]] qreal defaultZoomFactor() const;
    [[nodiscard]] qreal zoomFactor() const;
    [[nodiscard]] QList<qreal> zoomFactors() const;
    [[nodiscard]] bool isMenuVisible() const;

public slots:
    void setDefaultZoomFactor(const qreal factor);
    void resetDefaultZoomFactor();
    void setZoomFactor(const qreal factor);
    void resetZoomFactor();
    void setZoomFactors(const QList<qreal>& factors);
    void setMenuVisible(const bool visible);

    void zoomIn();
    void zoomOut();
    void resetZoom();

    void setDefaultAction(QAction* action);
    void setText(const QString& text);

signals:
    void defaultZoomFactorChanged(qreal factor);
    void zoomFactorChanged(qreal factor);
    void zoomFactorsChanged();
    void menuVisibleChanged();

protected:
    void wheelEvent(QWheelEvent* event) override;

private slots:
    void updateText();

private:
    qreal m_defaultZoomFactor;
    qreal m_zoomFactor;
    QList<qreal> m_zoomFactors;
    bool m_menuVisible;

    QString m_text;
    QString m_iconText;

    int getNewZoom(int stepIndex);
};

#endif // QXZOOMBUTTON_H
