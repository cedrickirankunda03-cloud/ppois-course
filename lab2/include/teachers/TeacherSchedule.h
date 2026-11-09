
#ifndef TEACHER_SCHEDULE_H
#define TEACHER_SCHEDULE_H

#include <string>
#include <vector>

class TeacherSchedule {
private:
    std::string teacherId;
    std::vector<std::string> lessons;

public:
    explicit TeacherSchedule(const std::string& teacherId);

    std::string getTeacherId() const;

    void addLesson(const std::string& lesson);
    void removeLesson(const std::string& lesson);

    int getLessonCount() const;
    std::vector<std::string> getLessons() const;
};

#endif
