
#ifndef TEACHER_RESEARCH_H
#define TEACHER_RESEARCH_H

#include <string>

class TeacherResearch {
private:
    std::string researchId;
    std::string teacherId;
    std::string researchTitle;
    std::string publication;
    int publicationYear;

public:
    TeacherResearch(
        const std::string& id,
        const std::string& teacher,
        const std::string& title,
        const std::string& publication,
        int year
    );

    const std::string& getResearchId() const;
    const std::string& getTeacherId() const;
    const std::string& getResearchTitle() const;
    const std::string& getPublication() const;
    int getPublicationYear() const;

    void updatePublication(const std::string& newPublication);

    void displayResearchInformation() const;
};

#endif
