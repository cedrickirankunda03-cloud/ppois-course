
#include "../../include/teachers/TeacherResearch.h"
#include <iostream>
#include <string>

using namespace std;

TeacherResearch::TeacherResearch(
    const string& id,
    const string& teacher,
    const string& title,
    const string& publication,
    int year
)
    : researchId(id),
      teacherId(teacher),
      researchTitle(title),
      publication(publication),
      publicationYear(year)
{
}

string TeacherResearch::getResearchId() const {
    return researchId;
}

string TeacherResearch::getTeacherId() const {
    return teacherId;
}

string TeacherResearch::getResearchTitle() const {
    return researchTitle;
}

string TeacherResearch::getPublication() const {
    return publication;
}

int TeacherResearch::getPublicationYear() const {
    return publicationYear;
}

void TeacherResearch::updatePublication(const string& newPublication) {
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
