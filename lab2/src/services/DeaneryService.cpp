#include "services/DeaneryService.h"

#include <stdexcept>
#include <algorithm>

DeaneryService::DeaneryService(const std::string& name)
    : serviceName(name)
{
    if (name.empty())
    {
        throw std::invalid_argument(
            "Service name cannot be empty"
        );
    }
}

// STUDENTS

void DeaneryService::registerStudent(
    const std::string& studentId)
{
    if (studentId.empty() || hasStudent(studentId))
        throw std::invalid_argument("Invalid or duplicate student");

    studentIds.push_back(studentId);
}

void DeaneryService::removeStudent(
    const std::string& studentId)
{
    auto it = std::find(studentIds.begin(), studentIds.end(), studentId);

    if (it == studentIds.end())
        throw std::invalid_argument("Student not found");

    studentIds.erase(it);
}

bool DeaneryService::hasStudent(
    const std::string& studentId) const
{
    return std::find(studentIds.begin(), studentIds.end(),
                     studentId) != studentIds.end();
}

// TEACHERS

void DeaneryService::registerTeacher(
    const std::string& teacherId)
{
    if (teacherId.empty() || hasTeacher(teacherId))
        throw std::invalid_argument("Invalid or duplicate teacher");

    teacherIds.push_back(teacherId);
}

void DeaneryService::removeTeacher(
    const std::string& teacherId)
{
    auto it = std::find(teacherIds.begin(), teacherIds.end(), teacherId);

    if (it == teacherIds.end())
        throw std::invalid_argument("Teacher not found");

    teacherIds.erase(it);
}

bool DeaneryService::hasTeacher(
    const std::string& teacherId) const
{
    return std::find(teacherIds.begin(), teacherIds.end(),
                     teacherId) != teacherIds.end();
}

// GROUPS

void DeaneryService::registerGroup(
    const std::string& groupId)
{
    if (groupId.empty() || hasGroup(groupId))
        throw std::invalid_argument("Invalid or duplicate group");

    groupIds.push_back(groupId);
}

void DeaneryService::removeGroup(
    const std::string& groupId)
{
    auto it = std::find(groupIds.begin(), groupIds.end(), groupId);

    if (it == groupIds.end())
        throw std::invalid_argument("Group not found");

    groupIds.erase(it);
}

bool DeaneryService::hasGroup(
    const std::string& groupId) const
{
    return std::find(groupIds.begin(), groupIds.end(),
                     groupId) != groupIds.end();
}

// ORDERS

void DeaneryService::registerOrder(
    const std::string& orderId)
{
    if (orderId.empty() || hasOrder(orderId))
        throw std::invalid_argument("Invalid or duplicate order");

    orderIds.push_back(orderId);
}

void DeaneryService::removeOrder(
    const std::string& orderId)
{
    auto it = std::find(orderIds.begin(), orderIds.end(), orderId);

    if (it == orderIds.end())
        throw std::invalid_argument("Order not found");

    orderIds.erase(it);
}

bool DeaneryService::hasOrder(
    const std::string& orderId) const
{
    return std::find(orderIds.begin(), orderIds.end(),
                     orderId) != orderIds.end();
}