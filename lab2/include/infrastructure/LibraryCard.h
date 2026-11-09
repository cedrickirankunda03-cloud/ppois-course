#ifndef LIBRARYCARD_H
#define LIBRARYCARD_H

#include <string>

class LibraryCard {
private:
    std::string cardId;
    std::string studentId;
    std::string borrowedBookId;

public:
    LibraryCard(
        const std::string& id,
        const std::string& studentId,
        const std::string& bookId
    );

    void borrowBook(const std::string& bookId);
    void returnBook();
    bool hasBorrowedBook() const;
};

#endif