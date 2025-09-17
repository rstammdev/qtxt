/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "mainwindow.h"

#include <QAction>
#include <QActionGroup>
#include <QFont>
#include <QKeySequence>
#include <QMenuBar>
#include <QToolBar>

#include <qxzoombutton.h>

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

    QAction* actionZoomIn = addAction(tr("Zoom &In"));
    actionZoomIn->setObjectName("actionZoomIn"_L1);
    actionZoomIn->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::ZoomIn));
    actionZoomIn->setShortcut(QKeySequence::ZoomIn);

    QAction* actionZoomOut = addAction(tr("Zoom &Out"));
    actionZoomOut->setObjectName("actionZoomOut"_L1);
    actionZoomOut->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::ZoomOut));
    actionZoomOut->setShortcut(QKeySequence::ZoomOut);

    QAction* actionResetZoom = addAction(tr("&Reset Zoom"));
    actionResetZoom->setObjectName("actionResetZoom"_L1);
    actionResetZoom->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::ZoomFitBest));
    actionResetZoom->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_0));
    actionResetZoom->setIconText(tr("%1%"));

    QMenu* menuView = menuBar()->addMenu(tr("&View"));
    menuView->setObjectName("menuView"_L1);
    menuView->addAction(actionZoomIn);
    menuView->addAction(actionZoomOut);
    menuView->addAction(actionResetZoom);

    QxZoomButton* buttonResetZoom = new QxZoomButton;
    buttonResetZoom->setObjectName("buttonResetZoom"_L1);
    buttonResetZoom->setDefaultAction(actionResetZoom);
    buttonResetZoom->setToolButtonStyle(Qt::ToolButtonTextOnly);

    QToolBar* toolbarView = addToolBar(tr("View Toolbar"));
    toolbarView->setObjectName("toolbarView"_L1);
    toolbarView->addAction(actionZoomOut);
    toolbarView->addWidget(buttonResetZoom);
    toolbarView->addAction(actionZoomIn);

    connect(actionZoomIn, &QAction::triggered, buttonResetZoom, &QxZoomButton::zoomIn);
    connect(actionZoomOut, &QAction::triggered, buttonResetZoom, &QxZoomButton::zoomOut);
    connect(actionResetZoom, &QAction::triggered, buttonResetZoom, &QxZoomButton::resetZoom);
    connect(buttonResetZoom, &QxZoomButton::zoomFactorChanged, this, &MainWindow::applyZoomFactor);

    QMenu* menuSettings = menuBar()->addMenu(tr("&Settings"));
    menuSettings->setObjectName("menuSettings"_L1);

    m_textEditor = new QPlainTextEdit;
    m_textEditor->setPlainText("Lorem ipsum dolor sit amet, consectetur adipiscing elit ..."_L1);
    setCentralWidget(m_textEditor);

    m_fontBasePointSize = m_textEditor->font().pointSizeF();
    if (m_fontBasePointSize <= 0)
        m_fontBasePointSize = 10.0;

    //

    setMinimumSize(600, 480);
}


void MainWindow::applyZoomFactor(const qreal factor)
{
    QFont font = m_textEditor->font();
    font.setPointSizeF(m_fontBasePointSize * factor);
    m_textEditor->setFont(font);
}
