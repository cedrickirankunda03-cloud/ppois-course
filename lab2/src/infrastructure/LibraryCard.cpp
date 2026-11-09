#include "infrastructure/LibraryCard.h"

#include <stdexcept>

LibraryCard::LibraryCard(
    const std::string& id,
    const std::string& studentId,
    const std::string& bookId
)
    : cardId(id),
      studentId(studentId),
      borrowedBookId(bookId)
{
    if (id.empty() || studentId.empty())
    {
        throw std::invalid_argument(
            "Invalid library card information"
        );
    }
}

void LibraryCard::borrowBook(const std::string& bookId)
{
    if (bookId.empty())
    {
        throw std::invalid_argument(
            "Book ID cannot be empty"
        );
    }

    if (!borrowedBookId.empty())
    {
        throw std::runtime_error(
            "A book is already borrowed"
        );
    }

    borrowedBookId = bookId;
}

void LibraryCard::returnBook()
{
    if (borrowedBookId.empty())
    {
        throw std::runtime_error(
            "No book is currently borrowed"
        );
    }

    borrowedBookId.clear();
}

bool LibraryCard::hasBorrowedBook() const
{
    return !borrowedBookId.empty();
}