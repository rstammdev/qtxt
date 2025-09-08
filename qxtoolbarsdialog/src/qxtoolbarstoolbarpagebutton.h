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

#include <QButtonGroup>
#include <QCheckBox>
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
    void save() override;

private:
    QToolButton* m_button;

    QButtonGroup* m_buttonsStyle;

    QCheckBox* m_checkboxVisible;
};

#endif // QXTOOLBARSTOOLBARPAGEBUTTON_H
