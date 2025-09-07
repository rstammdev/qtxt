/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLBARSTOOLBARPAGESEPARATOR_H
#define QXTOOLBARSTOOLBARPAGESEPARATOR_H

#include "qxtoolbarstoolbarpage.h"

#include <QAction>
#include <QWidget>


class QxToolbarsToolbarPageSeparator : public QxToolbarsToolbarPage
{
    Q_OBJECT

public:
    explicit QxToolbarsToolbarPageSeparator(QAction* separator, QWidget* parent = nullptr);
    ~QxToolbarsToolbarPageSeparator() = default;

public slots:
    void restoreDefaults(bool current) override;

private:
    QAction* m_separator;
};

#endif // QXTOOLBARSTOOLBARPAGESEPARATOR_H
