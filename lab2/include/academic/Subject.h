#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>

class Subject {
private:
    std::string name;
    std::string description;
    int credits;

public:
    // Constructor
    Subject(
        const std::string& name,
        const std::string& description,
        int credits
    );

    // Getters
    std::string getName() const;
    std::string getDescription() const;
    int getCredits() const;

    // Setters
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setCredits(int credits);
};

#endif