/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXCONFIRMATIONBOX_H
#define QXCONFIRMATIONBOX_H

#include <QMessageBox>


class QxConfirmationBox : public QMessageBox
{
    Q_OBJECT

public:
    static StandardButton continueCancelInformation(QWidget* parent, const QString& title, const QString& text, const QString& informativeText = QString(), const QString& key = QString());
    static StandardButton continueCancelWarning(QWidget* parent, const QString& title, const QString& text, const QString& informativeText = QString(), const QString& key = QString());
    static StandardButton continueCancel(QWidget* parent, const Icon icon, const QString& title, const QString& text, const QString& informativeText = QString(), const QString& key = QString());

private:
    explicit QxConfirmationBox(const QString& key, QWidget* parent = nullptr);
    ~QxConfirmationBox() = default;

    QString m_confirmationKey;

    StandardButton execute();
};

#endif // QXCONFIRMATIONBOX_H
