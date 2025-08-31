/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <QApplication>

#include "dialog.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Dialog dialog;
    dialog.show();

    return app.exec();
}
