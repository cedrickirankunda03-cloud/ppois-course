
#ifndef CURATOR_H
#define CURATOR_H

#include <string>

class StudentGroup;


class Curator {
private:
    std::string curatorId;
    std::string groupId;

    StudentGroup* group = nullptr;
public:
    Curator(
        const std::string& id,
        const std::string& group
    );

    std::string getCuratorId() const;
    std::string getGroupId() const;

    void displayInformation() const;
};

#endif
