
#include "Dictionary.h"
#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// 1. Test inserting and searching words
TEST(DictionaryTest, InsertAndSearch)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    EXPECT_EQ(dictionary.search("apple"), "яблоко");
    EXPECT_EQ(dictionary.search("cat"), "кошка");
    EXPECT_EQ(dictionary.search("dog"), "");
}

// 2. Test dictionary size
TEST(DictionaryTest, Size)
{
    Dictionary dictionary;

    EXPECT_EQ(dictionary.size(), 0);

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");
    dictionary.insert("dog", "собака");

    EXPECT_EQ(dictionary.size(), 3);
}

// 3. Test changing a translation
TEST(DictionaryTest, ChangeTranslation)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    EXPECT_EQ(dictionary["apple"], "яблоко");

    dictionary["apple"] = "новое_слово";

    EXPECT_EQ(dictionary["apple"], "новое_слово");
}

// 4. Test removing a leaf node
TEST(DictionaryTest, RemoveLeaf)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    dictionary -= "cat";

    EXPECT_EQ(dictionary.search("cat"), "");
    EXPECT_EQ(dictionary.search("apple"), "яблоко");
    EXPECT_EQ(dictionary.size(), 1);
}

// 5. Test removing a node with one child
TEST(DictionaryTest, RemoveNodeWithOneChild)
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("elephant", "слон");

    dictionary -= "dog";

    EXPECT_EQ(dictionary.search("dog"), "");
    EXPECT_EQ(dictionary.search("elephant"), "слон");
    EXPECT_EQ(dictionary.size(), 1);
}

// 6. Test removing a node with two children
TEST(DictionaryTest, RemoveNodeWithTwoChildren)
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("cat", "кошка");
    dictionary.insert("elephant", "слон");

    dictionary -= "dog";

    EXPECT_EQ(dictionary.search("dog"), "");
    EXPECT_EQ(dictionary.search("cat"), "кошка");
    EXPECT_EQ(dictionary.search("elephant"), "слон");
    EXPECT_EQ(dictionary.size(), 2);
}

// 7. Test searching for a missing word
TEST(DictionaryTest, NotFound)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    EXPECT_EQ(dictionary.search("house"), "");
}

// 8. Test inserting a duplicate word
TEST(DictionaryTest, DuplicateWord)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("apple", "другое");

    EXPECT_EQ(dictionary.size(), 1);
    EXPECT_EQ(dictionary.search("apple"), "яблоко");
}

// 9. Test the += operator with std::string
TEST(DictionaryTest, PlusEqualString)
{
    Dictionary dictionary;

    istringstream input("яблоко\n");
    streambuf* oldBuffer = cin.rdbuf(input.rdbuf());

    dictionary += string("apple");

    cin.rdbuf(oldBuffer);

    EXPECT_EQ(dictionary.size(), 1);
    EXPECT_EQ(dictionary.search("apple"), "яблоко");
}

// 10. Test the += operator with const char*
TEST(DictionaryTest, PlusEqualCString)
{
    Dictionary dictionary;

    istringstream input("собака\n");
    streambuf* oldBuffer = cin.rdbuf(input.rdbuf());

    dictionary += "dog";

    cin.rdbuf(oldBuffer);

    EXPECT_EQ(dictionary.size(), 1);
    EXPECT_EQ(dictionary.search("dog"), "собака");
}

// 11. Test the [] operator with a missing word
TEST(DictionaryTest, BracketMissingWord)
{
    Dictionary dictionary;

    EXPECT_EQ(dictionary["house"], "");
}

// 12. Test searching through different BST paths
TEST(DictionaryTest, SearchTreePaths)
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("cat", "кошка");
    dictionary.insert("elephant", "слон");
    dictionary.insert("apple", "яблоко");
    dictionary.insert("house", "дом");

    EXPECT_EQ(dictionary.search("apple"), "яблоко");
    EXPECT_EQ(dictionary.search("cat"), "кошка");
    EXPECT_EQ(dictionary.search("dog"), "собака");
    EXPECT_EQ(dictionary.search("elephant"), "слон");
    EXPECT_EQ(dictionary.search("house"), "дом");
    EXPECT_EQ(dictionary.search("unknown"), "");
}

// 13. Test loading words from a file
TEST(DictionaryTest, LoadFromFile)
{
    Dictionary dictionary;

    dictionary.loadFromFile("dictionary.txt");

    EXPECT_EQ(dictionary.search("apple"), "яблоко");
    EXPECT_EQ(dictionary.search("book"), "книга");
    EXPECT_EQ(dictionary.search("cat"), "кот");
    EXPECT_EQ(dictionary.search("dog"), "собака");
    EXPECT_EQ(dictionary.search("house"), "дом");
}

// 14. Test replacing the existing dictionary when loading
TEST(DictionaryTest, LoadReplacesDictionary)
{
    Dictionary dictionary;

    dictionary.insert("temporary", "временный");

    dictionary.loadFromFile("dictionary.txt");

    EXPECT_EQ(dictionary.search("temporary"), "");
    EXPECT_EQ(dictionary.search("apple"), "яблоко");
    EXPECT_EQ(dictionary.search("book"), "книга");
    EXPECT_EQ(dictionary.search("cat"), "кот");
}

// 15. Test saving the dictionary to a file
TEST(DictionaryTest, SaveToFile)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    dictionary.saveToFile("test_output.txt");

    ifstream file("test_output.txt");

    EXPECT_TRUE(file.is_open());

    file.close();
}

// 16. Test loading a file that does not exist
TEST(DictionaryTest, MissingFile)
{
    Dictionary dictionary;

    dictionary.loadFromFile("file_that_does_not_exist.txt");

    EXPECT_EQ(dictionary.size(), 0);
}

// 17. Test an empty dictionary
TEST(DictionaryTest, EmptyDictionary)
{
    Dictionary dictionary;

    EXPECT_EQ(dictionary.size(), 0);
    EXPECT_EQ(dictionary.search("apple"), "");
}

// 18. Test removing the only node
TEST(DictionaryTest, RemoveOnlyNode)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    dictionary -= "apple";

    EXPECT_EQ(dictionary.size(), 0);
    EXPECT_EQ(dictionary.search("apple"), "");
}

// 19. Test removing a word that does not exist
TEST(DictionaryTest, RemoveMissingWord)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    dictionary -= "house";

    EXPECT_EQ(dictionary.size(), 1);
    EXPECT_EQ(dictionary.search("apple"), "яблоко");
}

// 20. Test removing a node with a deep successor
TEST(DictionaryTest, RemoveWithDeepSuccessor)
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("cat", "кошка");
    dictionary.insert("elephant", "слон");
    dictionary.insert("bear", "медведь");

    dictionary -= "dog";

    EXPECT_EQ(dictionary.search("dog"), "");
    EXPECT_EQ(dictionary.search("bear"), "медведь");
    EXPECT_EQ(dictionary.search("cat"), "кошка");
    EXPECT_EQ(dictionary.search("elephant"), "слон");
    EXPECT_EQ(dictionary.size(), 3);
}

// 21. Test displaying the dictionary
TEST(DictionaryTest, Display)
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("cat", "кошка");

    dictionary.display();

    EXPECT_EQ(dictionary.size(), 2);
}

// 22. Test the Dictionary destructor
TEST(DictionaryTest, Destructor)
{
    {
        Dictionary dictionary;

        dictionary.insert("dog", "собака");
        dictionary.insert("cat", "кошка");
        dictionary.insert("elephant", "слон");
        dictionary.insert("apple", "яблоко");
    }

    SUCCEED();
}