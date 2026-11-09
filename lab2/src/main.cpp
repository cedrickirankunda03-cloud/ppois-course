
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>
#include <algorithm>

#include "students/Student.h"
#include "students/StudentGroup.h"
#include "teachers/Teacher.h"
#include "academic/Course.h"
#include "services/DeaneryService.h"

using namespace std;

// Read an integer safely
int readInt(const string& message)
{
    int value;

    while (true)
    {
        cout << message;

        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Invalid input. Enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Read a string
string readText(const string& message)
{
    string value;
    cout << message;
    getline(cin, value);
    return value;
}

// Project data
vector<unique_ptr<Student>> students;
vector<unique_ptr<Teacher>> teachers;
vector<unique_ptr<StudentGroup>> groups;
vector<unique_ptr<Course>> courses;

DeaneryService deanery("University Deanery");

// Find student by ID
Student* findStudent(const string& id)
{
    for (const auto& student : students)
    {
        if (student->getStudentId() == id)
            return student.get();
    }

    return nullptr;
}

// Find group by ID
StudentGroup* findGroup(int id)
{
    for (const auto& group : groups)
    {
        if (group->getGroupId() == id)
            return group.get();
    }

    return nullptr;
}

// Register a student
void addStudent()
{
    cout << "\n--- REGISTER STUDENT ---\n";

    string id = readText("Student ID: ");

    if (findStudent(id) != nullptr)
    {
        cout << "Student already exists.\n";
        return;
    }

    string first = readText("First name: ");
    string last = readText("Last name: ");
    int year = readInt("Year of study: ");

    try
    {
        auto student = make_unique<Student>(
            id, first, last, year
        );

        deanery.registerStudent(id);
        students.push_back(move(student));

        cout << "Student registered successfully!\n";
    }
    catch (const exception& e)
    {
        cout << "Registration failed: " << e.what() << '\n';
    }
}

// Display students
void displayStudents()
{
    cout << "\n--- STUDENT LIST ---\n";

    if (students.empty())
    {
        cout << "No students registered.\n";
        return;
    }

    for (const auto& student : students)
    {
        student->displayInformation();
        cout << "--------------------\n";
    }
}

// Register a teacher
void addTeacher()
{
    cout << "\n--- REGISTER TEACHER ---\n";

    string id = readText("Teacher ID: ");

    if (deanery.hasTeacher(id))
    {
        cout << "Teacher already registered.\n";
        return;
    }

    string first = readText("First name: ");
    string last = readText("Last name: ");
    string department = readText("Department: ");
    string specialization = readText("Specialization: ");

    double salary;

    while (true)
    {
        cout << "Salary: ";

        if (cin >> salary && salary >= 0)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        cout << "Enter a valid non-negative salary.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    try
    {
        auto teacher = make_unique<Teacher>(
            id, first, last, department,
            specialization, salary
        );

        deanery.registerTeacher(id);
        teachers.push_back(move(teacher));

        cout << "Teacher registered successfully!\n";
    }
    catch (const exception& e)
    {
        cout << "Registration failed: " << e.what() << '\n';
    }
}

// Display teachers
void displayTeachers()
{
    cout << "\n--- TEACHER LIST ---\n";

    if (teachers.empty())
    {
        cout << "No teachers registered.\n";
        return;
    }

    for (const auto& teacher : teachers)
    {
        teacher->displayInformation();
        cout << "--------------------\n";
    }
}

// Create a student group
void addGroup()
{
    cout << "\n--- CREATE STUDENT GROUP ---\n";

    int id = readInt("Group ID: ");

    if (findGroup(id) != nullptr)
    {
        cout << "Group already exists.\n";
        return;
    }

    string name = readText("Group name: ");

    try
    {
        auto group = make_unique<StudentGroup>(id, name);

        deanery.registerGroup(to_string(id));
        groups.push_back(move(group));

        cout << "Group created successfully!\n";
    }
    catch (const exception& e)
    {
        cout << "Group creation failed: " << e.what() << '\n';
    }
}

// Add a student to an existing group
void assignStudentToGroup()
{
    cout << "\n--- ASSIGN STUDENT TO GROUP ---\n";

    string studentId = readText("Student ID: ");
    int groupId = readInt("Group ID: ");

    Student* student = findStudent(studentId);
    StudentGroup* group = findGroup(groupId);

    if (student == nullptr)
    {
        cout << "Student not found.\n";
        return;
    }

    if (group == nullptr)
    {
        cout << "Group not found.\n";
        return;
    }

    try
    {
        group->addStudent(student);
        cout << "Student assigned successfully!\n";
    }
    catch (const exception& e)
    {
        cout << "Assignment failed: " << e.what() << '\n';
    }
}

// Display groups
void displayGroups()
{
    cout << "\n--- STUDENT GROUPS ---\n";

    if (groups.empty())
    {
        cout << "No groups registered.\n";
        return;
    }

    for (const auto& group : groups)
    {
        cout << "Group ID: " << group->getGroupId() << '\n';
        cout << "Group name: " << group->getGroupName() << '\n';
        cout << "Number of students: "
             << group->getStudentCount() << '\n';
        cout << "--------------------\n";
    }
}

// Register a course
void addCourse()
{
    cout << "\n--- REGISTER COURSE ---\n";

    string code = readText("Course code: ");

    for (const auto& course : courses)
    {
        if (course->getCode() == code)
        {
            cout << "Course already exists.\n";
            return;
        }
    }

    string name = readText("Course name: ");
    string description = readText("Description: ");
    int credits = readInt("Credits: ");

    try
    {
        courses.push_back(make_unique<Course>(
            code, name, description, credits
        ));

        cout << "Course registered successfully!\n";
    }
    catch (const exception& e)
    {
        cout << "Course registration failed: "
             << e.what() << '\n';
    }
}

// Display courses
void displayCourses()
{
    cout << "\n--- COURSE LIST ---\n";

    if (courses.empty())
    {
        cout << "No courses registered.\n";
        return;
    }

    for (const auto& course : courses)
    {
        cout << "Code: " << course->getCode() << '\n';
        cout << "Name: " << course->getName() << '\n';
        cout << "Description: "
             << course->getDescription() << '\n';
        cout << "Credits: " << course->getCredits() << '\n';
        cout << "--------------------\n";
    }
}

// Main menu
void showMenu()
{
    cout << "\n";
    cout << "====================================\n";
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
    cout << "0. Exit\n";
    cout << "====================================\n";
}

// Application entry point
int main()
{
    cout << "\nWelcome to the Dean's Office Management System!\n";

    int choice;

    do
    {
        showMenu();
        choice = readInt("Choose an option: ");

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                addTeacher();
                break;

            case 4:
                displayTeachers();
                break;

            case 5:
                addGroup();
                break;

            case 6:
                assignStudentToGroup();
                break;

            case 7:
                displayGroups();
                break;

            case 8:
                addCourse();
                break;

            case 9:
                displayCourses();
                break;

            case 0:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid option. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
