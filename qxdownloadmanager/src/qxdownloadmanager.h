/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/qtxt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef QXDOWNLOADMANAGER_H
#define QXDOWNLOADMANAGER_H

#include <QObject>


class QxDownloadManager : public QObject
{
    Q_OBJECT

public:
    explicit QxDownloadManager(QObject* parent = nullptr);
    ~QxDownloadManager();
};

#endif // QXDOWNLOADMANAGER_H
