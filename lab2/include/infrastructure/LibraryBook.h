#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

#include <string>

class Library;


class LibraryBook {
private:
    std::string bookId;
    std::string title;
    std::string author;
    std::string libraryId;

    Library* library = nullptr;
public:
    LibraryBook(
        const std::string& id,
        const std::string& title,
        const std::string& author,
        const std::string& libraryId
    );

    bool isAvailable() const;
    void setAvailability(bool available);

private:
    bool available;
};

#endif
