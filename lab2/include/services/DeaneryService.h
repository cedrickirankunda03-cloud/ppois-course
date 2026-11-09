#ifndef DEANERYSERVICE_H
#define DEANERYSERVICE_H

#include <string>
#include <vector>

class NotificationService;
class ScholarshipManager;


class DeaneryService {
private:
    std::string serviceName;
    std::vector<std::string> studentIds;
    std::vector<std::string> teacherIds;
    std::vector<std::string> groupIds;
    std::vector<std::string> orderIds;

    NotificationService* notificationService = nullptr;
    ScholarshipManager* scholarshipManager = nullptr;
public:
    explicit DeaneryService(const std::string& name);

    void registerStudent(const std::string& studentId);
    void removeStudent(const std::string& studentId);
    bool hasStudent(const std::string& studentId) const;

    void registerTeacher(const std::string& teacherId);
    void removeTeacher(const std::string& teacherId);
    bool hasTeacher(const std::string& teacherId) const;

    void registerGroup(const std::string& groupId);
    void removeGroup(const std::string& groupId);
    bool hasGroup(const std::string& groupId) const;

    void registerOrder(const std::string& orderId);
    void removeOrder(const std::string& orderId);
    bool hasOrder(const std::string& orderId) const;
};

#endif
