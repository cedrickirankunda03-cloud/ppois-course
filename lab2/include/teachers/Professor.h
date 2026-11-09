#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Teacher.h"
#include <string>

class TeacherResearch;


class Professor : public Teacher {
private:
    std::string academicRank;
    std::string researchField;
    int yearsOfExperience;
    int publications;

    TeacherResearch* research = nullptr;
public:
    Professor(
        const std::string& id,
        const std::string& first,
        const std::string& last,
        const std::string& department,
        const std::string& specialization,
        double salary,
        const std::string& rank,
        const std::string& research,
        int experience,
        int publications
    );

    std::string getAcademicRank() const;
    std::string getResearchField() const;
    int getPublications() const;

    void addPublication();
    void updateAcademicRank(const std::string& rank);

    void displayProfessorInformation() const;
};

#endif
