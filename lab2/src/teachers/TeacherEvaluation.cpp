
#include "teachers/TeacherEvaluation.h"
#include <iostream>
#include <stdexcept>

// Constructor
TeacherEvaluation::TeacherEvaluation(
    const std::string& id,
    const std::string& teacher,
    const std::string& date,
    double score,
    const std::string& comments
)
    : evaluationId(id),
      teacherId(teacher),
      evaluationDate(date),
      teachingScore(score),
      comments(comments)
{
    if (score < 0.0 || score > 10.0) {
        throw std::invalid_argument("Teaching score must be between 0 and 10.");
    }
}

// Getters
std::string TeacherEvaluation::getEvaluationId() const {
    return evaluationId;
}

std::string TeacherEvaluation::getTeacherId() const {
    return teacherId;
}

double TeacherEvaluation::getTeachingScore() const {
    return teachingScore;
}

std::string TeacherEvaluation::getComments() const {
    return comments;
}

// Update teaching score
void TeacherEvaluation::updateScore(double score) {
    if (score < 0.0 || score > 10.0) {
        throw std::invalid_argument("Teaching score must be between 0 and 10.");
    }

    teachingScore = score;
}

// Update evaluation comments
void TeacherEvaluation::updateComments(const std::string& newComments) {
    comments = newComments;
}

// Display evaluation information
void TeacherEvaluation::displayEvaluationInformation() const {
    std::cout << "\n========== TEACHER EVALUATION ==========\n";
    std::cout << "Evaluation ID: " << evaluationId << '\n';
    std::cout << "Teacher ID: " << teacherId << '\n';
    std::cout << "Evaluation Date: " << evaluationDate << '\n';
    std::cout << "Teaching Score: " << teachingScore << "/10\n";
    std::cout << "Comments: " << comments << '\n';
    std::cout << "========================================\n";
}
