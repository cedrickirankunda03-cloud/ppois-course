#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>

class Library {
private:
    std::string libraryId;
    std::string libraryName;
    std::string location;
    int totalBooks;

public:
    Library(
        const std::string& id,
        const std::string& name,
        const std::string& location,
        int books
    );

    void updateTotalBooks(int books);
    bool hasBooksAvailable() const;
};

#endif