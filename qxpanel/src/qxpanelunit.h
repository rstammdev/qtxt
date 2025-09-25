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
    Q_PROPERTY(UnitType unitType READ unitType WRITE setUnitType NOTIFY unitTypeChanged)
    Q_PROPERTY(QString unitTitle READ unitTitle WRITE setUnitTitle NOTIFY unitTitleChanged)
    Q_PROPERTY(QString unitDescription READ unitDescription WRITE setUnitDescription NOTIFY unitDescriptionChanged)

public:
    enum UnitType {
        NoType = 0,
        FlatBox,
        FrameBox,
        GroupBox
    };
    Q_ENUM(UnitType)

    explicit QxPanelUnit(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    [[nodiscard]] UnitType unitType() const;
    [[nodiscard]] QString unitTitle() const;
    [[nodiscard]] QString unitDescription() const;

public slots:
    void setUnitType(const QxPanelUnit::UnitType type);
    void setUnitTitle(const QString& title);
    void setUnitDescription(const QString& description);

signals:
    void unitTypeChanged(const QxPanelUnit::UnitType type);
    void unitTitleChanged(const QString& title);
    void unitDescriptionChanged(const QString& description);

private:
    UnitType m_unitType;
    QString m_unitTitle;
    QString m_unitDescription;
};

#endif // QXPANELUNIT_H
