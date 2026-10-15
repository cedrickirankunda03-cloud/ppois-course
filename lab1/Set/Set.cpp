#include "Set.h"
#include <algorithm>
#include <cctype>

std::string removeSpaces(const std::string& text)
{
    std::string result;

    for (char ch : text)
    {
        if (!std::isspace(static_cast<unsigned char>(ch)))
        {
            result += ch;
        }
    }

    return result;
}


std::string canonicalElement(const std::string& text)
{
    std::string value = removeSpaces(text);

    if (value.size() < 2 ||
        value.front() != '{' ||
        value.back() != '}')
    {
        return value;
    }

    std::vector<std::string> parts;
    std::string part;
    int depth = 0;

    for (int i = 1; i < value.size() - 1; i++)
    {
        char ch = value[i];

        if (ch == '{')
            depth++;
        else if (ch == '}')
            depth--;

        if (ch == ',' && depth == 0)
        {
            if (!part.empty())
                parts.push_back(canonicalElement(part));

            part.clear();
        }
        else
        {
            part += ch;
        }
    }

    if (!part.empty())
        parts.push_back(canonicalElement(part));

    std::sort(parts.begin(), parts.end());

    std::string result = "{";

    for (int i = 0; i < parts.size(); i++)
    {
        if (i > 0)
            result += ",";

        result += parts[i];
    }

    return result + "}";
}

// Create an empty set
Set::Set()
{
}

// Check if the set is empty
bool Set::empty() const
{
    return elements.empty();
}

// Add an element if it does not exist
void Set::add(const std::string& element)
{
    if (!contains(element))
    {
        elements.push_back(element);
    }
}

// Remove an element
void Set::remove(const std::string& element)
{
    for (int i = 0; i < elements.size(); i++)
    {
        if (elements[i] == element)
        {
            elements.erase(elements.begin() + i);
            return;
        }
    }
}

// Return the number of elements
int Set::size() const
{
    return elements.size();
}

// Check whether an element exists

bool Set::contains(const std::string& element) const
{
    for (const std::string& current : elements)
    {
        if (canonicalElement(current) == canonicalElement(element))
        {
            return true;
        }
    }

    return false;
}
    
// Union: combine two sets
Set Set::operator+(const Set& other) const
{
    Set result = *this;

    for (const std::string& element : other.elements)
    {
        result.add(element);
    }

    return result;
}

// Intersection: elements found in both sets
Set Set::operator*(const Set& other) const
{
    Set result;

    for (const std::string& element : elements)
    {
        if (other.contains(element))
        {
            result.add(element);
        }
    }

    return result;
}

// Difference: elements in this set but not the other
Set Set::operator-(const Set& other) const
{
    Set result;

    for (const std::string& element : elements)
    {
        if (!other.contains(element))
        {
            result.add(element);
        }
    }

    return result;
}

// Check whether two sets are equal
bool Set::operator==(const Set& other) const
{
    if (size() != other.size())
    {
        return false;
    }

    for (const std::string& element : elements)
    {
        if (!other.contains(element))
        {
            return false;
        }
    }

    return true;
}

// Check whether two sets are different
bool Set::operator!=(const Set& other) const
{
    return !(*this == other);
}

// Copy constructor
Set::Set(const Set& other)
{
    elements = other.elements;
}

// Copy assignment
Set& Set::operator=(const Set& other)
{
    if (this != &other)
    {
        elements = other.elements;
    }

    return *this;
}

// Convert the set to text
std::string Set::toString() const
{
    std::string result = "{";

    for (int i = 0; i < elements.size(); i++)
    {
        if (i > 0)
        {
            result += ", ";
        }

        result += elements[i];
    }

    result += "}";
    return result;
}

// Build a set from text
Set Set::fromString(const std::string& text)
{
    Set result;
    std::string element;
    int depth = 0;

    for (int i = 0; i < text.size(); i++)
    {
        char ch = text[i];

        if (ch == '{')
        {
            depth++;
            if (depth > 1)
            {
                element += ch;
            }
        }
        else if (ch == '}')
        {
            depth--;
            if (depth > 0)
            {
                element += ch;
            }
        }
        else if (ch == ',' && depth == 1)
        {
            if (!element.empty())
            {
                result.add(element);
                element.clear();
            }
        }
        else if (depth > 0 && ch != ' ')
        {
            element += ch;
        }
    }

    if (!element.empty())
    {
        result.add(element);
    }

    return result;
}

// Create all subsets
Set Set::powerSet() const
{
    Set result;
    int total = 1 << elements.size();

    for (int mask = 0; mask < total; mask++)
    {
        std::string subset = "{";

        for (int i = 0; i < elements.size(); i++)
        {
            if (mask & (1 << i))
            {
                if (subset.size() > 1)
                {
                    subset += ", ";
                }

                subset += elements[i];
            }
        }

        subset += "}";
        result.add(subset);
    }

    return result;
}
// Add another set to this set
Set& Set::operator+=(const Set& other)
{
    *this = *this + other;
    return *this;

}

// Keep only Common elements
Set& Set::operator*=(const Set& other)
{
    *this = *this * other;
    return *this;
}

// Remove elements from another set
Set& Set::operator-=(const Set& other)
{
    *this = *this -other;
    return *this;
}
// Check whether an element belongs to the sset
bool Set::operator[](const std::string& element)const
{
    return contains(element);
}