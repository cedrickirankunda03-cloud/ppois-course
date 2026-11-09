
#include "teachers/TeacherSchedule.h"

#include <algorithm>
#include <stdexcept>

TeacherSchedule::TeacherSchedule(const std::string& teacherId)
    : teacherId(teacherId) {

    if (teacherId.empty()) {
        throw std::invalid_argument("Teacher ID cannot be empty.");
    }
}

std::string TeacherSchedule::getTeacherId() const {
    return teacherId;
}

void TeacherSchedule::addLesson(const std::string& lesson) {
    if (lesson.empty()) {
        throw std::invalid_argument("Lesson cannot be empty.");
    }

    lessons.push_back(lesson);
}

void TeacherSchedule::removeLesson(const std::string& lesson) {
    auto it = std::find(lessons.begin(), lessons.end(), lesson);

    if (it != lessons.end()) {
        lessons.erase(it);
    }
}

int TeacherSchedule::getLessonCount() const {
    return static_cast<int>(lessons.size());
}

std::vector<std::string> TeacherSchedule::getLessons() const {
    return lessons;
}
