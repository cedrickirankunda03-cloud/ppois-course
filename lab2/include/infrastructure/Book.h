#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string bookId;
    std::string title;
    std::string libraryId;
    std::string subjectId;

public:
    Book(
        const std::string& id,
        const std::string& title,
        const std::string& libraryId,
        const std::string& subjectId
    );

    void updateTitle(const std::string& newTitle);
    bool belongsToSubject(const std::string& id) const;
};

#endif