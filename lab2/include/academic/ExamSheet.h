#ifndef EXAMSHEET_H
#define EXAMSHEET_H

#include <string>
#include <vector>

class ExamSheet {
private:
    std::string examSheetId;
    std::string examId;
    std::string teacherId;
    std::vector<std::string> studentIds;

public:
    ExamSheet(
        const std::string& id,
        const std::string& examId,
        const std::string& teacherId
    );

    void addStudent(const std::string& studentId);
    void removeStudent(const std::string& studentId);
    bool containsStudent(const std::string& studentId) const;
    int getStudentCount() const;
};

#endif