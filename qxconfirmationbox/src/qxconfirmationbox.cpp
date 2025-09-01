/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxconfirmationbox.h"

#include <QCheckBox>
#include <QPushButton>
#include <QSettings>

using namespace Qt::Literals::StringLiterals;


QMessageBox::StandardButton QxConfirmationBox::continueCancelInformation(QWidget* parent, const QString& title, const QString& text, const QString& informativeText, const QString& key)
{
    return continueCancel(parent, QMessageBox::Information, title, text, informativeText, key);
}

QMessageBox::StandardButton QxConfirmationBox::continueCancelWarning(QWidget* parent, const QString& title, const QString& text, const QString& informativeText, const QString& key)
{
    return continueCancel(parent, QMessageBox::Warning, title, text, informativeText, key);
}

QMessageBox::StandardButton QxConfirmationBox::continueCancelCritical(QWidget* parent, const QString& title, const QString& text, const QString& informativeText, const QString& key)
{
    return continueCancel(parent, QMessageBox::Critical, title, text, informativeText, key);
}

QMessageBox::StandardButton QxConfirmationBox::continueCancel(QWidget* parent, const Icon icon, const QString& title, const QString& text, const QString& informativeText, const QString& key)
{
    QxConfirmationBox messageBox(key, parent);
    messageBox.setIcon(icon);
    messageBox.setWindowTitle(title);
    messageBox.setText(text);
    messageBox.setInformativeText(informativeText);
    messageBox.addButton(QMessageBox::Cancel);

    QPushButton* buttonContinue = messageBox.addButton(QMessageBox::Ok);
    buttonContinue->setText(tr("C&ontinue"));
    buttonContinue->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::GoNext));
    messageBox.setDefaultButton(buttonContinue);

    return messageBox.execute();
}


QxConfirmationBox::QxConfirmationBox(const QString& key, QWidget* parent)
    : QMessageBox{parent}
    , m_confirmationKey{key}
{
    if (!m_confirmationKey.isEmpty())
        setCheckBox(new QCheckBox(tr("Do not show this message again")));

    setStyleSheet("QDialogButtonBox{min-width: 500px;}"_L1);
}


QMessageBox::StandardButton QxConfirmationBox::execute()
{
    QSettings settings;

    if (!m_confirmationKey.isEmpty() && !settings.value(m_confirmationKey, true).toBool())
        return standardButton(defaultButton());

    exec();

    if (!m_confirmationKey.isEmpty())
        settings.setValue(m_confirmationKey, !checkBox()->isChecked());

    return standardButton(clickedButton());
}
