#include "Dictionary.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

void testInsertAndSearch()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    assert(dictionary.search("apple") == "яблоко");
    assert(dictionary.search("cat") == "кошка");
    assert(dictionary.search("dog") == "word not found");
}

// NEW: Test search through multiple tree levels
void testSearchTreePaths()
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("cat", "кошка");
    dictionary.insert("elephant", "слон");
    dictionary.insert("apple", "яблоко");

    assert(dictionary.search("apple") == "яблоко");
    assert(dictionary.search("elephant") == "слон");
    assert(dictionary.search("house") == "word not found");
}

void testPlusEqual()
{
    Dictionary dictionary;

    streambuf* originalBuffer = cin.rdbuf();

    istringstream input("яблоко");
    cin.rdbuf(input.rdbuf());

    dictionary += "apple";

    assert(dictionary.size() == 1);
    assert(dictionary.search("apple") == "яблоко");

    cin.rdbuf(originalBuffer);
}

void testCStringPlusEqual()
{
    Dictionary dictionary;

    const char* word = "dog";

    streambuf* originalBuffer = cin.rdbuf();

    istringstream input("собака");
    cin.rdbuf(input.rdbuf());

    dictionary += word;

    assert(dictionary.size() == 1);
    assert(dictionary.search("dog") == "собака");

    cin.rdbuf(originalBuffer);
}

void testBracketOperator()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    assert(dictionary["apple"] == "яблоко");

    dictionary["apple"] = "новое_слово";

    assert(dictionary["apple"] == "новое_слово");
}

// NEW: Test missing word with [] operator
void testBracketOperatorMissingWord()
{
    Dictionary dictionary;

    assert(dictionary["house"] == "word not found");
}

// NEW: Test [] operator through multiple tree levels
void testBracketOperatorPaths()
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("cat", "кошка");
    dictionary.insert("elephant", "слон");
    dictionary.insert("apple", "яблоко");

    assert(dictionary["apple"] == "яблоко");
    assert(dictionary["elephant"] == "слон");
}

void testRemove()
{
    Dictionary dictionary;

    dictionary.insert("cat", "кошка");
    dictionary.insert("apple", "яблоко");
    dictionary.insert("dog", "собака");

    dictionary -= "cat";

    assert(dictionary.search("cat") == "word not found");
    assert(dictionary.size() == 2);
}

void testSize()
{
    Dictionary dictionary;

    assert(dictionary.size() == 0);

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");
    dictionary.insert("dog", "собака");

    assert(dictionary.size() == 3);
}

void testCopyConstructor()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    Dictionary copy(dictionary);

    assert(copy == dictionary);

    copy["apple"] = "новое_слово";

    assert(dictionary["apple"] == "яблоко");
    assert(copy["apple"] == "новое_слово");
}

// NEW: Test copying an empty dictionary
void testCopyEmptyDictionary()
{
    Dictionary dictionary;

    Dictionary copy(dictionary);

    assert(copy.size() == 0);
    assert(copy == dictionary);
}

void testAssignmentOperator()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    Dictionary copy;

    copy = dictionary;

    assert(copy == dictionary);

    copy["apple"] = "новое_слово";

    assert(dictionary["apple"] == "яблоко");
    assert(copy["apple"] == "новое_слово");
}

// NEW: Test assignment from an empty dictionary
void testAssignmentEmptyDictionary()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    Dictionary empty;

    dictionary = empty;

    assert(dictionary.size() == 0);
    assert(dictionary == empty);
}

void testEquality()
{
    Dictionary first;
    Dictionary second;

    first.insert("apple", "яблоко");
    second.insert("apple", "яблоко");

    assert(first == second);
    assert(!(first != second));

    second["apple"] = "другое_слово";

    assert(first != second);
    assert(!(first == second));
}

// NEW: Test different tree structures
void testDifferentTreeStructure()
{
    Dictionary first;
    Dictionary second;

    first.insert("apple", "яблоко");

    second.insert("apple", "яблоко");
    second.insert("cat", "кошка");

    assert(first != second);
    assert(!(first == second));
}

void testLoadFromFile()
{
    Dictionary dictionary;

    assert(dictionary.loadFromFile("dictionary.txt"));

    assert(dictionary.search("apple") == "яблоко");
    assert(dictionary.search("cat") == "кошка");
}

void testSaveToFile()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    assert(dictionary.saveToFile("test_output.txt"));
}

// NEW: Test different removal cases
void testRemoveDifferentCases()
{
    // Leaf node
    Dictionary leaf;

    leaf.insert("apple", "яблоко");
    leaf.insert("cat", "кошка");

    leaf -= "cat";

    assert(leaf.search("cat") == "word not found");

    // Node with one child
    Dictionary oneChild;

    oneChild.insert("dog", "собака");
    oneChild.insert("elephant", "слон");

    oneChild -= "dog";

    assert(oneChild.search("dog") == "word not found");
    assert(oneChild.search("elephant") == "слон");

    // Node with two children
    Dictionary twoChildren;

    twoChildren.insert("dog", "собака");
    twoChildren.insert("cat", "кошка");
    twoChildren.insert("elephant", "слон");

    twoChildren -= "dog";

    assert(twoChildren.search("dog") == "word not found");
    assert(twoChildren.size() == 2);

    // Word does not exist
    twoChildren -= "house";
}

// NEW: Test two-child removal with deeper successor
void testRemoveWithDeepSuccessor()
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("cat", "кошка");
    dictionary.insert("elephant", "слон");
    dictionary.insert("bear", "медведь");

    dictionary -= "dog";

    assert(dictionary.search("dog") == "word not found");
    assert(dictionary.search("bear") == "медведь");
    assert(dictionary.search("cat") == "кошка");
    assert(dictionary.search("elephant") == "слон");
    assert(dictionary.size() == 3);
}

// NEW: Test removing the only node
void testRemoveOnlyNode()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    dictionary -= "apple";

    assert(dictionary.size() == 0);
    assert(dictionary.search("apple") == "word not found");
}

// NEW: Test duplicate word
void testDuplicateWord()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("apple", "другое");

    assert(dictionary.size() == 1);
    assert(dictionary.search("apple") == "яблоко");
}

// NEW: Test empty dictionary
void testEmptyDictionary()
{
    Dictionary dictionary;

    dictionary.display();

    assert(dictionary.size() == 0);
}

// NEW: Test displaying a non-empty dictionary
void testDisplay()
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("cat", "кошка");

    dictionary.display();

    assert(dictionary.size() == 2);
}

// NEW: Test missing file
void testMissingFile()
{
    Dictionary dictionary;

    assert(dictionary.loadFromFile("file_that_does_not_exist.txt") == false);
}

// NEW: Test saving an empty dictionary
void testSaveEmptyDictionary()
{
    Dictionary dictionary;

    assert(dictionary.saveToFile("empty_dictionary.txt"));
}

// NEW: Test saving to an invalid path
void testSaveInvalidFile()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    assert(dictionary.saveToFile("Z:\\invalid_folder\\test.txt") == false);
}

// NEW: Test self-assignment
void testSelfAssignment()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    dictionary = dictionary;

    assert(dictionary.search("apple") == "яблоко");
}

int main()
{
    testInsertAndSearch();

    // NEW
    testSearchTreePaths();

    testPlusEqual();
    testCStringPlusEqual();
    testBracketOperator();
    testBracketOperatorMissingWord();

    // NEW
    testBracketOperatorPaths();

    testRemove();
    testSize();
    testCopyConstructor();
    testCopyEmptyDictionary();
    testAssignmentOperator();
    testAssignmentEmptyDictionary();
    testEquality();
    testDifferentTreeStructure();
    testLoadFromFile();
    testSaveToFile();
    testRemoveDifferentCases();
    testRemoveWithDeepSuccessor();

    // NEW
    testRemoveOnlyNode();

    testDuplicateWord();
    testEmptyDictionary();

    // NEW
    testDisplay();

    testMissingFile();

    // NEW
    testSaveEmptyDictionary();
    testSaveInvalidFile();

    testSelfAssignment();

    cout << "All tests passed successfully!" << endl;

    return 0;
}