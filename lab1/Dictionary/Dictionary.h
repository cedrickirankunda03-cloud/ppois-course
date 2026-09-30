#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <fstream>

using namespace std;

// NEW
/**
 * @brief Node of the binary search tree.
 *
 * Stores an English word, its Russian translation,
 * and pointers to the left and right child nodes.
 */
struct Node
{
    string english;
    string russian;
    Node* left;
    Node* right;
};

// NEW
/**
 * @brief English-Russian dictionary implemented using a binary search tree.
 *
 * English words are used as keys and Russian words are stored as translations.
 */
class Dictionary
{
private:
    Node* root;

    Node* createNode(string english, string russian);

    // NEW
    /**
     * @brief Creates a copy of a binary search tree.
     */
    Node* copyTree(Node* current);

    // NEW
    /**
     * @brief Compares two binary search trees.
     */
    bool compareTrees(Node* first, Node* second) const;

    void displayTree(Node* current);
    void deleteTree(Node* current);
    void saveTree(Node* current, ofstream& file);

public:

    // NEW
    /**
     * @brief Creates an empty dictionary.
     */
    Dictionary();

    // NEW
    /**
     * @brief Destroys the dictionary and releases allocated memory.
     */
    ~Dictionary();

    // NEW
    /**
     * @brief Creates a copy of another dictionary.
     */
    Dictionary(const Dictionary& other);

    // NEW
    /**
     * @brief Assigns another dictionary to this dictionary.
     */
    Dictionary& operator=(const Dictionary& other);

    // NEW
    /**
     * @brief Checks whether two dictionaries are equal.
     */
    bool operator==(const Dictionary& other) const;

    // NEW
    /**
     * @brief Checks whether two dictionaries are different.
     */
    bool operator!=(const Dictionary& other) const;

    // NEW
    /**
     * @brief Adds an English word and its Russian translation.
     */
    void insert(string english, string russian);

    // NEW
    /**
     * @brief Adds an English word using a string.
     */
    Dictionary& operator+=(string english);

    // NEW
    /**
     * @brief Adds an English word using a C-string.
     */
    Dictionary& operator+=(const char* english);

    // NEW
    /**
     * @brief Removes an English word from the dictionary.
     */
    Dictionary& operator-=(string english);

    // NEW
    /**
     * @brief Finds or changes the Russian translation of an English word.
     */
    string& operator[](string english);

    // NEW
    /**
     * @brief Searches for the Russian translation of an English word.
     */
    string search(string english);

    // NEW
    /**
     * @brief Displays all words in alphabetical order.
     */
    void display();

    // NEW
    /**
     * @brief Returns the number of words in the dictionary.
     */
    int size();

    // NEW
    /**
     * @brief Loads words and translations from a file.
     *
     * @param filename Name of the input file.
     * @return true if the file was successfully opened, otherwise false.
     */
    bool loadFromFile(string filename);

    // NEW
    /**
     * @brief Saves the dictionary to a file.
     *
     * @param filename Name of the output file.
     * @return true if the file was successfully created, otherwise false.
     */
    bool saveToFile(string filename);
};

#endif