/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLBARSTOOLBARPAGE_H
#define QXTOOLBARSTOOLBARPAGE_H

#include <QWidget>


class QxToolbarsToolbarPage : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QString pageTitle READ pageTitle WRITE setPageTitle NOTIFY pageTitleChanged)

public:
    explicit QxToolbarsToolbarPage(QWidget* parent = nullptr);
    ~QxToolbarsToolbarPage() = default;

    [[nodiscard]] QString pageTitle() const;

public slots:
    void setPageTitle(const QString& title);

signals:
    void pageTitleChanged(const QString& title);

private:
    QString m_pageTitle;
};

#endif // QXTOOLBARSTOOLBARPAGE_H
