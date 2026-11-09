
#ifndef TEACHER_EVALUATION_H
#define TEACHER_EVALUATION_H

#include <string>

class TeacherEvaluation {
private:
    std::string evaluationId;
    std::string teacherId;
    std::string evaluationDate;
    double teachingScore;
    std::string comments;

public:
    TeacherEvaluation(
        const std::string& id,
        const std::string& teacher,
        const std::string& date,
        double score,
        const std::string& comments
    );

    std::string getEvaluationId() const;
    std::string getTeacherId() const;
    double getTeachingScore() const;
    std::string getComments() const;

    void updateScore(double score);
    void updateComments(const std::string& newComments);

    void displayEvaluationInformation() const;
};

#endif
