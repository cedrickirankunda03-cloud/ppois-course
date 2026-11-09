
#include "teachers/Curator.h"
#include <iostream>

using namespace std;

Curator::Curator(
    const string& id,
    const string& group
)
    : curatorId(id),
      groupId(group)
{
}

string Curator::getCuratorId() const {
    return curatorId;
}

string Curator::getGroupId() const {
    return groupId;
}

void Curator::displayInformation() const {
    cout << "\n===== CURATOR INFORMATION =====" << endl;
    cout << "Curator ID: " << curatorId << endl;
    cout << "Group ID: " << groupId << endl;
}

