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
#include <QDate>
#include <QDateTime>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QSysInfo>
#include <QTime>
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;


QxComponentsDialog::QxComponentsDialog(QWidget* parent)
    : QDialog{parent}
{
    // Text

    m_textViewer = new QPlainTextEdit;
    m_textViewer->setFocusPolicy(Qt::NoFocus);
    m_textViewer->setReadOnly(true);

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
    layout->addWidget(m_textViewer);
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle(tr("Components"));
    setMinimumSize(640, 240);

    setText(defaultTemplate());
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


const QString QxComponentsDialog::replacePlaceholders(const QString& text)
{
    const QHash<QString, QString> values {
        { "%APPLICATION_NAME%"_L1, QApplication::applicationName() },
        { "%APPLICATION_VERSION%"_L1, QApplication::applicationVersion() },
        { "%QT_VERSION%"_L1, currentQtVersion() },
        { "%QT_BUILD_VERSION%"_L1, buildQtVersion() },
        { "%OS_PRODUCT_NAME%"_L1, QSysInfo::prettyProductName() },
        { "%OS_PRODUCT_TYPE%"_L1, QSysInfo::productType() },
        { "%OS_PRODUCT_VERSION%"_L1, QSysInfo::productVersion() },
        { "%OS_PLATFORM%"_L1, QApplication::platformName() },
        { "%OS_PLATFORM_NAME%"_L1, prettyPlatformName() },
        { "%OS_ARCHITECTURE%"_L1, QSysInfo::currentCpuArchitecture() },
        { "%OS_BUILD_ARCHITECTURE%"_L1, QSysInfo::buildCpuArchitecture() },
        { "%OS_BUILD_ARCHITECTURE_FULL%"_L1, QSysInfo::buildAbi() },
        { "%OS_KERNEL_TYPE%"_L1, QSysInfo::kernelType() },
        { "%OS_KERNEL_VERSION%"_L1, QSysInfo::kernelVersion() },
        { "%SYSTEM_DATE%"_L1, QDate::currentDate().toString() },
        { "%SYSTEM_TIME%"_L1, QTime::currentTime().toString() },
        { "%SYSTEM_DATE_TIME_UTC%"_L1, QDateTime::currentDateTimeUtc().toString() }
    };

    QString result = text;
    for (auto it = values.cbegin(), end = values.cend(); it != end; ++it)
        result.replace(it.key(), it.value());

    return result;
}


const QString QxComponentsDialog::defaultTemplate()
{
    return tr(
        "%APPLICATION_NAME% %APPLICATION_VERSION%\n"
        "Qt: Using %QT_VERSION% and built against %QT_BUILD_VERSION%\n"
        "OS: %OS_PRODUCT_NAME% (%OS_PLATFORM_NAME%)\n"
        "Build ABI: %OS_BUILD_ARCHITECTURE_FULL%\n"
        "Kernel: %OS_KERNEL_TYPE% %OS_KERNEL_VERSION%\n"
        "Created on %SYSTEM_DATE% at %SYSTEM_TIME%"
    );
}


void QxComponentsDialog::setText(const QString& text)
{
    m_textViewer->setPlainText(replacePlaceholders(text));
}


void QxComponentsDialog::copyToClipboard()
{
    if (!m_textViewer->toPlainText().isEmpty())
        QApplication::clipboard()->setText(m_textViewer->toPlainText());
}


const QString QxComponentsDialog::buildQtVersion()
{
    return QT_VERSION_STR;
}


const QString QxComponentsDialog::currentQtVersion()
{
    return qVersion();
}


const QString QxComponentsDialog::prettyPlatformName()
{
    const QString& platformName = QApplication::platformName();

    if (platformName == "wayland"_L1)
        return tr("Wayland");
    else if (platformName == "xcb"_L1)
        return tr("X11");

    return tr("Unknown (%1)").arg(platformName);
}
