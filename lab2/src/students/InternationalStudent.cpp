#include "students/InternationalStudent.h"
#include <iostream>
#include <stdexcept>

InternationalStudent::InternationalStudent(
    const std::string& id,
    const std::string& first,
    const std::string& last,
    int year,
    const std::string& country,
    const std::string& passport,
    const std::string& visaExpiry,
    const std::string& language,
    int proficiency
)
    : Student(id, first, last, year),
      homeCountry(country),
      passportNumber(passport),
      visaExpiryDate(visaExpiry),
      nativeLanguage(language),
      languageProficiency(proficiency),
      visaValid(true) {

    if (homeCountry.empty() ||
        passportNumber.empty() ||
        visaExpiryDate.empty() ||
        nativeLanguage.empty()) {
        throw std::invalid_argument(
            "International student information cannot be empty."
        );
    }

    if (proficiency < 1 || proficiency > 5) {
        throw std::invalid_argument(
            "Language proficiency must be between 1 and 5."
        );
    }
}

std::string InternationalStudent::getHomeCountry() const {
    return homeCountry;
}

std::string InternationalStudent::getPassportNumber() const {
    return passportNumber;
}

std::string InternationalStudent::getVisaExpiryDate() const {
    return visaExpiryDate;
}

void InternationalStudent::renewVisa(
    const std::string& newExpiryDate) {

    if (newExpiryDate.empty()) {
        throw std::invalid_argument(
            "Visa expiry date cannot be empty."
        );
    }

    visaExpiryDate = newExpiryDate;
    visaValid = true;
}

void InternationalStudent::updateLanguageProficiency(int level) {
    if (level < 1 || level > 5) {
        throw std::invalid_argument(
            "Language proficiency must be between 1 and 5."
        );
    }

    languageProficiency = level;
}

void InternationalStudent::updateNativeLanguage(
    const std::string& language) {

    if (language.empty()) {
        throw std::invalid_argument(
            "Language cannot be empty."
        );
    }

    nativeLanguage = language;
}

bool InternationalStudent::isVisaValid() const {
    return visaValid;
}

void InternationalStudent::displayInformation() const {
    Student::displayInformation();

    std::cout << "Home country: " << homeCountry << '\n';
    std::cout << "Passport number: " << passportNumber << '\n';
    std::cout << "Visa expiry: " << visaExpiryDate << '\n';
    std::cout << "Native language: " << nativeLanguage << '\n';
    std::cout << "Language proficiency: "
              << languageProficiency << "/5\n";
    std::cout << "Visa valid: "
              << (visaValid ? "Yes" : "No") << '\n';
}
