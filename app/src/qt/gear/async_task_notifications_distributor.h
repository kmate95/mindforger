/*
 async_task_notifications_distributor.h     MindForger thinking notebook

 Copyright (C) 2016-2018 Martin Dvorak <martin.dvorak@mindforger.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef M8RUI_ASYNC_TASK_NOTIFICATIONS_DISTRIBUTOR_H
#define M8RUI_ASYNC_TASK_NOTIFICATIONS_DISTRIBUTOR_H

#include <QThread>

namespace m8r {

/**
 * @brief Worker thread that distributes lib/backend async task/thread results to Qt GUI.
 *
 * IMPORTANT: you must work with Qt GUI only from GUI thread, that is main Qt thread.
 *
 * Therefore this distributor notifies GUI components using *signals* so that they
 * can be repainted() by the main Qt thread (signal is added to Qt event queue).
 */
class AsyncTaskNotificationsDistributor : public QThread
{
    Q_OBJECT

public:
    explicit AsyncTaskNotificationsDistributor(QWidget* parent);
    AsyncTaskNotificationsDistributor(const AsyncTaskNotificationsDistributor&) = delete;
    AsyncTaskNotificationsDistributor(const AsyncTaskNotificationsDistributor&&) = delete;
    AsyncTaskNotificationsDistributor &operator=(const AsyncTaskNotificationsDistributor&) = delete;
    AsyncTaskNotificationsDistributor &operator=(const AsyncTaskNotificationsDistributor&&) = delete;
    ~AsyncTaskNotificationsDistributor();
};

}
#endif // M8RUI_ASYNC_TASK_NOTIFICATIONS_DISTRIBUTOR_H