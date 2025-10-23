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
#include <QList>

#include <qxtoolgroup.h>


class QxToolPalette : public QDockWidget
{
    Q_OBJECT
    Q_PROPERTY(DisplayMode displayMode READ displayMode WRITE setDisplayMode NOTIFY displayModeChanged)
    Q_PROPERTY(int columnCount READ columnCount WRITE setColumnCount NOTIFY columnCountChanged)
    Q_PROPERTY(int rowCount READ rowCount WRITE setRowCount NOTIFY rowCountChanged)
    Q_PROPERTY(bool spanning READ isSpanning WRITE setSpanning NOTIFY spanningChanged)

public:
    enum DisplayMode {
        NoBoxes = 0,
        FlatBoxes,
        FrameBoxes,
        GroupBoxes,
        Custom,
    };
    Q_ENUM(DisplayMode)

    explicit QxToolPalette(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    explicit QxToolPalette(const QString& text, QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    [[nodiscard]] DisplayMode displayMode() const;
    [[nodiscard]] int columnCount() const;
    [[nodiscard]] int rowCount() const;
    [[nodiscard]] bool isSpanning() const;

    int addGroup(QxToolGroup* group);
    int insertGroup(const int index, QxToolGroup* group);

public slots:
    void setDisplayMode(const QxToolPalette::DisplayMode mode);
    void setColumnCount(const int count);
    void setRowCount(const int count);
    void setSpanning(const bool enable);

signals:
    void displayModeChanged(const QxToolPalette::DisplayMode mode);
    void columnCountChanged(const int count);
    void rowCountChanged(const int count);
    void spanningChanged(const bool enable);

private:
    DisplayMode m_displayMode;
    int m_columnCount;
    int m_rowCount;
    bool m_spanning;

    QList<QxToolGroup*> m_groups;
};

#endif // QXTOOLPALETTE_H
