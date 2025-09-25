/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "qxpanelpalette.h"

#include <QGroupBox>
#include <QLayoutItem>
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;


QxPanelPalette::QxPanelPalette(QWidget* parent, Qt::WindowFlags flags)
    : QDockWidget{parent, flags}
    , m_paletteDisplayMode{PaletteDisplayMode::NoMode}
    , m_paletteDisplayDirection{QBoxLayout::TopToBottom}
    , m_listUnits{}
{
    QBoxLayout* layout = new QBoxLayout(m_paletteDisplayDirection);
    layout->setObjectName("layout"_L1);

    QWidget* widget = new QWidget;
    widget->setObjectName("widget"_L1);
    widget->setLayout(layout);

    setWidget(widget);
}

QxPanelPalette::QxPanelPalette(const QString& title, QWidget* parent, Qt::WindowFlags flags)
    : QxPanelPalette{parent, flags}
{
    setWindowTitle(title);
}


QxPanelPalette::PaletteDisplayMode QxPanelPalette::paletteDisplayMode() const
{
    return m_paletteDisplayMode;
}

void QxPanelPalette::setPaletteDisplayMode(const PaletteDisplayMode mode)
{
    if (mode == m_paletteDisplayMode)
        return;

    m_paletteDisplayMode = mode;

    updateLayout();

    emit paletteDisplayModeChanged(m_paletteDisplayMode);
}


QBoxLayout::Direction QxPanelPalette::paletteDisplayDirection() const
{
    return m_paletteDisplayDirection;
}

void QxPanelPalette::setPaletteDisplayDirection(const QBoxLayout::Direction direction)
{
    if (direction == m_paletteDisplayDirection)
        return;

    m_paletteDisplayDirection = direction;

    QBoxLayout* layout = qobject_cast<QBoxLayout*>(widget()->layout());
    layout->setDirection(m_paletteDisplayDirection);

    emit paletteDisplayDirectionChanged(m_paletteDisplayDirection);
}


int QxPanelPalette::addUnit(QxPanelUnit* unit)
{
    return insertUnit(-1, unit);
}


int QxPanelPalette::insertUnit(int index, QxPanelUnit* unit)
{
    if (index < -1 || index >= m_listUnits.count() || !unit)
        return -1;

    if (index >= 0)
        m_listUnits.insert(index, unit);
    else
        m_listUnits.append(unit);

    updateLayout();

    return m_listUnits.indexOf(unit);
}


void QxPanelPalette::removeUnit(const int index)
{
    if (index < 0 || index >= m_listUnits.count())
        return;

    m_listUnits.removeAt(index);

    updateLayout();
}


void QxPanelPalette::updateLayout()
{
    if (!(widget() && widget()->layout()))
        return;

    QBoxLayout* layout = qobject_cast<QBoxLayout*>(widget()->layout());

    QLayoutItem* layoutItem;
    while ((layoutItem = layout->takeAt(0)) != nullptr) {
        if (layoutItem->widget()) {
            if (layoutItem->widget()->layout())
                while ((layoutItem->widget()->layout()->takeAt(0)) != nullptr);
            layoutItem->widget()->deleteLater();
        }
        delete layoutItem;
    }

    QList<QxPanelUnit*> units = m_listUnits;
    for (QxPanelUnit* unit : units) {

        if (m_paletteDisplayMode == QxPanelPalette::NoBoxes ||
            (m_paletteDisplayMode == QxPanelPalette::NoMode && unit->unitType() == QxPanelUnit::NoType)) {

            QVBoxLayout* layoutNoBox = new QVBoxLayout;
            layoutNoBox->setObjectName("layoutNoBox"_L1);
            layoutNoBox->setContentsMargins(0, 0, 0, 0);
            layoutNoBox->addWidget(unit);

            QWidget* noBox = new QWidget;
            noBox->setObjectName("noBox"_L1);
            noBox->setLayout(layoutNoBox);

            layout->addWidget(noBox);
        }
        else if (m_paletteDisplayMode == QxPanelPalette::FlatBoxes ||
                 (m_paletteDisplayMode == QxPanelPalette::NoMode && unit->unitType() == QxPanelUnit::FlatBox)) {

            QVBoxLayout* layoutFlatBox = new QVBoxLayout;
            layoutFlatBox->setObjectName("layoutFlatBox"_L1);
            layoutFlatBox->addWidget(unit);

            QGroupBox* flatBox = new QGroupBox;
            flatBox->setObjectName("flatBox"_L1);
            flatBox->setLayout(layoutFlatBox);
            flatBox->setFlat(true);

            layout->addWidget(flatBox);
        }
        else if (m_paletteDisplayMode == QxPanelPalette::FrameBoxes ||
                 (m_paletteDisplayMode == QxPanelPalette::NoMode && unit->unitType() == QxPanelUnit::FrameBox)) {

            QVBoxLayout* layoutFrameBox = new QVBoxLayout;
            layoutFrameBox->setObjectName("layoutFrameBox"_L1);
            layoutFrameBox->addWidget(unit);

            QGroupBox* frameBox = new QGroupBox;
            frameBox->setObjectName("frameBox"_L1);
            frameBox->setLayout(layoutFrameBox);

            layout->addWidget(frameBox);
        }
        else if (m_paletteDisplayMode == QxPanelPalette::GroupBoxes ||
                 (m_paletteDisplayMode == QxPanelPalette::NoMode && unit->unitType() == QxPanelUnit::GroupBox)) {

            QVBoxLayout* layoutGroupBox = new QVBoxLayout;
            layoutGroupBox->setObjectName("layoutGroupBox"_L1);
            layoutGroupBox->addWidget(unit);

            QGroupBox* groupBox = new QGroupBox(unit->unitTitle());
            groupBox->setObjectName("groupBox"_L1);
            groupBox->setLayout(layoutGroupBox);

            layout->addWidget(groupBox);
        }
    }

    layout->addStretch();
    layout->setDirection(m_paletteDisplayDirection);
}
