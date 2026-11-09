#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>

class Notification {
private:
    std::string notificationId;
    std::string studentId;
    std::string message;

public:
    Notification(
        const std::string& id,
        const std::string& studentId,
        const std::string& message
    );

    std::string getMessage() const;
    void updateMessage(const std::string& newMessage);
};

#endif