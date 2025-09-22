/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXPANELUNIT_H
#define QXPANELUNIT_H

#include <QWidget>


class QxPanelUnit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(UnitDisplayMode unitDisplayMode READ unitDisplayMode WRITE setUnitDisplayMode NOTIFY unitDisplayModeChanged)

public:
    enum UnitDisplayMode {
        NoBox = 0,
        FrameBox,
        GroupBox,
        TabBox,
        ToolBox
    };
    Q_ENUM(UnitDisplayMode)

    explicit QxPanelUnit(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    [[nodiscard]] UnitDisplayMode unitDisplayMode() const;

public slots:
    void setUnitDisplayMode(const QxPanelUnit::UnitDisplayMode mode);

signals:
    void unitDisplayModeChanged(const QxPanelUnit::UnitDisplayMode mode);

private:
    UnitDisplayMode m_unitDisplayMode;
};

#endif // QXPANELUNIT_H
