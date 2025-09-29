/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXTOOLBARSTOOLBARPAGELABEL_H
#define QXTOOLBARSTOOLBARPAGELABEL_H

#include "qxtoolbarstoolbarpage.h"

#include <QCheckBox>
#include <QLabel>


class QxToolbarsToolbarPageLabel : public QxToolbarsToolbarPage
{
    Q_OBJECT

public:
    explicit QxToolbarsToolbarPageLabel(QLabel* label, QWidget* parent = nullptr);

public slots:
    void restoreDefaults(bool current) override;
    void save() override;

private:
    QLabel* m_label;

    QCheckBox* m_checkboxVisible;
};

#endif // QXTOOLBARSTOOLBARPAGELABEL_H
