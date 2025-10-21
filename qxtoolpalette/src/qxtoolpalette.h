/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLPALETTE_H
#define QXTOOLPALETTE_H

#include <QDockWidget>


class QxToolPalette : public QDockWidget
{
    Q_OBJECT
    Q_PROPERTY(DisplayMode displayMode READ displayMode WRITE setDisplayMode NOTIFY displayModeChanged)

public:
    enum DisplayMode {
        Custom = 0,
        NoBoxes,
        FlatBoxes,
        FrameBoxes,
        GroupBoxes
    };
    Q_ENUM(DisplayMode)

    explicit QxToolPalette(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    explicit QxToolPalette(const QString& text, QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    [[nodiscard]] DisplayMode displayMode() const;

public slots:
    void setDisplayMode(const QxToolPalette::DisplayMode mode);

signals:
    void displayModeChanged(const QxToolPalette::DisplayMode mode);

private:
    DisplayMode m_displayMode;
};

#endif // QXTOOLPALETTE_H
