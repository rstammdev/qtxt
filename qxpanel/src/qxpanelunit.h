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
    Q_PROPERTY(QString unitTitle READ unitTitle WRITE setUnitTitle NOTIFY unitTitleChanged)

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
    [[nodiscard]] QString unitTitle() const;

public slots:
    void setUnitDisplayMode(const QxPanelUnit::UnitDisplayMode mode);
    void setUnitTitle(const QString& title);

signals:
    void unitDisplayModeChanged(const QxPanelUnit::UnitDisplayMode mode);
    void unitTitleChanged(const QString& title);

private:
    UnitDisplayMode m_unitDisplayMode;
    QString m_unitTitle;
};

#endif // QXPANELUNIT_H
