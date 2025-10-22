/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLGROUP_H
#define QXTOOLGROUP_H

#include <QIcon>
#include <QWidget>


class QxToolGroup : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(Type type READ type WRITE setType NOTIFY typeChanged)

public:
    enum Type {
        NoBox = 0,
        FlatBox,
        FrameBox,
        GroupBox
    };
    Q_ENUM(Type)

    explicit QxToolGroup(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    [[nodiscard]] Type type() const;

public slots:
    void setType(const QxToolGroup::Type type);

signals:
    void typeChanged(const QxToolGroup::Type type);

private:
    Type m_type;
};

#endif // QXTOOLGROUP_H
