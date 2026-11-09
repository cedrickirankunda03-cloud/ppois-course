#ifndef SEMESTER_H
#define SEMESTER_H

#include <string>

class Semester {
private:
    std::string id;
    std::string name;
    std::string startDate;
    std::string endDate;
    bool active;

public:
    Semester(
        const std::string& id,
        const std::string& name,
        const std::string& startDate,
        const std::string& endDate
    );

    std::string getId() const;
    std::string getName() const;
    std::string getStartDate() const;
    std::string getEndDate() const;
    bool isActive() const;

    void setName(const std::string& name);
    void setDates(
        const std::string& startDate,
        const std::string& endDate
    );

    void activate();
    void deactivate();
};

#endif