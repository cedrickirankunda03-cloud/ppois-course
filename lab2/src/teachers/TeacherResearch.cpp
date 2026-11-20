
#include "../../include/teachers/TeacherResearch.h"
#include <iostream>
#include <string>

using namespace std;

TeacherResearch::TeacherResearch(
    const std::string& id,
    const std::string& teacher,
    const std::string& title,
    const std::string& publication,
    int year
)
    : researchId(id),
      teacherId(teacher),
      researchTitle(title),
      publication(publication),
      publicationYear(year)
{
}

const std::string& TeacherResearch::getResearchId() const {
    return researchId;
}

const std::string& TeacherResearch::getTeacherId() const {
    return teacherId;
}

const std::string& TeacherResearch::getResearchTitle() const {
    return researchTitle;
}

const std::string& TeacherResearch::getPublication() const {
    return publication;
}

int TeacherResearch::getPublicationYear() const {
    return publicationYear;
}

void TeacherResearch::updatePublication(const std::string& newPublication) {
    publication = newPublication;
}

void TeacherResearch::displayResearchInformation() const {
    cout << "\n===== TEACHER RESEARCH =====" << endl;
    cout << "Research ID: " << researchId << endl;
    cout << "Teacher ID: " << teacherId << endl;
    cout << "Research Title: " << researchTitle << endl;
    cout << "Publication: " << publication << endl;
    cout << "Publication Year: " << publicationYear << endl;
}
