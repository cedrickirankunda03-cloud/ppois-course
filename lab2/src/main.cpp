#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>

#include "students/Student.h"
#include "students/StudentGroup.h"
#include "teachers/Teacher.h"
#include "academic/Course.h"
#include "services/DeaneryService.h"
#include "infrastructure/DormRoom.h"
#include "infrastructure/Library.h"
#include "infrastructure/LibraryBook.h"
#include "finance/Scholarship.h"
#include "finance/Payment.h"
#include "exceptions/StudentNotFoundException.h"

using namespace std;

int readInt(const string& message) {
    int value;
    while (true) {
        cout << message;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid input. Enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string readText(const string& message) {
    cout << message;
    string value;
    getline(cin, value);
    return value;
}

vector<unique_ptr<Student>> students;
vector<unique_ptr<Teacher>> teachers;
vector<unique_ptr<StudentGroup>> groups;
vector<unique_ptr<Course>> courses;
vector<unique_ptr<DormRoom>> dormRooms;
vector<unique_ptr<Library>> libraries;
vector<unique_ptr<LibraryBook>> libraryBooks;
vector<unique_ptr<Scholarship>> scholarships;
vector<unique_ptr<Payment>> payments;

DeaneryService deanery("University Deanery");

void printMenu() {
    cout << "\n====================================\n";
    cout << "       DEAN'S OFFICE SYSTEM\n";
    cout << "====================================\n";
    cout << "1. Register student\n";
    cout << "2. Display students\n";
    cout << "3. Register teacher\n";
    cout << "4. Display teachers\n";
    cout << "5. Create student group\n";
    cout << "6. Assign student to group\n";
    cout << "7. Display groups\n";
    cout << "8. Register course\n";
    cout << "9. Display courses\n";
    cout << "10. Add Dorm Room\n";
    cout << "11. Display Dorm Rooms\n";
    cout << "12. Register a Library\n";
    cout << "13. Add Book to Library\n";
    cout << "14. Award Scholarship\n";
    cout << "15. Process Payment\n";
    cout << "16. Demo Exception Handling\n";
    cout << "0. Exit\n";
    cout << "====================================\n";
}

int main() {
    cout << "Welcome to the Dean's Office Management System!\n";

    while (true) {
        printMenu();
        int choice = readInt("Choose an option: ");

        if (choice == 0) {
            cout << "\nThank you for using the system!\n";
            break;
        }

        try {
            switch (choice) {
                case 1: {
                    cout << "\n--- REGISTER STUDENT ---\n";
                    string id = readText("Student ID: ");
                    string first = readText("First name: ");
                    string last = readText("Last name: ");
                    int year = readInt("Year of study: ");
                    students.push_back(make_unique<Student>(id, first, last, year));
                    deanery.registerStudent(id);
                    cout << "Student registered successfully!\n";
                    break;
                }
                case 2: {
                    cout << "\n--- STUDENT LIST ---\n";
                    for (const auto& s : students) {
                        s->displayInformation();
                        cout << "--------------------\n";
                    }
                    break;
                }
                case 3: {
                    cout << "\n--- REGISTER TEACHER ---\n";
                    string id = readText("Teacher ID: ");
                    string first = readText("First name: ");
                    string last = readText("Last name: ");
                    string dept = readText("Department: ");
                    string spec = readText("Specialization: ");
                    double salary = readInt("Salary: ");
                    teachers.push_back(make_unique<Teacher>(id, first, last, dept, spec, salary));
                    deanery.registerTeacher(id);
                    cout << "Teacher registered successfully!\n";
                    break;
                }
                case 4: {
                    cout << "\n--- TEACHER LIST ---\n";
                    for (const auto& t : teachers) {
                        t->displayInformation();
                        cout << "--------------------\n";
                    }
                    break;
                }
                case 5: {
                    cout << "\n--- CREATE STUDENT GROUP ---\n";
                    int groupId = readInt("Group ID: ");
                    string name = readText("Group name: ");
                    groups.push_back(make_unique<StudentGroup>(groupId, name));
                    deanery.registerGroup(to_string(groupId));
                    cout << "Group created successfully!\n";
                    break;
                }
                case 6: {
                    cout << "\n--- ASSIGN STUDENT TO GROUP ---\n";
                    string studentId = readText("Student ID: ");
                    int groupId = readInt("Group ID: ");
                    Student* foundStudent = nullptr;
                    for (const auto& s : students) {
                        if (s->getStudentId() == studentId) foundStudent = s.get();
                    }
                    StudentGroup* foundGroup = nullptr;
                    for (const auto& g : groups) {
                        if (g->getGroupId() == groupId) foundGroup = g.get();
                    }
                    if (foundStudent && foundGroup) {
                        foundGroup->addStudent(foundStudent);
                        cout << "Student assigned successfully!\n";
                    } else {
                        cout << "Error: Student or Group not found.\n";
                    }
                    break;
                }
                case 7: {
                    cout << "\n--- STUDENT GROUPS ---\n";
                    for (const auto& g : groups) {
                        cout << "Group ID: " << g->getGroupId() << "\n";
                        cout << "Group name: " << g->getGroupName() << "\n";
                        cout << "Number of students: " << g->getStudentCount() << "\n";
                        cout << "--------------------\n";
                    }
                    break;
                }
                case 8: {
                    cout << "\n--- REGISTER COURSE ---\n";
                    string code = readText("Course code: ");
                    string name = readText("Course name: ");
                    string desc = readText("Description: ");
                    int credits = readInt("Credits: ");
                    courses.push_back(make_unique<Course>(code, name, desc, credits));
                    cout << "Course registered successfully!\n";
                    break;
                }
                case 9: {
                    cout << "\n--- COURSE LIST ---\n";
                    for (const auto& c : courses) {
                        cout << "Code: " << c->getCode() << "\n";
                        cout << "Name: " << c->getName() << "\n";
                        cout << "Description: " << c->getDescription() << "\n";
                        cout << "Credits: " << c->getCredits() << "\n";
                        cout << "--------------------\n";
                    }
                    break;
                }
                case 10: {
                    cout << "\n--- ADD DORM ROOM ---\n";
                    string roomId = readText("Room ID: ");
                    string dormId = readText("Dormitory ID: ");
                    int roomNum = readInt("Room Number: ");
                    int capacity = readInt("Capacity: ");
                    dormRooms.push_back(make_unique<DormRoom>(roomId, dormId, roomNum, capacity));
                    cout << "Dorm Room added successfully!\n";
                    break;
                }
                case 11: {
                    cout << "\n--- DORM ROOM LIST ---\n";
                    for (const auto& d : dormRooms) {
                        cout << "Room ID: " << d->getRoomId() << "\n";
                        cout << "Dormitory: " << d->getDormitoryId() << "\n";
                        cout << "Room Number: " << d->getRoomNumber() << "\n";
                        cout << "Capacity: " << d->getCapacity() << "\n";
                        cout << "--------------------\n";
                    }
                    break;
                }
                case 12: {
                    cout << "\n--- REGISTER LIBRARY ---\n";
                    string libId = readText("Library ID: ");
                    string libName = readText("Library Name: ");
                    string location = readText("Location: ");
                    int books = readInt("Total Books: ");
                    libraries.push_back(make_unique<Library>(libId, libName, location, books));
                    cout << "Library registered successfully!\n";
                    break;
                }
                case 13: {
                    cout << "\n--- ADD BOOK TO LIBRARY ---\n";
                    string bookId = readText("Book ID: ");
                    string title = readText("Title: ");
                    string author = readText("Author: ");
                    string libId = readText("Library ID: ");
                    libraryBooks.push_back(make_unique<LibraryBook>(bookId, title, author, libId));
                    cout << "Book added to library successfully!\n";
                    break;
                }
                case 14: {
                    cout << "\n--- AWARD SCHOLARSHIP ---\n";
                    string schId = readText("Scholarship ID: ");
                    string studentId = readText("Student ID: ");
                    double amount = readInt("Amount: ");
                    string year = readText("Academic Year (e.g. 2026-2027): ");
                    scholarships.push_back(make_unique<Scholarship>(schId, studentId, amount, year));
                    cout << "Scholarship awarded successfully!\n";
                    break;
                }
                case 15: {
                    cout << "\n--- PROCESS PAYMENT ---\n";
                    string paymentId = readText("Payment ID: ");
                    string contractId = readText("Contract ID: ");
                    string studentId = readText("Student ID: ");
                    double amount = readInt("Amount: ");
                    payments.push_back(make_unique<Payment>(paymentId, contractId, studentId, amount));
                    cout << "Payment processed successfully!\n";
                    break;
                }
                case 16: {
                    cout << "\n--- EXCEPTION DEMO ---\n";
                    cout << "Searching for student with ID 'UNKNOWN'...\n";
                    throw StudentNotFoundException("UNKNOWN");
                    break;
                }
                default:
                    cout << "Invalid option. Please try again.\n";
                    break;
            }
        } 
        catch (const DeaneryException& e) {
            cout << "\n[!] CUSTOM EXCEPTION CAUGHT: " << e.what() << "\n";
        }
        catch (const std::exception& e) {
            cout << "\n[!] ERROR: " << e.what() << "\n";
        }
    }
    return 0;
}
