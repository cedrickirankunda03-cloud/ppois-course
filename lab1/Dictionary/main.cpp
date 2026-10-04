#include "Dictionary.h"
#include <iostream>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <windows.h>

using namespace std;

string wideToUtf8(const wstring& text)
{
    if (text.empty())
    {
        return "";
    }

    int size = WideCharToMultiByte(
        CP_UTF8,
        0,
        text.c_str(),
        -1,
        nullptr,
        0,
        nullptr,
        nullptr
    );

    string result(size - 1, '\0');

    WideCharToMultiByte(
        CP_UTF8,
        0,
        text.c_str(),
        -1,
        &result[0],
        size,
        nullptr,
        nullptr
    );

    return result;
}

wstring utf8ToWide(const string& text)
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

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    Dictionary dictionary;

    // Initial dictionary
    dictionary.insert("apple", "яблоко");
    dictionary.insert("cat", "кошка");
    dictionary.insert("dog", "собака");
    dictionary.insert("house", "дом");
    dictionary.insert("book", "книга");

    int choice = 0;

    while (choice != 9)
    {
        wcout << L"\n===== ENGLISH-RUSSIAN DICTIONARY =====\n";
        wcout << L"1. Add word\n";
        wcout << L"2. Remove word\n";
        wcout << L"3. Search word\n";
        wcout << L"4. Change translation\n";
        wcout << L"5. Display dictionary\n";
        wcout << L"6. Number of words\n";
        wcout << L"7. Load from file\n";
        wcout << L"8. Save to file\n";
        wcout << L"9. Exit\n";
        wcout << L"Choose an option: ";

        wcin >> choice;
        wcin.ignore(10000, L'\n');

        if (choice == 1)
        {
            wstring englishWide;
            wstring russian;

            wcout << L"Enter English word: ";
            wcin >> englishWide;
            wcin.ignore(10000, L'\n');

            wcout << L"Enter Russian translation: ";
            getline(wcin, russian);

            dictionary.insert(
                wideToUtf8(englishWide),
                wideToUtf8(russian)
            );
        }
        else if (choice == 2)
        {
            wstring englishWide;

            wcout << L"Enter English word to remove: ";
            wcin >> englishWide;
            wcin.ignore(10000, L'\n');

            dictionary -= wideToUtf8(englishWide);
        }
        else if (choice == 3)
        {
            wstring englishWide;

            wcout << L"Enter English word to search: ";
            wcin >> englishWide;
            wcin.ignore(10000, L'\n');

            string translation =
                dictionary.search(wideToUtf8(englishWide));

            if (translation.empty())
            {
                wcout << L"Word not found.\n";
            }
            else
            {
                wcout << L"Translation: "
                      << utf8ToWide(translation)
                      << L"\n";
            }
        }
        else if (choice == 4)
        {
            wstring englishWide;
            wstring russian;

            wcout << L"Enter English word: ";
            wcin >> englishWide;
            wcin.ignore(10000, L'\n');

            string english = wideToUtf8(englishWide);

            if (dictionary.search(english).empty())
            {
                wcout << L"Word not found.\n";
            }
            else
            {
                wcout << L"Enter new Russian translation: ";
                getline(wcin, russian);

                dictionary[english] = wideToUtf8(russian);

                wcout << L"Translation changed.\n";
            }
        }
        else if (choice == 5)
        {
            dictionary.display();
        }
        else if (choice == 6)
        {
            wcout << L"Number of words: "
                  << dictionary.size()
                  << L"\n";
        }
        else if (choice == 7)
        {
            wstring filenameWide;

            wcout << L"Enter filename: ";
            wcin >> filenameWide;
            wcin.ignore(10000, L'\n');

            dictionary.loadFromFile(
                wideToUtf8(filenameWide)
            );
        }
        else if (choice == 8)
        {
            wstring filenameWide;

            wcout << L"Enter filename: ";
            wcin >> filenameWide;
            wcin.ignore(10000, L'\n');

            dictionary.saveToFile(
                wideToUtf8(filenameWide)
            );
        }
        else if (choice == 9)
        {
            wcout << L"Goodbye!\n";
        }
        else
        {
            wcout << L"Invalid option.\n";
        }
    }

    return 0;
}