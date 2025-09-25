/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "mainwindow.h"

#include <QAction>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenuBar>
#include <QPushButton>
#include <QToolBar>

#include <qxpanelpalette.h>
#include <qxpanelunit.h>

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

    QLabel* labelResult = new QLabel(tr("<click button>"));
    labelResult->setObjectName("labelResult"_L1);

    QHBoxLayout* layoutLabel = new QHBoxLayout;
    layoutLabel->setObjectName("layoutLabel"_L1);
    layoutLabel->addWidget(labelResult, Qt::AlignCenter);

    QxPanelUnit* unitLabel = new QxPanelUnit;
    unitLabel->setObjectName("unitLabel"_L1);
    unitLabel->setUnitType(QxPanelUnit::FrameBox);
    unitLabel->setUnitTitle(tr("Label"));
    unitLabel->setLayout(layoutLabel);

    QPushButton* buttonNo1 = new QPushButton(tr("#1"));
    buttonNo1->setObjectName("buttonNo1"_L1);

    QPushButton* buttonNo2 = new QPushButton(tr("#2"));
    buttonNo2->setObjectName("buttonNo2"_L1);

    QHBoxLayout* layoutButtons = new QHBoxLayout;
    layoutButtons->setObjectName("layoutButtons"_L1);
    layoutButtons->addWidget(buttonNo1);
    layoutButtons->addWidget(buttonNo2);

    QxPanelUnit* unitButtons = new QxPanelUnit;
    unitButtons->setObjectName("unitButtons"_L1);
    unitButtons->setUnitType(QxPanelUnit::GroupBox);
    unitButtons->setUnitTitle(tr("Buttons"));
    unitButtons->setLayout(layoutButtons);

    QxPanelPalette* panelLabelButtons = new QxPanelPalette(tr("Label && Buttons Panel"), this);
    panelLabelButtons->setObjectName("panelLabelButtons"_L1);
    panelLabelButtons->addUnit(unitLabel);
    panelLabelButtons->addUnit(unitButtons);
    addDockWidget(Qt::RightDockWidgetArea, panelLabelButtons);

    connect(buttonNo1, &QPushButton::clicked, [=]() {
        labelResult->setText(tr("Button #1 clicked"));
    });
    connect(buttonNo2, &QPushButton::clicked, [=]() {
        labelResult->setText(tr("Button #2 clicked"));
    });

    setCentralWidget(new QWidget);

    //

    setMinimumSize(640, 480);
}
