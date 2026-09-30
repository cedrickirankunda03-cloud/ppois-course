#include "Dictionary.h"
#include <iostream>

using namespace std;

int main()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");
    dictionary.insert("dog", "собака");

    cout << "Original dictionary:" << endl;
    dictionary.display();

    // NEW: create a copy
    Dictionary copy = dictionary;

    cout << endl;
    cout << "Copied dictionary:" << endl;
    copy.display();

    // Change the copy
    copy["apple"] = "новое_слово";

    cout << endl;
    cout << "After changing the copy:" << endl;

    cout << "Original apple: "
         << dictionary["apple"] << endl;

    cout << "Copied apple: "
         << copy["apple"] << endl;

    return 0;
}