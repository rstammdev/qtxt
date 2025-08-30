/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXDIALOGHEADERBOX_H
#define QXDIALOGHEADERBOX_H

#include <QIcon>
#include <QWidget>


class QxDialogHeaderBox : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QIcon icon READ icon WRITE setIcon NOTIFY changed)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY changed)
    Q_PROPERTY(QString subTitle READ subTitle WRITE setSubTitle NOTIFY changed)

public:
    explicit QxDialogHeaderBox(QWidget* parent = nullptr);
    ~QxDialogHeaderBox() = default;

    [[nodiscard]] QIcon icon() const;
    [[nodiscard]] QString title() const;
    [[nodiscard]] QString subTitle() const;

public slots:
    void setIcon(const QIcon& icon);
    void setTitle(const QString& title);
    void setSubTitle(const QString& subTitle);

signals:
    void changed();

private:
    QIcon m_icon;
    QString m_title;
    QString m_subTitle;
};

#endif // QXDIALOGHEADERBOX_H
