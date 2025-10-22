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
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)

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
    [[nodiscard]] QString title() const;

public slots:
    void setType(const QxToolGroup::Type type);
    void setTitle(const QString& title);

signals:
    void typeChanged(const QxToolGroup::Type type);
    void titleChanged(const QString& title);

private:
    Type m_type;
    QString m_title;
};

#endif // QXTOOLGROUP_H
