/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <QApplication>

#include "mainwindow.h"

using namespace Qt::Literals::StringLiterals;


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("QtXt-Examples"_L1);
    app.setApplicationName("DownloadManager"_L1);
    app.setApplicationDisplayName("DownloadManager"_L1);

    MainWindow window;
    window.show();

    return app.exec();
}
