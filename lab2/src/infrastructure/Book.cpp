#include "infrastructure/Book.h"

#include <stdexcept>

Book::Book(
    const std::string& id,
    const std::string& title,
    const std::string& libraryId,
    const std::string& subjectId
)
    : bookId(id),
      title(title),
      libraryId(libraryId),
      subjectId(subjectId)
{
    if (id.empty() ||
        title.empty() ||
        libraryId.empty() ||
        subjectId.empty())
    {
        throw std::invalid_argument(
            "Invalid book information"
        );
    }
}

void Book::updateTitle(const std::string& newTitle)
{
    if (newTitle.empty())
    {
        throw std::invalid_argument(
            "Book title cannot be empty"
        );
    }

    title = newTitle;
}

bool Book::belongsToSubject(const std::string& id) const
{
    return subjectId == id;
}