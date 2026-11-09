#ifndef NOTIFICATIONSERVICE_H
#define NOTIFICATIONSERVICE_H

#include <string>

class NotificationService {
private:
    std::string serviceName;
    int notificationsSent;

public:
    NotificationService(const std::string& name);

    void notifyStudent(const std::string& studentId,
                       const std::string& message);

    void notifyTeacher(const std::string& teacherId,
                       const std::string& message);

    int getNotificationsSent() const;
    void resetCounter();
};

#endif