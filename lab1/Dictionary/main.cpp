#include "Dictionary.h"
#include <iostream>

using namespace std;

int main()
{
    Dictionary dictionary;

    int choice = 0;

    while (choice != 9)
    {
        cout << endl;
        cout << "===== ENGLISH-RUSSIAN DICTIONARY =====" << endl;
        cout << "1. Add word" << endl;
        cout << "2. Remove word" << endl;
        cout << "3. Search word" << endl;
        cout << "4. Change translation" << endl;
        cout << "5. Display dictionary" << endl;
        cout << "6. Number of words" << endl;
        cout << "7. Load from file" << endl;
        cout << "8. Save to file" << endl;
        cout << "9. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1)
        {
            string english;

            cout << "Enter English word: ";
            cin >> english;

            dictionary += english;
        }
        else if (choice == 2)
        {
            string english;

            cout << "Enter English word to remove: ";
            cin >> english;

            dictionary -= english;
        }
        else if (choice == 3)
        {
            string english;

            cout << "Enter English word to search: ";
            cin >> english;

            cout << "Translation: "
                 << dictionary.search(english) << endl;
        }
        else if (choice == 4)
        {
            string english;
            string russian;

            cout << "Enter English word: ";
            cin >> english;

            cout << "Enter new Russian translation: ";
            cin >> russian;

            dictionary[english] = russian;

            cout << "Translation changed." << endl;
        }
        else if (choice == 5)
        {
            dictionary.display();
        }
        else if (choice == 6)
        {
            cout << "Number of words: "
                 << dictionary.size() << endl;
        }
        else if (choice == 7)
        {
            string filename;

            cout << "Enter filename: ";
            cin >> filename;

            dictionary.loadFromFile(filename);
        }
        else if (choice == 8)
        {
            string filename;

            cout << "Enter filename: ";
            cin >> filename;

            dictionary.saveToFile(filename);
        }
        else if (choice == 9)
        {
            cout << "Goodbye!" << endl;
        }
        else
        {
            cout << "Invalid option." << endl;
        }
    }

    return 0;
}