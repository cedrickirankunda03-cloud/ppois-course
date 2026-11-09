#include "academic/ExamSheet.h"

#include <stdexcept>
#include <algorithm>

ExamSheet::ExamSheet(
    const std::string& id,
    const std::string& examId,
    const std::string& teacherId
)
    : examSheetId(id),
      examId(examId),
      teacherId(teacherId)
{
    if (id.empty() || examId.empty() || teacherId.empty())
    {
        throw std::invalid_argument(
            "Invalid exam sheet information"
        );
    }
}

void ExamSheet::addStudent(const std::string& studentId)
{
    if (studentId.empty() || containsStudent(studentId))
    {
        throw std::invalid_argument(
            "Invalid or duplicate student"
        );
    }

    studentIds.push_back(studentId);
}

void ExamSheet::removeStudent(const std::string& studentId)
{
    auto it = std::find(
        studentIds.begin(),
        studentIds.end(),
        studentId
    );

    if (it == studentIds.end())
    {
        throw std::invalid_argument("Student not found");
    }

    studentIds.erase(it);
}

bool ExamSheet::containsStudent(const std::string& studentId) const
{
    return std::find(
        studentIds.begin(),
        studentIds.end(),
        studentId
    ) != studentIds.end();
}

int ExamSheet::getStudentCount() const
{
    return static_cast<int>(studentIds.size());
}