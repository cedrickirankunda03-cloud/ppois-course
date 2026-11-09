#ifndef EXAM_H
#define EXAM_H

#include <string>

class Exam {
private:
    std::string id;
    std::string subjectCode;
    std::string date;
    int durationMinutes;
    double maximumScore;

public:
    Exam(
        const std::string& id,
        const std::string& subjectCode,
        const std::string& date,
        int durationMinutes,
        double maximumScore
    );

    std::string getId() const;
    std::string getSubjectCode() const;
    std::string getDate() const;
    int getDurationMinutes() const;
    double getMaximumScore() const;

    void setDate(const std::string& date);
    void setDurationMinutes(int durationMinutes);
};

#endif