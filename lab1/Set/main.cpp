
#include "Set.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    Set A;
    Set B;
    int choice;

    do
    {
        cout << "\n===== UNORDERED CANTOR SET =====\n";
        cout << "1. Display both sets\n";
        cout << "2. Enter Set A\n";
        cout << "3. Enter Set B\n";
        cout << "4. Add element to A\n";
        cout << "5. Add element to B\n";
        cout << "6. Remove element from A\n";
        cout << "7. Remove element from B\n";
        cout << "8. Check membership in A\n";
        cout << "9. Check membership in B\n";
        cout << "10. Union (A + B)\n";
        cout << "11. Intersection (A * B)\n";
        cout << "12. Difference (A - B)\n";
        cout << "13. Power set of A\n";
        cout << "14. Power set of B\n";
        cout << "15. Compare A and B\n";
        cout << "16. A += B (union and update A)\n";
        cout << "17. A *= B (intersection and update A)\n";
        cout << "18. A -= B (difference and update A)\n";
        cout << "19. Show sizes and empty status\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string text;
        string element;

        switch (choice)
        {
        case 1:
            cout << "Set A: " << A.toString() << '\n';
            cout << "Set B: " << B.toString() << '\n';
            break;

        case 2:
            cout << "Enter Set A, for example {a, b, {c, d}}: ";
            getline(cin, text);
            A = Set::fromString(text);
            cout << "Set A updated: " << A.toString() << '\n';
            break;

        case 3:
            cout << "Enter Set B, for example {b, c}: ";
            getline(cin, text);
            B = Set::fromString(text);
            cout << "Set B updated: " << B.toString() << '\n';
            break;

        case 4:
            cout << "Enter element to add to A: ";
            getline(cin, element);
            A.add(element);
            cout << "Set A: " << A.toString() << '\n';
            break;

        case 5:
            cout << "Enter element to add to B: ";
            getline(cin, element);
            B.add(element);
            cout << "Set B: " << B.toString() << '\n';
            break;

        case 6:
            cout << "Enter element to remove from A: ";
            getline(cin, element);
            A.remove(element);
            cout << "Set A: " << A.toString() << '\n';
            break;

        case 7:
            cout << "Enter element to remove from B: ";
            getline(cin, element);
            B.remove(element);
            cout << "Set B: " << B.toString() << '\n';
            break;

        case 8:
            cout << "Enter element to find in A: ";
            getline(cin, element);
            cout << (A.contains(element) ? "Element exists.\n" :
                                           "Element not found.\n");
            break;

        case 9:
            cout << "Enter element to find in B: ";
            getline(cin, element);
            cout << (B.contains(element) ? "Element exists.\n" :
                                           "Element not found.\n");
            break;

        case 10:
            cout << "Union: " << (A + B).toString() << '\n';
            break;

        case 11:
            cout << "Intersection: " << (A * B).toString() << '\n';
            break;

        case 12:
            cout << "Difference A - B: " << (A - B).toString() << '\n';
            break;

        case 13:
            cout << "Power set of A: " << A.powerSet().toString() << '\n';
            break;

        case 14:
            cout << "Power set of B: " << B.powerSet().toString() << '\n';
            break;

        case 15:
            if (A == B)
                cout << "A and B are equal.\n";
            else
                cout << "A and B are not equal.\n";
            break;

        case 16:
            A += B;
            cout << "Updated A: " << A.toString() << '\n';
            break;

        case 17:
            A *= B;
            cout << "Updated A: " << A.toString() << '\n';
            break;

        case 18:
            A -= B;
            cout << "Updated A: " << A.toString() << '\n';
            break;

        case 19:
            cout << "Size of A: " << A.size() << '\n';
            cout << "Size of B: " << B.size() << '\n';
            cout << "Is A empty? " << (A.empty() ? "Yes" : "No") << '\n';
            cout << "Is B empty? " << (B.empty() ? "Yes" : "No") << '\n';
            break;

        case 0:
            cout << "Program finished.\n";
            break;

        default:
            cout << "Invalid option. Choose a number from 0 to 19.\n";
        }

    } while (choice != 0);

    return 0;
}