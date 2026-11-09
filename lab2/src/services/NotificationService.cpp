#include "services/NotificationService.h"

#include <stdexcept>

NotificationService::NotificationService(const std::string& name)
    : serviceName(name),
      notificationsSent(0)
{
    if (name.empty())
    {
        throw std::invalid_argument(
            "Service name cannot be empty"
        );
    }
}

void NotificationService::notifyStudent(
    const std::string& studentId,
    const std::string& message)
{
    if (studentId.empty() || message.empty())
    {
        throw std::invalid_argument(
            "Invalid student notification"
        );
    }

    ++notificationsSent;
}

void NotificationService::notifyTeacher(
    const std::string& teacherId,
    const std::string& message)
{
    if (teacherId.empty() || message.empty())
    {
        throw std::invalid_argument(
            "Invalid teacher notification"
        );
    }

    ++notificationsSent;
}

int NotificationService::getNotificationsSent() const
{
    return notificationsSent;
}

void NotificationService::resetCounter()
{
    notificationsSent = 0;
}