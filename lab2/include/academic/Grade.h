#ifndef GRADE_H
#define GRADE_H

#include <string>

class Grade {
private:
    std::string studentId;
    std::string subjectCode;
    double score;
    std::string letterGrade;

    void calculateLetterGrade();

public:
    Grade(
        const std::string& studentId,
        const std::string& subjectCode,
        double score
    );

    std::string getStudentId() const;
    std::string getSubjectCode() const;
    double getScore() const;
    std::string getLetterGrade() const;

    void setScore(double score);
    bool isPassing() const;
};

#endif