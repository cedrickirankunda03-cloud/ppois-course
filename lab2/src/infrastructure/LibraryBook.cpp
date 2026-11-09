#include "infrastructure/LibraryBook.h"

#include <stdexcept>

LibraryBook::LibraryBook(
    const std::string& id,
    const std::string& title,
    const std::string& author,
    const std::string& libraryId
)
    : bookId(id),
      title(title),
      author(author),
      libraryId(libraryId),
      available(true)
{
    if (id.empty() || title.empty() ||
        author.empty() || libraryId.empty())
    {
        throw std::invalid_argument(
            "Invalid library book information"
        );
    }
}

bool LibraryBook::isAvailable() const
{
    return available;
}

void LibraryBook::setAvailability(bool available)
{
    this->available = available;
}