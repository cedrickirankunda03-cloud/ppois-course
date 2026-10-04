#include "Dictionary.h"
#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

TEST(DictionaryTest, InsertAndSearch)
{
    Dictionary dictionary;
    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    EXPECT_EQ(dictionary.search("apple"), "яблоко");
    EXPECT_EQ(dictionary.search("cat"), "кошка");
    EXPECT_EQ(dictionary.search("dog"), "");
}

TEST(DictionaryTest, Size)
{
    Dictionary dictionary;

    EXPECT_EQ(dictionary.size(), 0);

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");
    dictionary.insert("dog", "собака");

    EXPECT_EQ(dictionary.size(), 3);
}

TEST(DictionaryTest, ChangeTranslation)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    EXPECT_EQ(dictionary["apple"], "яблоко");

    dictionary["apple"] = "новое_слово";

    EXPECT_EQ(dictionary["apple"], "новое_слово");
}

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

TEST(DictionaryTest, NotFound)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    EXPECT_EQ(dictionary.search("house"), "");
}

TEST(DictionaryTest, DuplicateWord)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("apple", "другое");

    EXPECT_EQ(dictionary.size(), 1);
    EXPECT_EQ(dictionary.search("apple"), "яблоко");
}

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

TEST(DictionaryTest, BracketMissingWord)
{
    Dictionary dictionary;

    EXPECT_EQ(dictionary["house"], "");
}

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

TEST(DictionaryTest, MissingFile)
{
    Dictionary dictionary;

    dictionary.loadFromFile("file_that_does_not_exist.txt");

    EXPECT_EQ(dictionary.size(), 0);
}

TEST(DictionaryTest, EmptyDictionary)
{
    Dictionary dictionary;

    EXPECT_EQ(dictionary.size(), 0);
    EXPECT_EQ(dictionary.search("apple"), "");
}

TEST(DictionaryTest, RemoveOnlyNode)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    dictionary -= "apple";

    EXPECT_EQ(dictionary.size(), 0);
    EXPECT_EQ(dictionary.search("apple"), "");
}

TEST(DictionaryTest, RemoveMissingWord)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    dictionary -= "house";

    EXPECT_EQ(dictionary.size(), 1);
    EXPECT_EQ(dictionary.search("apple"), "яблоко");
}

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

TEST(DictionaryTest, Display)
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("cat", "кошка");

    dictionary.display();

    EXPECT_EQ(dictionary.size(), 2);
}

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