#include "Dictionary.h"
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>

using namespace std;

void testInsertAndSearch()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    assert(dictionary.search("apple") == "яблоко");
    assert(dictionary.search("cat") == "кошка");

    cout << "testInsertAndSearch: PASSED" << endl;
}

void testSize()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");
    dictionary.insert("dog", "собака");

    assert(dictionary.size() == 3);

    cout << "testSize: PASSED" << endl;
}

void testChangeTranslation()
{
    Dictionary dictionary;

    dictionary.insert("cat", "кошка");

    dictionary["cat"] = "кот";

    assert(dictionary.search("cat") == "кот");

    cout << "testChangeTranslation: PASSED" << endl;
}

void testRemoveLeaf()
{
    Dictionary dictionary;

    dictionary.insert("cat", "кошка");
    dictionary.insert("apple", "яблоко");
    dictionary.insert("dog", "собака");

    dictionary -= "apple";

    assert(dictionary.search("apple") == "");
    assert(dictionary.size() == 2);

    cout << "testRemoveLeaf: PASSED" << endl;
}

void testRemoveNodeWithOneChild()
{
    Dictionary dictionary;

    dictionary.insert("cat", "кошка");
    dictionary.insert("apple", "яблоко");
    dictionary.insert("banana", "банан");

    dictionary -= "apple";

    assert(dictionary.search("apple") == "");
    assert(dictionary.search("banana") == "банан");
    assert(dictionary.size() == 2);

    cout << "testRemoveNodeWithOneChild: PASSED" << endl;
}

void testRemoveNodeWithTwoChildren()
{
    Dictionary dictionary;

    dictionary.insert("dog", "собака");
    dictionary.insert("cat", "кошка");
    dictionary.insert("house", "дом");
    dictionary.insert("apple", "яблоко");
    dictionary.insert("book", "книга");

    dictionary -= "dog";

    assert(dictionary.search("dog") == "");
    assert(dictionary.search("cat") == "кошка");
    assert(dictionary.search("house") == "дом");
    assert(dictionary.search("apple") == "яблоко");
    assert(dictionary.search("book") == "книга");
    assert(dictionary.size() == 4);

    cout << "testRemoveNodeWithTwoChildren: PASSED" << endl;
}

void testNotFound()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");

    assert(dictionary.search("banana") == "");

    cout << "testNotFound: PASSED" << endl;
}

void testDuplicate()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("apple", "яблоко");

    assert(dictionary.size() == 1);

    cout << "testDuplicate: PASSED" << endl;
}

void testLoadFromFile()
{
    ofstream file("test_dictionary.txt");

    file << "apple яблоко" << endl;
    file << "book книга" << endl;
    file << "cat кошка" << endl;

    file.close();

    Dictionary dictionary;

    dictionary.loadFromFile("test_dictionary.txt");

    assert(dictionary.size() == 3);
    assert(dictionary.search("apple") == "яблоко");
    assert(dictionary.search("book") == "книга");
    assert(dictionary.search("cat") == "кошка");

    remove("test_dictionary.txt");

    cout << "testLoadFromFile: PASSED" << endl;
}

void testSaveToFile()
{
    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    dictionary.saveToFile("test_saved_dictionary.txt");

    ifstream file("test_saved_dictionary.txt");

    assert(file.is_open());

    string line1;
    string line2;

    getline(file, line1);
    getline(file, line2);

    file.close();

    assert(line1 == "apple яблоко");
    assert(line2 == "cat кошка");

    remove("test_saved_dictionary.txt");

    cout << "testSaveToFile: PASSED" << endl;
}

void testLoadReplacesDictionary()
{
    ofstream file("test_replace_dictionary.txt");

    file << "orange апельсин" << endl;
    file << "house дом" << endl;

    file.close();

    Dictionary dictionary;

    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");

    dictionary.loadFromFile("test_replace_dictionary.txt");

    assert(dictionary.size() == 2);
    assert(dictionary.search("orange") == "апельсин");
    assert(dictionary.search("house") == "дом");
    assert(dictionary.search("apple") == "");
    assert(dictionary.search("cat") == "");

    remove("test_replace_dictionary.txt");

    cout << "testLoadReplacesDictionary: PASSED" << endl;
}

void testEmptyDictionary()
{
    Dictionary dictionary;

    assert(dictionary.size() == 0);
    assert(dictionary.search("apple") == "");

    cout << "testEmptyDictionary: PASSED" << endl;
}

int main()
{
    cout << "===== DICTIONARY UNIT TESTS =====" << endl;

    testInsertAndSearch();
    testSize();
    testChangeTranslation();

    testRemoveLeaf();
    testRemoveNodeWithOneChild();
    testRemoveNodeWithTwoChildren();

    testNotFound();
    testDuplicate();

    testLoadFromFile();
    testSaveToFile();
    testLoadReplacesDictionary();

    testEmptyDictionary();

    cout << endl;
    cout << "ALL TESTS PASSED!" << endl;

    return 0;
}

