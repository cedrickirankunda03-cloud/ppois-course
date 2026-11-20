
#include "teachers/Curator.h"
#include <iostream>

using namespace std;

Curator::Curator(
    const std::string& id,
    const std::string& group
)
    : curatorId(id),
      groupId(group)
{
}

const std::string& Curator::getCuratorId() const {
    return curatorId;
}

const std::string& Curator::getGroupId() const {
    return groupId;
}

void Curator::displayInformation() const {
    cout << "\n===== CURATOR INFORMATION =====" << endl;
    cout << "Curator ID: " << curatorId << endl;
    cout << "Group ID: " << groupId << endl;
}

