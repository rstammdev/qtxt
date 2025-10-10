/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXABOUTDIALOG_H
#define QXABOUTDIALOG_H

#include <QDialog>
#include <QTabWidget>

#include <qxdialogheaderbox.h>


class QxAboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QxAboutDialog(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    QxDialogHeaderBox* header() const;

    QTabWidget* tabs() const;

    int insertPage(const int index, QWidget* page, const QString& label);
    int insertPage(const int index, QWidget* page, const QIcon& icon, const QString& label);

private:
    QxDialogHeaderBox* m_headerBox;

    QTabWidget* m_tabBox;
};

#endif // QXABOUTDIALOG_H
