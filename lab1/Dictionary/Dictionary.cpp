#include "Dictionary.h"
#include <iostream>

using namespace std;

Dictionary::Dictionary()
{
    root = nullptr;
}

// NEW
Dictionary::Dictionary(const Dictionary& other)
{
    root = copyTree(other.root);
}

// NEW
Dictionary& Dictionary::operator=(const Dictionary& other)
{
    if (this != &other)
    {
        deleteTree(root);
        root = copyTree(other.root);
    }

    return *this;
}

// NEW
Dictionary::~Dictionary()
{
    deleteTree(root);
}

Node* Dictionary::createNode(string english, string russian)
{
    Node* newNode = new Node;

    newNode->english = english;
    newNode->russian = russian;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

// NEW
Node* Dictionary::copyTree(Node* current)
{
    if (current == nullptr)
    {
        return nullptr;
    }

    Node* newNode = createNode(current->english, current->russian);

    newNode->left = copyTree(current->left);
    newNode->right = copyTree(current->right);

    return newNode;
}

// NEW
bool Dictionary::compareTrees(Node* first, Node* second) const
{
    if (first == nullptr && second == nullptr)
    {
        return true;
    }

    if (first == nullptr || second == nullptr)
    {
        return false;
    }

    if (first->english != second->english ||
        first->russian != second->russian)
    {
        return false;
    }

    return compareTrees(first->left, second->left) &&
           compareTrees(first->right, second->right);
}

// NEW
bool Dictionary::operator==(const Dictionary& other) const
{
    return compareTrees(root, other.root);
}

// NEW
bool Dictionary::operator!=(const Dictionary& other) const
{
    return !(*this == other);
}

void Dictionary::insert(string english, string russian)
{
    Node* newNode = createNode(english, russian);

    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    Node* current = root;

    while (true)
    {
        if (english < current->english)
        {
            if (current->left == nullptr)
            {
                current->left = newNode;
                return;
            }

            current = current->left;
        }
        else if (english > current->english)
        {
            if (current->right == nullptr)
            {
                current->right = newNode;
                return;
            }

            current = current->right;
        }
        else
        {
            cout << "Word already exists." << endl;
            delete newNode;
            return;
        }
    }
}

Dictionary& Dictionary::operator+=(string english)
{
    string russian;

    cout << "Enter Russian translation: ";
    cin >> russian;

    insert(english, russian);

    return *this;
}

Dictionary& Dictionary::operator+=(const char* english)
{
    string word = english;

    *this += word;

    return *this;
}

Dictionary& Dictionary::operator-=(string english)
{
    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr && current->english != english)
    {
        parent = current;

        if (english < current->english)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (current == nullptr)
    {
        cout << "Word not found." << endl;
        return *this;
    }

    if (current->left == nullptr && current->right == nullptr)
    {
        if (parent == nullptr)
        {
            root = nullptr;
        }
        else if (parent->left == current)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }

        delete current;
    }

    else if (current->left == nullptr || current->right == nullptr)
    {
        Node* child;

        if (current->left != nullptr)
            child = current->left;
        else
            child = current->right;

        if (parent == nullptr)
            root = child;
        else if (parent->left == current)
            parent->left = child;
        else
            parent->right = child;

        delete current;
    }

    else
    {
        Node* successorParent = current;
        Node* successor = current->right;

        while (successor->left != nullptr)
        {
            successorParent = successor;
            successor = successor->left;
        }

        current->english = successor->english;
        current->russian = successor->russian;

        if (successorParent->left == successor)
            successorParent->left = successor->right;
        else
            successorParent->right = successor->right;

        delete successor;
    }

    cout << "Word removed." << endl;

    return *this;
}

string Dictionary::search(string english)
{
    Node* current = root;

    while (current != nullptr)
    {
        if (english == current->english)
        {
            return current->russian;
        }
        else if (english < current->english)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    return "word not found";
}

string& Dictionary::operator[](string english)
{
    Node* current = root;

    while (current != nullptr)
    {
        if (english == current->english)
        {
            return current->russian;
        }
        else if (english < current->english)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    static string notFound = "word not found";

    return notFound;
}

void Dictionary::displayTree(Node* current)
{
    if (current == nullptr)
    {
        return;
    }

    displayTree(current->left);

    cout << current->english << " - "
         << current->russian << endl;

    displayTree(current->right);
}

void Dictionary::deleteTree(Node* current)
{
    if (current == nullptr)
    {
        return;
    }

    deleteTree(current->left);
    deleteTree(current->right);

    delete current;
}

void Dictionary::display()
{
    if (root == nullptr)
    {
        cout << "Dictionary is empty." << endl;
        return;
    }

    cout << endl;
    cout << "Dictionary:" << endl;

    displayTree(root);
}

int countNodes(Node* current)
{
    if (current == nullptr)
    {
        return 0;
    }

    return 1 + countNodes(current->left) + countNodes(current->right);
}

int Dictionary::size()
{
    return countNodes(root);
}

bool Dictionary::loadFromFile(string filename)
{
    ifstream file(filename);

    if (!file)
    {
        cout << "Could not open file." << endl;
        return false;
    }

    string english;
    string russian;

    while (file >> english >> russian)
    {
        insert(english, russian);
    }

    file.close();

    cout << "Dictionary loaded from file." << endl;

    return true;
}

void Dictionary::saveTree(Node* current, ofstream& file)
{
    if (current == nullptr)
    {
        return;
    }

    saveTree(current->left, file);

    file << current->english << " "
         << current->russian << endl;

    saveTree(current->right, file);
}

// NEW
bool Dictionary::saveToFile(string filename)
{
    ofstream file(filename);

    if (!file)
    {
        cout << "Could not create file." << endl;
        return false;
    }

    saveTree(root, file);

    file.close();

    cout << "Dictionary saved to file." << endl;

    return true;
}