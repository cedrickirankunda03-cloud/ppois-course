
#ifndef LAB_ASSISTANT_H
#define LAB_ASSISTANT_H

#include <string>

class LabAssistant {
private:
    std::string assistantId;
    std::string teacherId;
    std::string assignedRoom;

public:
    LabAssistant(
        const std::string& id,
        const std::string& teacher,
        const std::string& room
    );

    const std::string& getAssistantId() const;
    const std::string& getTeacherId() const;
    const std::string& getAssignedRoom() const;

    void displayInformation() const;
};

#endif
