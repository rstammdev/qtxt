/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "mainwindow.h"

#include <QAction>
#include <QLabel>
#include <QMenuBar>
#include <QToolBar>

#include <qxstatusbutton.h>

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

    QAction* actionFullScreen = addAction(tr("F&ull Screen"));
    actionFullScreen->setObjectName("actionFullScreen"_L1);
    actionFullScreen->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::ViewFullscreen));
    actionFullScreen->setIconText(tr("Full Screen"));
    actionFullScreen->setShortcut(QKeySequence::FullScreen);
    actionFullScreen->setCheckable(true);

    QMenu* menuView = menuBar()->addMenu(tr("&View"));
    menuView->setObjectName("menuView"_L1);
    menuView->addAction(actionFullScreen);

    QxStatusButton* buttonFullScreen = new QxStatusButton;
    buttonFullScreen->setObjectName("buttonFullScreen"_L1);
    buttonFullScreen->setDefaultAction(actionFullScreen);

    QToolBar* toolbarView = addToolBar(tr("View Toolbar"));
    toolbarView->setObjectName("toolbarView"_L1);
    toolbarView->addWidget(buttonFullScreen);

    connect(buttonFullScreen, &QxStatusButton::toggled, this, &MainWindow::toggleFullScreen);

    QLabel* labelFullScreen = new QLabel;
    labelFullScreen->setObjectName("labelFullScreen"_L1);
    labelFullScreen->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    setCentralWidget(labelFullScreen);

    //

    setMinimumSize(640, 480);

    toggleFullScreen(buttonFullScreen->isChecked());
}


void MainWindow::toggleFullScreen(const bool checked)
{
    QString state = checked ? tr("On") : tr("Off");

    qobject_cast<QLabel*>(centralWidget())->setText(tr("Full Screen is %1").arg(state));
}
