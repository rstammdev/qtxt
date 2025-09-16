/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "mainwindow.h"

#include <QMenuBar>
#include <QToolBar>

using namespace Qt::Literals::StringLiterals;


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{

    QMenu* menuFile = menuBar()->addMenu(tr("&File"));
    menuFile->setObjectName("menuFile"_L1);

    QToolBar* toolbarFile = addToolBar(tr("File Toolbar"));
    toolbarFile->setObjectName("toolbarFile"_L1);

    setMinimumSize(640, 480);
}
