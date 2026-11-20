
#include "teachers/LabAssistant.h"
#include <iostream>

using namespace std;

LabAssistant::LabAssistant(
    const std::string& id,
    const std::string& teacher,
    const std::string& room
)
    : assistantId(id),
      teacherId(teacher),
      assignedRoom(room)
{
}

const std::string& LabAssistant::getAssistantId() const {
    return assistantId;
}

const std::string& LabAssistant::getTeacherId() const {
    return teacherId;
}

const std::string& LabAssistant::getAssignedRoom() const {
    return assignedRoom;
}

void LabAssistant::displayInformation() const {
    cout << "\n===== LAB ASSISTANT =====" << endl;
    cout << "Assistant ID: " << assistantId << endl;
    cout << "Teacher ID: " << teacherId << endl;
    cout << "Assigned Room: " << assignedRoom << endl;
}

