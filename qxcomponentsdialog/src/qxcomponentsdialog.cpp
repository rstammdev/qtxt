/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxcomponentsdialog.h"

#include <QApplication>
#include <QClipboard>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;


QxComponentsDialog::QxComponentsDialog(QWidget* parent)
    : QDialog{parent}
{
    // Text

    m_textBox = new QPlainTextEdit;
    m_textBox->setFocusPolicy(Qt::NoFocus);
    m_textBox->setReadOnly(true);

    // Buttons

    QPushButton* buttonCopyToClipboard = new QPushButton(tr("Copy to Clipboard"));
    buttonCopyToClipboard->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::EditCopy));

    QDialogButtonBox* buttonBox = new QDialogButtonBox;
    buttonBox->addButton(buttonCopyToClipboard, QDialogButtonBox::ActionRole);
    buttonBox->addButton(QDialogButtonBox::Close);

    connect(buttonCopyToClipboard, &QPushButton::clicked, this, &QxComponentsDialog::copyToClipboard);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QxComponentsDialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(m_textBox);
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle(tr("Components"));
    setMinimumSize(640, 240);
}


const QList<QStringList> QxComponentsDialog::placeholders()
{
    return {
        { "%APPLICATION_NAME%"_L1, tr("The name of this application.") },
        { "%APPLICATION_VERSION%"_L1, tr("The version number of this application.") },
        { "%QT_VERSION%"_L1, tr("The version number of Qt at run-time.") },
        { "%QT_BUILD_VERSION%"_L1, tr("The version number of Qt against which the application is compiled.") },
        { "%OS_PRODUCT_NAME%"_L1, tr("A prettier form of the product name and version number of the operating system this application is running in.") },
        { "%OS_PRODUCT_TYPE%"_L1, tr("The product name of the operating system this application is running in.") },
        { "%OS_PRODUCT_VERSION%"_L1, tr("The product version of the operating system this application is running in.") },
        { "%OS_PLATFORM%"_L1, tr("The name of the underlying platform plugin.") },
        { "%OS_PLATFORM_NAME%"_L1, tr("A prettier form of the name of the underlying platform plugin.") },
        { "%OS_ARCHITECTURE%"_L1, tr("The architecture of the CPU that the application is running on.") },
        { "%OS_BUILD_ARCHITECTURE%"_L1, tr("The architecture of the CPU that Qt was compiled for.") },
        { "%OS_BUILD_ARCHITECTURE_FULL%"_L1, tr("The full architecture string that Qt was compiled for.") },
        { "%OS_KERNEL_TYPE%"_L1, tr("The type of the operating system kernel Qt was compiled for. It's also the kernel the application is running on.") },
        { "%OS_KERNEL_VERSION%"_L1, tr("The release version of the operating system kernel.") },
        { "%SYSTEM_DATE%"_L1, tr("The system clock's current date.") },
        { "%SYSTEM_TIME%"_L1, tr("The current time as reported by the system clock.") },
        { "%SYSTEM_DATE_TIME_UTC%"_L1, tr("The system clock's current datetime, expressed in terms of UTC.") }
    };
}


void QxComponentsDialog::copyToClipboard()
{
    if (!m_textBox->toPlainText().isEmpty())
        QApplication::clipboard()->setText(m_textBox->toPlainText());
}
