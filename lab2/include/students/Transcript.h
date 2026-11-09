#ifndef TRANSCRIPT_H
#define TRANSCRIPT_H

#include <string>
#include <vector>

#include "students/Student.h"
#include "academic/Grade.h"

class Transcript {
private:
    Student* student;
    std::vector<Grade> grades;
    std::string academicYear;

public:
    // Constructor
    Transcript(Student* student, const std::string& academicYear);

    // Assign student
    void setStudent(Student* student);

    // Add grade
    void addGrade(const Grade& grade);

    // Get all grades
    const std::vector<Grade>& getGrades() const;

    // Get academic year
    std::string getAcademicYear() const;
};

#endif