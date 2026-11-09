#include "academic/Timetable.h"

#include <stdexcept>

Timetable::Timetable(
    const std::string& subject,
    const std::string& day,
    const std::string& startTime,
    const std::string& endTime,
    const std::string& room
) {
    setSubject(subject);
    setDay(day);
    setTime(startTime, endTime);
    setRoom(room);
}

std::string Timetable::getSubject() const {
    return subject;
}

std::string Timetable::getDay() const {
    return day;
}

std::string Timetable::getStartTime() const {
    return startTime;
}

std::string Timetable::getEndTime() const {
    return endTime;
}

std::string Timetable::getRoom() const {
    return room;
}

void Timetable::setSubject(const std::string& subject) {
    if (subject.empty()) {
        throw std::invalid_argument("Subject cannot be empty");
    }

    this->subject = subject;
}

void Timetable::setDay(const std::string& day) {
    if (day.empty()) {
        throw std::invalid_argument("Day cannot be empty");
    }

    this->day = day;
}

void Timetable::setTime(
    const std::string& startTime,
    const std::string& endTime
) {
    if (startTime.empty() || endTime.empty()) {
        throw std::invalid_argument("Time cannot be empty");
    }

    this->startTime = startTime;
    this->endTime = endTime;
}

void Timetable::setRoom(const std::string& room) {
    if (room.empty()) {
        throw std::invalid_argument("Room cannot be empty");
    }

    this->room = room;
}