/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLBARSTOOLBARPAGEBUTTON_H
#define QXTOOLBARSTOOLBARPAGEBUTTON_H

#include "qxtoolbarstoolbarpage.h"

#include <QToolButton>
#include <QWidget>


class QxToolbarsToolbarPageButton : public QxToolbarsToolbarPage
{
    Q_OBJECT

public:
    explicit QxToolbarsToolbarPageButton(QToolButton* button, QWidget* parent = nullptr);
    ~QxToolbarsToolbarPageButton() = default;

public slots:
    void restoreDefaults(bool current) override;

private:
    QToolButton* m_button;
};

#endif // QXTOOLBARSTOOLBARPAGEBUTTON_H
