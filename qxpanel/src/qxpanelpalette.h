/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXPANELPALETTE_H
#define QXPANELPALETTE_H

#include <QBoxLayout>
#include <QDockWidget>
#include <QList>

#include <qxpanelunit.h>


class QxPanelPalette : public QDockWidget
{
    Q_OBJECT
    Q_PROPERTY(PaletteDisplayMode paletteDisplayMode READ paletteDisplayMode WRITE setPaletteDisplayMode NOTIFY paletteDisplayModeChanged)
    Q_PROPERTY(QBoxLayout::Direction paletteDisplayDirection READ paletteDisplayDirection WRITE setPaletteDisplayDirection NOTIFY paletteDisplayDirectionChanged)

public:
    enum PaletteDisplayMode {
        NoMode = 0,
        NoBoxes,
        FlatBoxes,
        FrameBoxes,
        GroupBoxes
    };
    Q_ENUM(PaletteDisplayMode)

    explicit QxPanelPalette(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    explicit QxPanelPalette(const QString& text, QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    [[nodiscard]] PaletteDisplayMode paletteDisplayMode() const;
    [[nodiscard]] QBoxLayout::Direction paletteDisplayDirection() const;

    int addUnit(QxPanelUnit* unit);

    int insertUnit(const int index, QxPanelUnit* unit);

    void removeUnit(const int index);

public slots:
    void setPaletteDisplayMode(const QxPanelPalette::PaletteDisplayMode mode);
    void setPaletteDisplayDirection(const QBoxLayout::Direction direction);

signals:
    void paletteDisplayModeChanged(const QxPanelPalette::PaletteDisplayMode mode);
    void paletteDisplayDirectionChanged(const QBoxLayout::Direction direction);

private:
    PaletteDisplayMode m_paletteDisplayMode;
    QBoxLayout::Direction m_paletteDisplayDirection;

    QList<QxPanelUnit*> m_listUnits;
};

#endif // QXPANELPALETTE_H
