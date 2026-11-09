#include "academic/GradeBook.h"

#include <stdexcept>
#include <algorithm>

GradeBook::GradeBook(
    const std::string& id,
    const std::string& studentId
)
    : gradeBookId(id),
      studentId(studentId)
{
    if (id.empty() || studentId.empty())
    {
        throw std::invalid_argument(
            "Invalid grade book information"
        );
    }
}

void GradeBook::addGrade(const std::string& grade)
{
    if (grade.empty())
    {
        throw std::invalid_argument("Grade cannot be empty");
    }

    gradeRecords.push_back(grade);
}

void GradeBook::removeGrade(const std::string& grade)
{
    auto it = std::find(
        gradeRecords.begin(),
        gradeRecords.end(),
        grade
    );

    if (it == gradeRecords.end())
    {
        throw std::invalid_argument("Grade not found");
    }

    gradeRecords.erase(it);
}

bool GradeBook::containsGrade(const std::string& grade) const
{
    return std::find(
        gradeRecords.begin(),
        gradeRecords.end(),
        grade
    ) != gradeRecords.end();
}

int GradeBook::getGradeCount() const
{
    return static_cast<int>(gradeRecords.size());
}

void GradeBook::clearGrades()
{
    gradeRecords.clear();
}