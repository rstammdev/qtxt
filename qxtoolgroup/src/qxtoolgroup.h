/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLGROUP_H
#define QXTOOLGROUP_H

#include <QAction>
#include <QIcon>
#include <QList>
#include <QWidget>


class QxToolGroup : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(Type type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(int columnCount READ columnCount WRITE setColumnCount NOTIFY columnCountChanged)
    Q_PROPERTY(int rowCount READ rowCount WRITE setRowCount NOTIFY rowCountChanged)
    Q_PROPERTY(bool spanning READ isSpanning WRITE setSpanning NOTIFY spanningChanged)

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
    [[nodiscard]] int rowCount() const;
    [[nodiscard]] bool isSpanning() const;

    int addWidget(QWidget* widget);
    int insertWidget(const int index, QWidget* widget);

    bool removeWidget(const int index);

    int widgetCount();

    int addAction(QAction* action);
    void addActions(const QList<QAction*>& actions);

public slots:
    void setType(const QxToolGroup::Type type);
    void setTitle(const QString& title);
    void setColumnCount(const int count);
    void setRowCount(const int count);
    void setSpanning(const bool enable);

signals:
    void typeChanged(const QxToolGroup::Type type);
    void titleChanged(const QString& title);
    void columnCountChanged(const int count);
    void rowCountChanged(const int count);
    void spanningChanged(const bool enable);

protected:
    void rebuildLayout();

private:
    Type m_type;
    QString m_title;
    int m_columnCount;
    int m_rowCount;
    bool m_spanning;

    QList<QWidget*> m_widgets;
};

#endif // QXTOOLGROUP_H
