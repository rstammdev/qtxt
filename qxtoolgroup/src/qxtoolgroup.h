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
    Q_PROPERTY(int columnCount READ columnCount WRITE setColumnCount NOTIFY columnCountChanged)

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
    [[nodiscard]] int columnCount() const;

public slots:
    void setType(const QxToolGroup::Type type);
    void setTitle(const QString& title);
    void setColumnCount(const int count);

signals:
    void typeChanged(const QxToolGroup::Type type);
    void titleChanged(const QString& title);
    void columnCountChanged(const int count);

private:
    Type m_type;
    QString m_title;
    int m_columnCount;
};

#endif // QXTOOLGROUP_H
