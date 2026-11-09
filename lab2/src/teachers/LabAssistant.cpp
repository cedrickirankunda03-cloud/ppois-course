
#include "teachers/LabAssistant.h"
#include <iostream>

using namespace std;

LabAssistant::LabAssistant(
    const string& id,
    const string& teacher,
    const string& room
)
    : assistantId(id),
      teacherId(teacher),
      assignedRoom(room)
{
}

string LabAssistant::getAssistantId() const {
    return assistantId;
}

string LabAssistant::getTeacherId() const {
    return teacherId;
}

string LabAssistant::getAssignedRoom() const {
    return assignedRoom;
}

void LabAssistant::displayInformation() const {
    cout << "\n===== LAB ASSISTANT =====" << endl;
    cout << "Assistant ID: " << assistantId << endl;
    cout << "Teacher ID: " << teacherId << endl;
    cout << "Assigned Room: " << assignedRoom << endl;
}

