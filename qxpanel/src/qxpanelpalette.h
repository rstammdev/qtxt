/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXPANELPALETTE_H
#define QXPANELPALETTE_H

#include <QDockWidget>
#include <QList>

#include <qxpanelunit.h>


class QxPanelPalette : public QDockWidget
{
    Q_OBJECT
    Q_PROPERTY(DisplayMode displayMode READ displayMode WRITE setDisplayMode NOTIFY displayModeChanged)

public:
    enum DisplayMode {
        NoMode = 0,
        NoBox,
        FrameBox,
        GroupBox,
        TabBox,
        ToolBox
    };
    Q_ENUM(DisplayMode)

    explicit QxPanelPalette(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    explicit QxPanelPalette(const QString& text, QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    [[nodiscard]] DisplayMode displayMode() const;

    int addUnit(QxPanelUnit* unit);

    int insertUnit(const int index, QxPanelUnit* unit);

    void removeUnit(const int index);

public slots:
    void setDisplayMode(const QxPanelPalette::DisplayMode mode);

signals:
    void displayModeChanged(const QxPanelPalette::DisplayMode mode);

private:
    DisplayMode m_displayMode;

    QList<QxPanelUnit*> m_listUnits;
};

#endif // QXPANELPALETTE_H
