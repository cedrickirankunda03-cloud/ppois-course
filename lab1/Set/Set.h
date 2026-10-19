#include <string>
#include <vector>

class Set
{
private:
std::vector<std::string> elements;

public:
Set();

bool empty() const;
void add(const std::string& element);
void remove(const std::string& element);
int size() const;
bool contains(const std::string& element) const;

Set operator+(const Set& other) const;
Set operator*(const Set& other) const;
Set operator-(const Set& other) const;

Set& operator+=(const Set& other);
Set& operator*=(const Set& other);
Set& operator-=(const Set& other);

bool operator==(const Set& other) const;
bool operator!=(const Set& other) const;
bool operator[](const std::string& element) const;

Set(const Set& other);
Set& operator=(const Set& other);

std::string toString() const;
static Set fromString(const std::string& text);

Set powerSet() const;

};
