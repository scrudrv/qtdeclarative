/****************************************************************************
**
** Copyright (C) 2018 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QML preview debug service.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QQMLPREVIEWPOSITION_H
#define QQMLPREVIEWPOSITION_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qvector.h>
#include <QtCore/qpoint.h>
#include <QtCore/qurl.h>
#include <QtCore/qtimer.h>
#include <QtCore/qsettings.h>

QT_BEGIN_NAMESPACE

class QWindow;

class QQmlPreviewPosition
{
public:
    QQmlPreviewPosition();

    void setPosition(const QPoint &point);
    void saveWindowPosition();
    void loadWindowPositionSettings(const QUrl &url);
    void initLastSavedWindowPosition(QWindow *window);
    static const QSize currentScreenSize(QWindow *window);

private:
    bool m_hasPosition = false;
    QPoint m_lastWindowPosition;
    QSettings m_settings;
    QString m_settingsKey;
    QTimer m_savePositionTimer;
    QVector<QWindow *> m_positionedWindows;
};


QT_END_NAMESPACE

#endif // QQMLPREVIEWPOSITION_H
