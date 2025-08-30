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

public:
    explicit QxDialogHeaderBox(QWidget* parent = nullptr);
    ~QxDialogHeaderBox() = default;

    [[nodiscard]] QIcon icon() const;

public slots:
    void setIcon(const QIcon& icon);

signals:
    void changed();

private:
    QIcon m_icon;
};

#endif // QXDIALOGHEADERBOX_H
