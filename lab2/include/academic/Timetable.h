#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <string>

class Timetable {
private:
    std::string subject;
    std::string day;
    std::string startTime;
    std::string endTime;
    std::string room;

public:
    // Constructor
    Timetable(
        const std::string& subject,
        const std::string& day,
        const std::string& startTime,
        const std::string& endTime,
        const std::string& room
    );

    // Getters
    const std::string& getSubject() const;
    const std::string& getDay() const;
    const std::string& getStartTime() const;
    const std::string& getEndTime() const;
    const std::string& getRoom() const;

    // Setters
    void setSubject(const std::string& subject);
    void setDay(const std::string& day);
    void setTime(
        const std::string& startTime,
        const std::string& endTime
    );
    void setRoom(const std::string& room);
};

#endif