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

#include <qxtoolpalette.h>

using namespace Qt::Literals::StringLiterals;


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow{parent}
{
    // File menu & toolbar

    QAction* actionQuit = addAction(tr("&Quit"));
    actionQuit->setObjectName("actionQuit"_L1);
    actionQuit->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
    actionQuit->setIconText(tr("Quit"));
    actionQuit->setShortcut(QKeySequence::Quit);
    actionQuit->setMenuRole(QAction::QuitRole);

    QMenu* menuFile = menuBar()->addMenu(tr("&File"));
    menuFile->setObjectName("menuFile"_L1);
    menuFile->addAction(actionQuit);

    QToolBar* toolbarFile = addToolBar(tr("File Toolbar"));
    toolbarFile->setObjectName("toolbarFile"_L1);
    toolbarFile->addAction(actionQuit);

    connect(actionQuit, &QAction::triggered, this, &MainWindow::close);

    // Information tool palette

    QxToolPalette* paletteInformation = new QxToolPalette(tr("Information"));
    actionQuit->setObjectName("paletteInformation"_L1);
    addDockWidget(Qt::RightDockWidgetArea, paletteInformation);

    //

    setCentralWidget(new QWidget);

    resize(640, 480);
}
