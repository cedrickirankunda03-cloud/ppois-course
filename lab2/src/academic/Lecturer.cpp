#include "academic/Lecturer.h"
#include <iostream>

using namespace std;

// Constructor
Lecturer::Lecturer(
    const string& id,
    const string& first,
    const string& last,
    const string& department,
    const string& specialization,
    double salary,
    int hours,
    int courses,
    const string& level
)
    : Teacher(id, first, last, department, specialization, salary),
      weeklyTeachingHours(hours),
      coursesAssigned(courses),
      teachingLevel(level)
{
}

// Getters
int Lecturer::getWeeklyTeachingHours() const {
    return weeklyTeachingHours;
}

int Lecturer::getCoursesAssigned() const {
    return coursesAssigned;
}

string Lecturer::getTeachingLevel() const {
    return teachingLevel;
}

// Assign a course
void Lecturer::assignCourse() {
    coursesAssigned++;
}

// Update weekly teaching hours
void Lecturer::updateTeachingHours(int hours) {
    if (hours >= 0) {
        weeklyTeachingHours = hours;
    }
}

// Display lecturer information
void Lecturer::displayLecturerInformation() const {
    cout << "\n===== LECTURER INFORMATION =====" << endl;

    displayInformation();

    cout << "Weekly Teaching Hours: "
         << weeklyTeachingHours << endl;

    cout << "Courses Assigned: "
         << coursesAssigned << endl;

    cout << "Teaching Level: "
         << teachingLevel << endl;
}
