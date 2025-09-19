/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "mainwindow.h"

#include <QAction>
#include <QMenuBar>
#include <QToolBar>

using namespace Qt::Literals::StringLiterals;


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    QAction* actionQuit = addAction(tr("&Quit"));
    actionQuit->setObjectName("actionQuit"_L1);
    actionQuit->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));

    QMenu* menuFile = menuBar()->addMenu(tr("&File"));
    menuFile->setObjectName("menuFile"_L1);
    menuFile->addAction(actionQuit);

    QToolBar* toolbarFile = addToolBar(tr("File Toolbar"));
    toolbarFile->setObjectName("toolbarFile"_L1);
    toolbarFile->addAction(actionQuit);

    connect(actionQuit, &QAction::triggered, this, &MainWindow::close);

    QMenu* menuView = menuBar()->addMenu(tr("&View"));
    menuView->setObjectName("menuView"_L1);

    //

    setMinimumSize(640, 480);
}
