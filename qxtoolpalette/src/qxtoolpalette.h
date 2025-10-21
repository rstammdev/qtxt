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
    Q_PROPERTY(int columnCount READ columnCount WRITE setColumnCount NOTIFY columnCountChanged)

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
    [[nodiscard]] int columnCount() const;

public slots:
    void setDisplayMode(const QxToolPalette::DisplayMode mode);
    void setColumnCount(const int count);

signals:
    void displayModeChanged(const QxToolPalette::DisplayMode mode);
    void columnCountChanged(const int count);

private:
    DisplayMode m_displayMode;
    int m_columnCount;
};

#endif // QXTOOLPALETTE_H
