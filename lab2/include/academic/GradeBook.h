#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>
#include <vector>

class GradeBook {
private:
    std::string gradeBookId;
    std::string studentId;
    std::vector<std::string> gradeRecords;

public:
    GradeBook(
        const std::string& id,
        const std::string& studentId
    );

    void addGrade(const std::string& grade);
    void removeGrade(const std::string& grade);
    bool containsGrade(const std::string& grade) const;
    int getGradeCount() const;
    void clearGrades();
};

#endif