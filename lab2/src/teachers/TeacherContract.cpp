
#include "teachers/TeacherContract.h"

#include <stdexcept>

TeacherContract::TeacherContract(
    const std::string& contractId,
    const std::string& teacherId,
    const std::string& contractType,
    const std::string& startDate,
    const std::string& endDate
)
    : contractId(contractId),
      teacherId(teacherId),
      contractType(contractType),
      startDate(startDate),
      endDate(endDate),
      active(true) {

    if (contractId.empty() || teacherId.empty()) {
        throw std::invalid_argument("Contract and teacher IDs are required.");
    }

    if (contractType.empty() || startDate.empty() || endDate.empty()) {
        throw std::invalid_argument("Contract information cannot be empty.");
    }
}

const std::string& TeacherContract::getContractId() const {
    return contractId;
}

const std::string& TeacherContract::getTeacherId() const {
    return teacherId;
}

const std::string& TeacherContract::getContractType() const {
    return contractType;
}

const std::string& TeacherContract::getStartDate() const {
    return startDate;
}

const std::string& TeacherContract::getEndDate() const {
    return endDate;
}

bool TeacherContract::isActive() const {
    return active;
}

void TeacherContract::activate() {
    active = true;
}

void TeacherContract::deactivate() {
    active = false;
}

void TeacherContract::updateEndDate(const std::string& newEndDate) {
    if (newEndDate.empty()) {
        throw std::invalid_argument("End date cannot be empty.");
    }

    endDate = newEndDate;
}
