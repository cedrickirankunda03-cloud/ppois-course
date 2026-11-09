#ifndef INTERNATIONAL_STUDENT_H
#define INTERNATIONAL_STUDENT_H

#include "Student.h"
#include <string>

class InternationalStudent : public Student {
private:
    std::string homeCountry;
    std::string passportNumber;
    std::string visaExpiryDate;
    std::string nativeLanguage;
    int languageProficiency;
    bool visaValid;

public:
    InternationalStudent(
        const std::string& id,
        const std::string& first,
        const std::string& last,
        int year,
        const std::string& country,
        const std::string& passport,
        const std::string& visaExpiry,
        const std::string& language,
        int proficiency
    );

    std::string getHomeCountry() const;
    std::string getPassportNumber() const;
    std::string getVisaExpiryDate() const;

    void renewVisa(const std::string& newExpiryDate);
    void updateLanguageProficiency(int level);
    void updateNativeLanguage(const std::string& language);

    bool isVisaValid() const;

    void displayInformation() const override;
};

#endif