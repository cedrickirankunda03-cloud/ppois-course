#include "services/Notification.h"

#include <stdexcept>

Notification::Notification(
    const std::string& id,
    const std::string& studentId,
    const std::string& message
)
    : notificationId(id),
      studentId(studentId),
      message(message)
{
    if (id.empty() || studentId.empty() || message.empty())
    {
        throw std::invalid_argument(
            "Invalid notification information"
        );
    }
}

std::string Notification::getMessage() const
{
    return message;
}

void Notification::updateMessage(const std::string& newMessage)
{
    if (newMessage.empty())
    {
        throw std::invalid_argument(
            "Notification message cannot be empty"
        );
    }

    message = newMessage;
}