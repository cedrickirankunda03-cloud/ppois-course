#include "Dictionary.h"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

using namespace std;


TEST(DictionaryTest, InsertAndSearch)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    EXPECT_EQ(dictionary.search("apple"), "яблоко");
    EXPECT_EQ(dictionary.search("cat"), "кошка");
    EXPECT_EQ(dictionary.search("dog"), "word not found");
}


TEST(DictionaryTest, SearchTreePaths)
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("cat", "кошка");
    dictionary.insert("elephant", "слон");
    dictionary.insert("apple", "яблоко");

    EXPECT_EQ(dictionary.search("apple"), "яблоко");
    EXPECT_EQ(dictionary.search("elephant"), "слон");
    EXPECT_EQ(dictionary.search("house"), "word not found");
}


TEST(DictionaryTest, PlusEqual)
{
    Dictionary dictionary;

    streambuf* originalBuffer = cin.rdbuf();

    istringstream input("яблоко");
    cin.rdbuf(input.rdbuf());

    dictionary += "apple";

    EXPECT_EQ(dictionary.size(), 1);
    EXPECT_EQ(dictionary.search("apple"), "яблоко");

    cin.rdbuf(originalBuffer);
}


TEST(DictionaryTest, CStringPlusEqual)
{
    Dictionary dictionary;

    const char* word = "dog";

    streambuf* originalBuffer = cin.rdbuf();

    istringstream input("собака");
    cin.rdbuf(input.rdbuf());

    dictionary += word;

    EXPECT_EQ(dictionary.size(), 1);
    EXPECT_EQ(dictionary.search("dog"), "собака");

    cin.rdbuf(originalBuffer);
}


TEST(DictionaryTest, BracketOperator)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    EXPECT_EQ(dictionary["apple"], "яблоко");

    dictionary["apple"] = "новое_слово";

    EXPECT_EQ(dictionary["apple"], "новое_слово");
}


TEST(DictionaryTest, BracketOperatorMissingWord)
{
    Dictionary dictionary;

    EXPECT_EQ(dictionary["house"], "word not found");
}


TEST(DictionaryTest, BracketOperatorPaths)
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("cat", "кошка");
    dictionary.insert("elephant", "слон");
    dictionary.insert("apple", "яблоко");

    EXPECT_EQ(dictionary["apple"], "яблоко");
    EXPECT_EQ(dictionary["elephant"], "слон");
}


TEST(DictionaryTest, Remove)
{
    Dictionary dictionary;

    dictionary.insert("cat", "кошка");
    dictionary.insert("apple", "яблоко");
    dictionary.insert("dog", "собака");

    dictionary -= "cat";

    EXPECT_EQ(dictionary.search("cat"), "word not found");
    EXPECT_EQ(dictionary.size(), 2);
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


TEST(DictionaryTest, CopyConstructor)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    Dictionary copy(dictionary);

    EXPECT_TRUE(copy == dictionary);

    copy["apple"] = "новое_слово";

    EXPECT_EQ(dictionary["apple"], "яблоко");
    EXPECT_EQ(copy["apple"], "новое_слово");
}


TEST(DictionaryTest, CopyEmptyDictionary)
{
    Dictionary dictionary;

    Dictionary copy(dictionary);

    EXPECT_EQ(copy.size(), 0);
    EXPECT_TRUE(copy == dictionary);
}


TEST(DictionaryTest, AssignmentOperator)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    Dictionary copy;

    copy = dictionary;

    EXPECT_TRUE(copy == dictionary);

    copy["apple"] = "новое_слово";

    EXPECT_EQ(dictionary["apple"], "яблоко");
    EXPECT_EQ(copy["apple"], "новое_слово");
}


TEST(DictionaryTest, AssignmentEmptyDictionary)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    Dictionary empty;

    dictionary = empty;

    EXPECT_EQ(dictionary.size(), 0);
    EXPECT_TRUE(dictionary == empty);
}


TEST(DictionaryTest, Equality)
{
    Dictionary first;
    Dictionary second;

    first.insert("apple", "яблоко");
    second.insert("apple", "яблоко");

    EXPECT_TRUE(first == second);
    EXPECT_FALSE(first != second);

    second["apple"] = "другое_слово";

    EXPECT_TRUE(first != second);
    EXPECT_FALSE(first == second);
}


TEST(DictionaryTest, DifferentTreeStructure)
{
    Dictionary first;
    Dictionary second;

    first.insert("apple", "яблоко");

    second.insert("apple", "яблоко");
    second.insert("cat", "кошка");

    EXPECT_TRUE(first != second);
    EXPECT_FALSE(first == second);
}


TEST(DictionaryTest, LoadFromFile)
{
    Dictionary dictionary;

    EXPECT_TRUE(dictionary.loadFromFile("dictionary.txt"));

    EXPECT_EQ(dictionary.search("apple"), "яблоко");
    EXPECT_EQ(dictionary.search("cat"), "кошка");
}


TEST(DictionaryTest, SaveToFile)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    EXPECT_TRUE(dictionary.saveToFile("test_output.txt"));
}


TEST(DictionaryTest, RemoveDifferentCases)
{
    // Leaf node
    Dictionary leaf;

    leaf.insert("apple", "яблоко");
    leaf.insert("cat", "кошка");

    leaf -= "cat";

    EXPECT_EQ(leaf.search("cat"), "word not found");


    // Node with one child
    Dictionary oneChild;

    oneChild.insert("dog", "собака");
    oneChild.insert("elephant", "слон");

    oneChild -= "dog";

    EXPECT_EQ(oneChild.search("dog"), "word not found");
    EXPECT_EQ(oneChild.search("elephant"), "слон");


    // Node with two children
    Dictionary twoChildren;

    twoChildren.insert("dog", "собака");
    twoChildren.insert("cat", "кошка");
    twoChildren.insert("elephant", "слон");

    twoChildren -= "dog";

    EXPECT_EQ(twoChildren.search("dog"), "word not found");
    EXPECT_EQ(twoChildren.size(), 2);

    // Word does not exist
    twoChildren -= "house";
}


TEST(DictionaryTest, RemoveWithDeepSuccessor)
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("cat", "кошка");
    dictionary.insert("elephant", "слон");
    dictionary.insert("bear", "медведь");

    dictionary -= "dog";

    EXPECT_EQ(dictionary.search("dog"), "word not found");
    EXPECT_EQ(dictionary.search("bear"), "медведь");
    EXPECT_EQ(dictionary.search("cat"), "кошка");
    EXPECT_EQ(dictionary.search("elephant"), "слон");
    EXPECT_EQ(dictionary.size(), 3);
}


TEST(DictionaryTest, RemoveOnlyNode)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    dictionary -= "apple";

    EXPECT_EQ(dictionary.size(), 0);
    EXPECT_EQ(dictionary.search("apple"), "word not found");
}


TEST(DictionaryTest, DuplicateWord)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("apple", "другое");

    EXPECT_EQ(dictionary.size(), 1);
    EXPECT_EQ(dictionary.search("apple"), "яблоко");
}


TEST(DictionaryTest, EmptyDictionary)
{
    Dictionary dictionary;

    dictionary.display();

    EXPECT_EQ(dictionary.size(), 0);
}


TEST(DictionaryTest, Display)
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("cat", "кошка");

    dictionary.display();

    EXPECT_EQ(dictionary.size(), 2);
}


TEST(DictionaryTest, MissingFile)
{
    Dictionary dictionary;

    EXPECT_FALSE(
        dictionary.loadFromFile("file_that_does_not_exist.txt")
    );
}


TEST(DictionaryTest, SaveEmptyDictionary)
{
    Dictionary dictionary;

    EXPECT_TRUE(
        dictionary.saveToFile("empty_dictionary.txt")
    );
}


TEST(DictionaryTest, SaveInvalidFile)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    EXPECT_FALSE(
        dictionary.saveToFile("Z:\\invalid_folder\\test.txt")
    );
}


TEST(DictionaryTest, SelfAssignment)
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    dictionary = dictionary;

    EXPECT_EQ(dictionary.search("apple"), "яблоко");
}