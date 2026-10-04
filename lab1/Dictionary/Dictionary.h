#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <fstream>

class Dictionary
{
private:
    struct Node
    {
        std::string english;
        std::string russian;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* createNode(const std::string& english,
                     const std::string& russian);

    void deleteTree(Node* node);

    void displayTree(Node* node) const;

    Node* findNode(Node* node,
                   const std::string& english) const;

    Node* removeNode(Node* node,
                     const std::string& english);

    Node* findMinimum(Node* node) const;

    int countNodes(Node* node) const;

    void saveTreeToFile(Node* node,
                        std::ofstream& file) const;

public:
    Dictionary();
    ~Dictionary();

    void insert(const std::string& english,
                const std::string& russian);

    Dictionary& operator+=(const std::string& english);

    Dictionary& operator+=(const char* english);

    Dictionary& operator-=(const std::string& english);

    std::string& operator[](const std::string& english);

    std::string search(const std::string& english) const;

    void display() const;

    int size() const;

    void loadFromFile(const std::string& filename);

    void saveToFile(const std::string& filename) const;
};

#endif