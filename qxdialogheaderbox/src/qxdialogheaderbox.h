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
#include <QLabel>
#include <QResizeEvent>
#include <QWidget>


class QxDialogHeaderBox : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QIcon icon READ icon WRITE setIcon NOTIFY changed)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY changed)
    Q_PROPERTY(QString subTitle READ subTitle WRITE setSubTitle NOTIFY changed)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY changed)

public:
    explicit QxDialogHeaderBox(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    ~QxDialogHeaderBox() = default;

    [[nodiscard]] QIcon icon() const;
    [[nodiscard]] QString title() const;
    [[nodiscard]] QString subTitle() const;
    [[nodiscard]] QString description() const;

public slots:
    void setIcon(const QIcon& icon);
    void setTitle(const QString& title);
    void setSubTitle(const QString& subTitle);
    void setDescription(const QString& description);

signals:
    void changed();

protected:
    void resizeEvent(QResizeEvent* event) override;

private slots:
    void updateLayout();

private:
    QIcon m_icon;
    QString m_title;
    QString m_subTitle;
    QString m_description;

    QLabel* m_labelIcon;
    QLabel* m_labelTitle;
    QLabel* m_labelDescription;
};

#endif // QXDIALOGHEADERBOX_H
