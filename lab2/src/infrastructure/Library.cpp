#include "infrastructure/Library.h"

#include <stdexcept>

Library::Library(
    const std::string& id,
    const std::string& name,
    const std::string& location,
    int books
)
    : libraryId(id),
      libraryName(name),
      location(location),
      totalBooks(books)
{
    if (id.empty() || name.empty() ||
        location.empty() || books < 0)
    {
        throw std::invalid_argument(
            "Invalid library information"
        );
    }
}

void Library::updateTotalBooks(int books)
{
    if (books < 0)
    {
        throw std::invalid_argument(
            "Book count cannot be negative"
        );
    }

    totalBooks = books;
}

bool Library::hasBooksAvailable() const
{
    return totalBooks > 0;
}