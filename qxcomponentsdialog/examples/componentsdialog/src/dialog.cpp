/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "dialog.h"

#include <QDialogButtonBox>
#include <QPushButton>
#include <QScrollArea>
#include <QTabWidget>
#include <QVBoxLayout>

#include <qxcomponentsdialog.h>

using namespace Qt::Literals::StringLiterals;


Dialog::Dialog(QWidget* parent)
    : QDialog{parent}
{
    // Editor

    m_textEditor = new QPlainTextEdit;

    QScrollArea* areaPlaceholders = new QScrollArea;

    QTabWidget* tabBox = new QTabWidget;
    tabBox->addTab(m_textEditor, "Editor"_L1);
    tabBox->addTab(areaPlaceholders, "Placeholders"_L1);

    // Buttons

    QPushButton* buttonComponentsDialog = new QPushButton("Components Dialog"_L1);

    QDialogButtonBox* buttonBox = new QDialogButtonBox;
    buttonBox->addButton(buttonComponentsDialog, QDialogButtonBox::ActionRole);
    buttonBox->addButton(QDialogButtonBox::Close);

    connect(buttonComponentsDialog, &QPushButton::clicked, this, &Dialog::showComponentsDialog);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &Dialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(tabBox);
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle("Example of QxComponentsDialog"_L1);
    setMinimumSize(320, 240);
}


void Dialog::showComponentsDialog()
{
    QxComponentsDialog dialog(this);
    dialog.exec();
}
