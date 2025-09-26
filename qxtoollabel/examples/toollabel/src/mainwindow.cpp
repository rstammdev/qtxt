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
#include <QToolButton>

#include <qxtoollabel.h>

using namespace Qt::Literals::StringLiterals;


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow{parent}
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

    QxToolLabel* labelButtons = new QxToolLabel;
    labelButtons->setObjectName("labelButtons"_L1);
    labelButtons->setText(tr("Buttons"));
    labelButtons->setFontBold(true);

    QToolButton* buttonButton1 = new QToolButton;
    buttonButton1->setObjectName("buttonButton1"_L1);
    buttonButton1->setText(tr("Button 1"));

    QToolButton* buttonButton2 = new QToolButton;
    buttonButton2->setObjectName("buttonButton2"_L1);
    buttonButton2->setText(tr("Button 2"));

    QToolBar* toolbarButtons = addToolBar(tr("Buttons Toolbar"));
    toolbarButtons->setObjectName("toolbarButtons"_L1);
    toolbarButtons->addWidget(labelButtons);
    toolbarButtons->addWidget(buttonButton1);
    toolbarButtons->addWidget(buttonButton2);

    //

    setMinimumSize(640, 480);
}
