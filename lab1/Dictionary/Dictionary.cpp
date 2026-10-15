#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

// Convert UTF-8 string to Windows Unicode
static wstring dictionaryUtf8ToWide(const string& text)
{
    if (text.empty())
    {
        return L"";
    }

    int size = MultiByteToWideChar(
        CP_UTF8,
        0,
        text.c_str(),
        -1,
        nullptr,
        0
    );

    wstring result(size - 1, L'\0');

    MultiByteToWideChar(
        CP_UTF8,
        0,
        text.c_str(),
        -1,
        &result[0],
        size
    );

    return result;
}

Dictionary::Dictionary()
{
    root = nullptr;
}

Dictionary::~Dictionary()
{
    deleteTree(root);
}

Dictionary::Node* Dictionary::createNode(
    const string& english,
    const string& russian)
{
    Node* newNode = new Node;

    newNode->english = english;
    newNode->russian = russian;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

void Dictionary::deleteTree(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}

void Dictionary::insert(
    const string& english,
    const string& russian)
{
    if (root == nullptr)
    {
        root = createNode(english, russian);
        return;
    }

    Node* current = root;

    while (true)
    {
        if (english == current->english)
        {
            wcout << L"Word already exists." << endl;
            return;
        }

        if (english < current->english)
        {
            if (current->left == nullptr)
            {
                current->left = createNode(english, russian);
                return;
            }

            current = current->left;
        }
        else
        {
            if (current->right == nullptr)
            {
                current->right = createNode(english, russian);
                return;
            }

            current = current->right;
        }
    }
}

Dictionary& Dictionary::operator+=(const string& english)
{
    string russian;

    cout << "Enter Russian translation: ";
    getline(cin, russian);

    insert(english, russian);

    return *this;
}

Dictionary& Dictionary::operator+=(const char* english)
{
    return (*this += string(english));
}

Dictionary::Node* Dictionary::findNode(
    Node* node,
    const string& english) const
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (english == node->english)
    {
        return node;
    }

    if (english < node->english)
    {
        return findNode(node->left, english);
    }

    return findNode(node->right, english);
}

string Dictionary::search(const string& english) const
{
    Node* node = findNode(root, english);

    if (node == nullptr)
    {
        return "";
    }

    return node->russian;
}

string& Dictionary::operator[](const string& english)
{
    Node* node = findNode(root, english);

    if (node == nullptr)
    {
        static string empty;

        empty = "";

        return empty;
    }

    return node->russian;
}

void Dictionary::displayTree(Node* node) const
{
    if (node == nullptr)
    {
        return;
    }

    displayTree(node->left);

    wcout << dictionaryUtf8ToWide(node->english)
          << L" - "
          << dictionaryUtf8ToWide(node->russian)
          << endl;

    displayTree(node->right);
}

void Dictionary::display() const
{
    wcout << endl;
    wcout << L"Dictionary:" << endl;

    displayTree(root);
}

int Dictionary::countNodes(Node* node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    return 1
         + countNodes(node->left)
         + countNodes(node->right);
}

int Dictionary::size() const
{
    return countNodes(root);
}

Dictionary::Node* Dictionary::findMinimum(Node* node) const
{
    while (node != nullptr && node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}

Dictionary::Node* Dictionary::removeNode(
    Node* node,
    const string& english)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (english < node->english)
    {
        node->left = removeNode(node->left, english);
    }
    else if (english > node->english)
    {
        node->right = removeNode(node->right, english);
    }
    else
    {
        if (node->left == nullptr)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }

        if (node->right == nullptr)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMinimum(node->right);

        node->english = temp->english;
        node->russian = temp->russian;

        node->right =
            removeNode(node->right, temp->english);
    }

    return node;
}

Dictionary& Dictionary::operator-=(const string& english)
{
    if (findNode(root, english) == nullptr)
    {
        wcout << L"Word not found." << endl;
        return *this;
    }

    root = removeNode(root, english);

    wcout << L"Word removed." << endl;

    return *this;
}

void Dictionary::loadFromFile(const string& filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        wcout << L"Cannot open file." << endl;
        return;
    }

    // Clear the current dictionary before loading
    deleteTree(root);
    root = nullptr;

    string english;
    string russian;

    while (file >> english >> russian)
    {
        insert(english, russian);
    }

    file.close();

    wcout << L"Dictionary loaded from file." << endl;
}

void Dictionary::saveTreeToFile(
    Node* node,
    ofstream& file) const
{
    if (node == nullptr)
    {
        return;
    }

    saveTreeToFile(node->left, file);

    file << node->english << " "
         << node->russian << endl;

    saveTreeToFile(node->right, file);
}

void Dictionary::saveToFile(const string& filename) const
{
    ofstream file(filename);

    if (!file.is_open())
    {
        wcout << L"Cannot open file for saving." << endl;
        return;
    }

    saveTreeToFile(root, file);

    file.close();

    wcout << L"Dictionary saved to file." << endl;
}