/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "mainwindow.h"

#include <QAction>
#include <QApplication>
#include <QLabel>
#include <QMenuBar>
#include <QToolBar>
#include <QVBoxLayout>

#include <qxaboutdialog.h>

using namespace Qt::Literals::StringLiterals;


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
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

    // Help menu & toolbar

    QAction* actionAbout = addAction(tr("&About %1").arg(QApplication::applicationName()));
    actionAbout->setObjectName("actionAbout"_L1);
    actionAbout->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout));
    actionAbout->setIconText(tr("About"));
    actionAbout->setMenuRole(QAction::AboutRole);

    QMenu* menuHelp = menuBar()->addMenu(tr("&Help"));
    menuHelp->setObjectName("menuHelp"_L1);
    menuHelp->addAction(actionAbout);

    QToolBar* toolbarHelp = addToolBar(tr("Help Toolbar"));
    toolbarHelp->setObjectName("toolbarHelp"_L1);
    toolbarHelp->addAction(actionAbout);

    connect(actionAbout, &QAction::triggered, this, &MainWindow::showAboutDialog);

    //

    setWindowIcon(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout));
    resize(640, 480);
}


void MainWindow::showAboutDialog()
{
    QxAboutDialog dialog(this);
    dialog.setSubTitle(tr("v1.2.3"));
    dialog.setDescription(tr("This is an example in action"));
    dialog.addPage(pageLoremIpsum(), tr("Lorem Ipsum"));
    dialog.exec();
}


QWidget *MainWindow::pageLoremIpsum()
{
    QLabel* paragraph1 = new QLabel;
    paragraph1->setText(tr("Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor."));
    paragraph1->setWordWrap(true);

    QLabel* paragraph2 = new QLabel;
    paragraph2->setText(tr("Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus."));
    paragraph2->setWordWrap(true);

    QLabel* paragraph3 = new QLabel;
    paragraph3->setText(tr("Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim."));
    paragraph3->setWordWrap(true);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(paragraph1);
    layout->addWidget(paragraph2);
    layout->addWidget(paragraph3);
    layout->addStretch();

    QWidget* page = new QWidget;
    page->setLayout(layout);

    return page;
}
