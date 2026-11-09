#include "academic/Grade.h"
#include <stdexcept>

Grade::Grade(
    const std::string& studentId,
    const std::string& subjectCode,
    double score
) : studentId(studentId),
    subjectCode(subjectCode),
    score(score) {

    if (studentId.empty() || subjectCode.empty()) {
        throw std::invalid_argument(
            "Student ID and subject code cannot be empty"
        );
    }

    if (score < 0 || score > 100) {
        throw std::invalid_argument(
            "Score must be between 0 and 100"
        );
    }

    calculateLetterGrade();
}

std::string Grade::getStudentId() const {
    return studentId;
}

std::string Grade::getSubjectCode() const {
    return subjectCode;
}

double Grade::getScore() const {
    return score;
}

std::string Grade::getLetterGrade() const {
    return letterGrade;
}

void Grade::setScore(double score) {
    if (score < 0 || score > 100) {
        throw std::invalid_argument(
            "Score must be between 0 and 100"
        );
    }

    this->score = score;
    calculateLetterGrade();
}

void Grade::calculateLetterGrade() {
    if (score >= 90) {
        letterGrade = "A";
    } else if (score >= 80) {
        letterGrade = "B";
    } else if (score >= 70) {
        letterGrade = "C";
    } else if (score >= 60) {
        letterGrade = "D";
    } else {
        letterGrade = "F";
    }
}

bool Grade::isPassing() const {
    return score >= 60;
}