
#ifndef LECTURER_H
#define LECTURER_H

#include "teachers/Teacher.h"
#include <string>

class Lecturer : public Teacher {
private:
    int weeklyTeachingHours;
    int coursesAssigned;
    std::string teachingLevel;

public:
    Lecturer(
        const std::string& id,
        const std::string& first,
        const std::string& last,
        const std::string& department,
        const std::string& specialization,
        double salary,
        int hours,
        int courses,
        const std::string& level
    );

    int getWeeklyTeachingHours() const;
    int getCoursesAssigned() const;
    std::string getTeachingLevel() const;

    void assignCourse();
    void updateTeachingHours(int hours);

    void displayLecturerInformation() const;
};

#endif
