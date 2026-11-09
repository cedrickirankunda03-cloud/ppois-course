#ifndef GRADUATE_STUDENT_H
#define GRADUATE_STUDENT_H

#include "Student.h"
#include <string>

class GraduateStudent : public Student {
private:
    std::string researchArea;
    std::string thesisTitle;
    std::string supervisorName;
    int researchProgress;
    bool thesisSubmitted;

public:
    GraduateStudent(
        const std::string& id,
        const std::string& first,
        const std::string& last,
        int year,
        const std::string& research,
        const std::string& thesis,
        const std::string& supervisor
    );

    std::string getResearchArea() const;
    std::string getThesisTitle() const;
    int getResearchProgress() const;

    void updateResearchProgress(int progress);
    void changeThesisTitle(const std::string& newTitle);
    void submitThesis();

    bool isThesisSubmitted() const;

    void displayInformation() const override;
};

#endif