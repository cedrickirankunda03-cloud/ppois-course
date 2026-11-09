
#ifndef TEACHER_CONTRACT_H
#define TEACHER_CONTRACT_H

#include <string>

class TeacherContract {
private:
    std::string contractId;
    std::string teacherId;
    std::string contractType;
    std::string startDate;
    std::string endDate;
    bool active;

public:
    TeacherContract(
        const std::string& contractId,
        const std::string& teacherId,
        const std::string& contractType,
        const std::string& startDate,
        const std::string& endDate
    );

    std::string getContractId() const;
    std::string getTeacherId() const;
    std::string getContractType() const;
    std::string getStartDate() const;
    std::string getEndDate() const;

    bool isActive() const;

    void activate();
    void deactivate();
    void updateEndDate(const std::string& newEndDate);
};

#endif
