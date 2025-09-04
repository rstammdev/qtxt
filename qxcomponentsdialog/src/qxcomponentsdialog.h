/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXCOMPONENTSDIALOG_H
#define QXCOMPONENTSDIALOG_H

#include <QDialog>
#include <QList>
#include <QPlainTextEdit>


class QxComponentsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QxComponentsDialog(QWidget* parent = nullptr);
    ~QxComponentsDialog() = default;

    static const QList<QStringList> placeholders();

    static const QString replacePlaceholders(const QString& text);

private slots:
    void copyToClipboard();

private:
    QPlainTextEdit* m_textViewer;

    static const QString buildQtVersion();
    static const QString currentQtVersion();
    static const QString prettyPlatformName();
};

#endif // QXCOMPONENTSDIALOG_H
