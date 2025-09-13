/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <QApplication>

#include "dialog.h"

using namespace Qt::Literals::StringLiterals;


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("QtXt-Examples"_L1);
    app.setApplicationName("HeadingLabel"_L1);
    app.setApplicationDisplayName("HeadingLabel"_L1);

    Dialog dialog;
    dialog.show();

    return app.exec();
}
