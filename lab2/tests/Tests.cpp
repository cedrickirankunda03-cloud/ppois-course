#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>

#include "students/InternationalStudent.h"

#include "infrastructure/Address.h"
#include "infrastructure/Building.h"
#include "infrastructure/ContactInfo.h"
#include "infrastructure/Infrastructure.h"
#include "infrastructure/LibraryCard.h"
#include "infrastructure/Transport.h"

#include "administration/Building.h"
#include "administration/Room.h"
#include "administration/Schedule.h"
#include "services/ScholarshipManager.h"
#include "administration/Application.h"
#include "administration/Order.h"

#include "finance/Contract.h"
#include "finance/Finance.h"

#include "services/DeaneryService.h"
#include "teachers/Teacher.h"
#include "teachers/Professor.h"
#include "teachers/TeacherContract.h"
#include "teachers/TeacherEvaluation.h"
#include "teachers/TeacherResearch.h"
#include "teachers/TeacherSchedule.h"

#include "students/Student.h"
#include "students/StudentProfile.h"
#include "students/Enrollment.h"
#include "students/StudentGroup.h"
#include "students/Transcript.h"
#include "students/UndergraduateStudent.h"
#include "students/GraduateStudent.h"

#include "exceptions/DeaneryException.h"
#include "exceptions/StudentNotFoundException.h"
#include "exceptions/TeacherNotFoundException.h"
#include "exceptions/GroupNotFoundException.h"
#include "exceptions/GradeOutOfBoundsException.h"
#include "exceptions/ScheduleConflictException.h"
#include "exceptions/InvalidDocumentException.h"
#include "exceptions/UnauthorizedAccessException.h"
#include "exceptions/ScholarshipLimitExceededException.h"
#include "exceptions/RoomCapacityExceededException.h"
#include "exceptions/DuplicateEntityException.h"
#include "exceptions/MissingPrerequisiteException.h"

#include "academic/Academic.h"
#include "academic/Course.h"
#include "academic/Grade.h"
#include "academic/GradeBook.h"
#include "academic/Subject.h"

#include "infrastructure/DormRoom.h"
#include "infrastructure/Dormitory.h"
#include "infrastructure/Cafeteria.h"
#include "infrastructure/Meal.h"
#include "infrastructure/Route.h"
#include "infrastructure/Book.h"
#include "infrastructure/Library.h"
#include "infrastructure/LibraryBook.h"
#include "academic/Department.h"
#include "academic/Semester.h"
#include "academic/Timetable.h"
#include "academic/Faculty.h"
#include "academic/Lecturer.h"
#include "academic/ExamSheet.h"
#include "finance/Payment.h"
#include "finance/Scholarship.h"
#include "finance/ScholarshipManager.h"



#include "services/Notification.h"
#include "services/NotificationService.h"
#include "teachers/Curator.h"
#include "teachers/DepartmentHead.h"
#include "teachers/HeadOfDepartment.h"
#include "teachers/LabAssistant.h"

int passed = 0;
int failed = 0;

// Record test results
void check(bool condition, const std::string& testName)
{
    if (condition)
    {
        std::cout << "[PASS] " << testName << std::endl;
        passed++;
    }
    else
    {
        std::cout << "[FAIL] " << testName << std::endl;
        failed++;
    }
}

// Check whether an expected exception is thrown
template <typename ExceptionType, typename Function>
void checkThrows(Function function, const std::string& testName)
{
    bool exceptionThrown = false;

    try
    {
        function();
    }
    catch (const ExceptionType&)
    {
        exceptionThrown = true;
    }
    catch (...)
    {
    }

    check(exceptionThrown, testName);
}

// Helper for testing any standard exception
template <typename Function>
void throws(Function function, const std::string& testName)
{
    checkThrows<std::exception>(function, testName);
}

// Test StudentNotFoundException
void testStudentNotFoundException()
{
    try
    {
        throw StudentNotFoundException("S001");
    }
    catch (const StudentNotFoundException& exception)
    {
        check(
            std::string(exception.what()) == "Student not found: S001",
            "StudentNotFoundException"
        );
    }
    catch (...)
    {
        check(false, "StudentNotFoundException");
    }
}

// Generic test for other exceptions
template <typename ExceptionType>
void testException(const std::string& testName)
{
    try
    {
        throw ExceptionType(testName);
    }
    catch (const ExceptionType& exception)
    {
        check(
            std::string(exception.what()) == testName,
            testName
        );
    }
    catch (...)
    {
        check(false, testName);
    }
}

// Test all 12 custom exceptions
void testAllExceptions()
{
    std::cout << "\n========== EXCEPTION TESTS ==========\n";

    testException<DeaneryException>("DeaneryException");
    testStudentNotFoundException();

    testException<TeacherNotFoundException>("TeacherNotFoundException");
    testException<GroupNotFoundException>("GroupNotFoundException");
    testException<GradeOutOfBoundsException>("GradeOutOfBoundsException");
    testException<ScheduleConflictException>("ScheduleConflictException");
    testException<InvalidDocumentException>("InvalidDocumentException");
    testException<UnauthorizedAccessException>("UnauthorizedAccessException");
    testException<ScholarshipLimitExceededException>("ScholarshipLimitExceededException");
    testException<RoomCapacityExceededException>("RoomCapacityExceededException");
    testException<DuplicateEntityException>("DuplicateEntityException");
    testException<MissingPrerequisiteException>("MissingPrerequisiteException");
}

// Test Teacher class
void testTeacher()
{
    std::cout << "\n========== TEACHER TESTS ==========\n";

    Teacher teacher(
        "T001",
        "John",
        "Smith",
        "Computer Science",
        "Software Engineering",
        3500.0
    );

    check(teacher.getTeacherId() == "T001", "Teacher ID getter");
    check(teacher.getFullName() == "John Smith", "Teacher full name getter");
    check(teacher.getDepartment() == "Computer Science", "Teacher department getter");
    check(teacher.getSalary() == 3500.0, "Teacher salary getter");

    teacher.updateDepartment("Mathematics");

    check(
        teacher.getDepartment() == "Mathematics",
        "Update teacher department"
    );

    teacher.updateSalary(4200.0);

    check(
        teacher.getSalary() == 4200.0,
        "Update teacher salary"
    );

    checkThrows<std::invalid_argument>(
        [&teacher] { teacher.updateDepartment(""); },
        "Reject empty updated teacher department"
    );

    checkThrows<std::invalid_argument>(
        [&teacher] { teacher.updateSalary(-100.0); },
        "Reject negative updated teacher salary"
    );

    checkThrows<std::invalid_argument>(
        [] {
            Teacher invalid(
                "", "John", "Smith", "Computer Science",
                "Software Engineering", 3500.0
            );
        },
        "Reject empty teacher ID"
    );

    checkThrows<std::invalid_argument>(
        [] {
            Teacher invalid(
                "T002", "", "Smith", "Computer Science",
                "Software Engineering", 3500.0
            );
        },
        "Reject empty teacher first name"
    );

    checkThrows<std::invalid_argument>(
        [] {
            Teacher invalid(
                "T003", "John", "", "Computer Science",
                "Software Engineering", 3500.0
            );
        },
        "Reject empty teacher last name"
    );

    checkThrows<std::invalid_argument>(
        [] {
            Teacher invalid(
                "T004", "John", "Smith", "",
                "Software Engineering", 3500.0
            );
        },
        "Reject empty teacher department"
    );

    checkThrows<std::invalid_argument>(
        [] {
            Teacher invalid(
                "T005", "John", "Smith", "Computer Science",
                "", 3500.0
            );
        },
        "Reject empty teacher specialization"
    );

    checkThrows<std::invalid_argument>(
        [] {
            Teacher invalid(
                "T006", "John", "Smith", "Computer Science",
                "Software Engineering", -100.0
            );
        },
        "Reject negative teacher salary"
    );

    std::ostringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf();

    std::cout.rdbuf(output.rdbuf());
    teacher.displayInformation();
    std::cout.rdbuf(originalBuffer);

    check(output.str().find("T001") != std::string::npos, "Display teacher ID");
    check(output.str().find("John Smith") != std::string::npos, "Display teacher full name");
    check(output.str().find("Mathematics") != std::string::npos, "Display updated teacher department");
}

// Test Professor class
void testProfessor()
{
    std::cout << "\n========== PROFESSOR TESTS ==========\n";

    Professor professor(
        "P001",
        "Alice",
        "Brown",
        "Computer Science",
        "Artificial Intelligence",
        5000.0,
        "Associate Professor",
        "Machine Learning",
        10,
        25
    );

    check(professor.getTeacherId() == "P001", "Professor inherited teacher ID getter");
    check(professor.getFullName() == "Alice Brown", "Professor inherited full name getter");
    check(professor.getDepartment() == "Computer Science", "Professor inherited department getter");
    check(professor.getSalary() == 5000.0, "Professor inherited salary getter");
    check(professor.getAcademicRank() == "Associate Professor", "Professor academic rank getter");
    check(professor.getResearchField() == "Machine Learning", "Professor research field getter");
    check(professor.getPublications() == 25, "Professor publications getter");

    professor.addPublication();

    check(professor.getPublications() == 26, "Add professor publication");

    professor.updateAcademicRank("Full Professor");

    check(professor.getAcademicRank() == "Full Professor", "Update professor academic rank");

    checkThrows<std::invalid_argument>(
        [&professor] { professor.updateAcademicRank(""); },
        "Reject empty updated professor rank"
    );

    checkThrows<std::invalid_argument>(
        [] {
            Professor invalid(
                "P002", "John", "Smith", "Computer Science",
                "Artificial Intelligence", 5000.0,
                "", "Machine Learning", 10, 25
            );
        },
        "Reject empty professor academic rank"
    );

    checkThrows<std::invalid_argument>(
        [] {
            Professor invalid(
                "P003", "John", "Smith", "Computer Science",
                "Artificial Intelligence", 5000.0,
                "Professor", "", 10, 25
            );
        },
        "Reject empty professor research field"
    );

    checkThrows<std::invalid_argument>(
        [] {
            Professor invalid(
                "P004", "John", "Smith", "Computer Science",
                "Artificial Intelligence", 5000.0,
                "Professor", "Machine Learning", -1, 25
            );
        },
        "Reject negative professor experience"
    );

    checkThrows<std::invalid_argument>(
        [] {
            Professor invalid(
                "P005", "John", "Smith", "Computer Science",
                "Artificial Intelligence", 5000.0,
                "Professor", "Machine Learning", 10, -1
            );
        },
        "Reject negative professor publications"
    );

    checkThrows<std::invalid_argument>(
        [] {
            Professor invalid(
                "", "John", "Smith", "Computer Science",
                "Artificial Intelligence", 5000.0,
                "Professor", "Machine Learning", 10, 25
            );
        },
        "Reject empty professor teacher ID"
    );

    std::ostringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf();

    std::cout.rdbuf(output.rdbuf());
    professor.displayProfessorInformation();
    std::cout.rdbuf(originalBuffer);

    check(output.str().find("Alice Brown") != std::string::npos, "Display professor name");
    check(output.str().find("Full Professor") != std::string::npos, "Display updated professor rank");
    check(output.str().find("Machine Learning") != std::string::npos, "Display professor research field");
    check(output.str().find("26") != std::string::npos, "Display professor publication count");
}

// Test TeacherContract class
void testTeacherContract()
{
    std::cout << "\n========== TEACHER CONTRACT TESTS ==========\n";

    TeacherContract contract(
        "C001", "T001", "Full-time",
        "2026-01-01", "2026-12-31"
    );

    check(contract.getContractId() == "C001", "Contract ID getter");
    check(contract.getTeacherId() == "T001", "Contract teacher ID getter");
    check(contract.getContractType() == "Full-time", "Contract type getter");
    check(contract.getStartDate() == "2026-01-01", "Contract start date getter");
    check(contract.getEndDate() == "2026-12-31", "Contract end date getter");
    check(contract.isActive(), "Contract initially active");

    contract.deactivate();
    check(!contract.isActive(), "Deactivate contract");

    contract.activate();
    check(contract.isActive(), "Activate contract");

    contract.updateEndDate("2027-12-31");
    check(contract.getEndDate() == "2027-12-31", "Update contract end date");

    checkThrows<std::invalid_argument>(
        [] { TeacherContract invalid("", "T001", "Full-time", "2026-01-01", "2026-12-31"); },
        "Reject empty contract ID"
    );

    checkThrows<std::invalid_argument>(
        [] { TeacherContract invalid("C002", "", "Full-time", "2026-01-01", "2026-12-31"); },
        "Reject empty contract teacher ID"
    );

    checkThrows<std::invalid_argument>(
        [] { TeacherContract invalid("C003", "T001", "", "2026-01-01", "2026-12-31"); },
        "Reject empty contract type"
    );

    checkThrows<std::invalid_argument>(
        [] { TeacherContract invalid("C004", "T001", "Full-time", "", "2026-12-31"); },
        "Reject empty contract start date"
    );

    checkThrows<std::invalid_argument>(
        [] { TeacherContract invalid("C005", "T001", "Full-time", "2026-01-01", ""); },
        "Reject empty contract end date"
    );

    checkThrows<std::invalid_argument>(
        [&contract] { contract.updateEndDate(""); },
        "Reject empty updated contract end date"
    );
}

// Test TeacherEvaluation class
void testTeacherEvaluation()
{
    std::cout << "\n========== TEACHER EVALUATION TESTS ==========\n";

    TeacherEvaluation evaluation(
        "E001", "T001", "2026-10-15",
        8.5, "Very good teaching"
    );

    check(evaluation.getEvaluationId() == "E001", "Evaluation ID getter");
    check(evaluation.getTeacherId() == "T001", "Evaluation teacher ID getter");
    check(evaluation.getTeachingScore() == 8.5, "Evaluation teaching score getter");
    check(evaluation.getComments() == "Very good teaching", "Evaluation comments getter");

    evaluation.updateScore(9.5);
    check(evaluation.getTeachingScore() == 9.5, "Update evaluation score");

    evaluation.updateComments("Excellent teaching");
    check(evaluation.getComments() == "Excellent teaching", "Update evaluation comments");

    evaluation.updateScore(0.0);
    check(evaluation.getTeachingScore() == 0.0, "Accept minimum evaluation score");

    evaluation.updateScore(10.0);
    check(evaluation.getTeachingScore() == 10.0, "Accept maximum evaluation score");

    checkThrows<std::invalid_argument>(
        [] { TeacherEvaluation invalid("E002", "T001", "2026-10-15", -1.0, "Invalid"); },
        "Reject negative evaluation score"
    );

    checkThrows<std::invalid_argument>(
        [] { TeacherEvaluation invalid("E003", "T001", "2026-10-15", 11.0, "Invalid"); },
        "Reject evaluation score above 10"
    );

    checkThrows<std::invalid_argument>(
        [&evaluation] { evaluation.updateScore(-1.0); },
        "Reject negative updated evaluation score"
    );

    checkThrows<std::invalid_argument>(
        [&evaluation] { evaluation.updateScore(11.0); },
        "Reject updated evaluation score above 10"
    );

    std::ostringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf();

    std::cout.rdbuf(output.rdbuf());
    evaluation.displayEvaluationInformation();
    std::cout.rdbuf(originalBuffer);

    check(output.str().find("E001") != std::string::npos, "Display evaluation ID");
    check(output.str().find("T001") != std::string::npos, "Display evaluation teacher ID");
    check(output.str().find("2026-10-15") != std::string::npos, "Display evaluation date");
    check(output.str().find("Excellent teaching") != std::string::npos, "Display updated evaluation comments");
}

// Test TeacherResearch class
void testTeacherResearch()
{
    std::cout << "\n========== TEACHER RESEARCH TESTS ==========\n";

    TeacherResearch research(
        "R001",
        "T001",
        "Artificial Intelligence",
        "Journal of Computer Science",
        2026
    );

    check(research.getResearchId() == "R001", "Research ID getter");
    check(research.getTeacherId() == "T001", "Research teacher ID getter");
    check(research.getResearchTitle() == "Artificial Intelligence", "Research title getter");
    check(research.getPublication() == "Journal of Computer Science", "Research publication getter");
    check(research.getPublicationYear() == 2026, "Research publication year getter");

    research.updatePublication("International AI Conference");

    check(research.getPublication() == "International AI Conference", "Update research publication");

    std::ostringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf();

    std::cout.rdbuf(output.rdbuf());
    research.displayResearchInformation();
    std::cout.rdbuf(originalBuffer);

    check(output.str().find("R001") != std::string::npos, "Display research ID");
    check(output.str().find("T001") != std::string::npos, "Display research teacher ID");
    check(output.str().find("Artificial Intelligence") != std::string::npos, "Display research title");
    check(output.str().find("International AI Conference") != std::string::npos, "Display updated research publication");
    check(output.str().find("2026") != std::string::npos, "Display research publication year");
}

// Test TeacherSchedule class
void testTeacherSchedule()
{
    std::cout << "\n========== TEACHER SCHEDULE TESTS ==========\n";

    TeacherSchedule schedule("T001");

    check(schedule.getTeacherId() == "T001", "Schedule teacher ID getter");
    check(schedule.getLessonCount() == 0, "Schedule initially empty");
    check(schedule.getLessons().empty(), "Schedule initially has no lessons");

    schedule.addLesson("Monday - Mathematics");

    check(schedule.getLessonCount() == 1, "Add first lesson");

    schedule.addLesson("Tuesday - Programming");

    check(schedule.getLessonCount() == 2, "Add second lesson");

    std::vector<std::string> lessons = schedule.getLessons();

    check(lessons.size() == 2, "Retrieve all scheduled lessons");
    check(lessons[0] == "Monday - Mathematics", "Verify first scheduled lesson");
    check(lessons[1] == "Tuesday - Programming", "Verify second scheduled lesson");

    schedule.removeLesson("Monday - Mathematics");

    check(schedule.getLessonCount() == 1, "Remove existing lesson");

    check(
        schedule.getLessons()[0] == "Tuesday - Programming",
        "Verify remaining lesson after removal"
    );

    schedule.removeLesson("Missing lesson");

    check(schedule.getLessonCount() == 1, "Removing missing lesson changes nothing");

    checkThrows<std::invalid_argument>(
        [] { TeacherSchedule invalid(""); },
        "Reject empty schedule teacher ID"
    );

    checkThrows<std::invalid_argument>(
        [&schedule] { schedule.addLesson(""); },
        "Reject empty scheduled lesson"
    );
}

// Test Student class
void testStudent()
{
    std::cout << "\n========== STUDENT TESTS ==========\n";

    Student student("S001", "John", "Smith", 2);

    check(student.getStudentId() == "S001", "Student ID getter");
    check(student.getFirstName() == "John", "Student first name getter");
    check(student.getLastName() == "Smith", "Student last name getter");
    check(student.getYearOfStudy() == 2, "Student year getter");

    checkThrows<std::invalid_argument>(
        [] { Student invalid("", "John", "Smith", 2); },
        "Reject empty student ID"
    );

    checkThrows<std::invalid_argument>(
        [] { Student invalid("S002", "", "Smith", 2); },
        "Reject empty first name"
    );

    checkThrows<std::invalid_argument>(
        [] { Student invalid("S003", "John", "", 2); },
        "Reject empty last name"
    );

    checkThrows<std::invalid_argument>(
        [] { Student invalid("S004", "John", "Smith", 0); },
        "Reject invalid study year"
    );

    checkThrows<std::invalid_argument>(
        [] { Student invalid("S005", "John", "Smith", 7); },
        "Reject study year above 6"
    );

    student.updateName("Michael", "Brown");

    check(student.getFirstName() == "Michael" && student.getLastName() == "Brown", "Update student name");

    checkThrows<std::invalid_argument>(
        [&student] { student.updateName("", "Brown"); },
        "Reject empty updated name"
    );

    student.promoteToNextYear();

    check(student.getYearOfStudy() == 3, "Promote student to next year");

    Student finalYearStudent("S006", "Anna", "Green", 6);
    finalYearStudent.promoteToNextYear();

    check(finalYearStudent.getYearOfStudy() == 6, "Do not promote beyond year 6");

    std::ostringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf();

    std::cout.rdbuf(output.rdbuf());
    student.displayInformation();
    std::cout.rdbuf(originalBuffer);

    check(output.str().find("S001") != std::string::npos, "Display student information");
    check(output.str().find("Michael Brown") != std::string::npos, "Display updated student name");
}

// Test StudentProfile class
void testStudentProfile()
{
    std::cout << "\n========== STUDENT PROFILE TESTS ==========\n";

    StudentProfile profile("S001", "john@example.com", "123456789", "Amsterdam");

    check(profile.getStudentId() == "S001", "StudentProfile ID getter");
    check(profile.getEmail() == "john@example.com", "StudentProfile email getter");
    check(profile.getPhoneNumber() == "123456789", "StudentProfile phone getter");
    check(profile.getAddress() == "Amsterdam", "StudentProfile address getter");

    profile.setEmail("michael@example.com");
    profile.setPhoneNumber("987654321");
    profile.setAddress("Rotterdam");

    check(profile.getEmail() == "michael@example.com", "Update profile email");
    check(profile.getPhoneNumber() == "987654321", "Update profile phone number");
    check(profile.getAddress() == "Rotterdam", "Update profile address");

    checkThrows<std::invalid_argument>(
        [&profile] { profile.setEmail(""); },
        "Reject empty profile email"
    );

    checkThrows<std::invalid_argument>(
        [&profile] { profile.setPhoneNumber(""); },
        "Reject empty profile phone"
    );

    checkThrows<std::invalid_argument>(
        [&profile] { profile.setAddress(""); },
        "Reject empty profile address"
    );
}

// Test Enrollment class
void testEnrollment()
{
    std::cout << "\n========== ENROLLMENT TESTS ==========\n";

    Enrollment enrollment(1, 101, 201, "2026-09-01");

    check(enrollment.getEnrollmentId() == 1, "Enrollment ID");
    check(enrollment.getStudentId() == 101, "Enrollment student ID");
    check(enrollment.getCourseId() == 201, "Enrollment course ID");
    check(enrollment.getEnrollmentDate() == "2026-09-01", "Enrollment date");
    check(enrollment.isActive(), "Enrollment initially active");

    enrollment.setStatus("Completed");

    check(enrollment.getStatus() == "Completed", "Set enrollment completed");
    check(!enrollment.isActive(), "Completed enrollment is inactive");

    enrollment.setStatus("Cancelled");

    check(enrollment.getStatus() == "Cancelled", "Set enrollment cancelled");

    checkThrows<std::invalid_argument>(
        [] { Enrollment invalid(0, 101, 201, "2026-09-01"); },
        "Reject invalid enrollment ID"
    );

    checkThrows<std::invalid_argument>(
        [] { Enrollment invalid(1, 101, 201, ""); },
        "Reject empty enrollment date"
    );

    checkThrows<std::invalid_argument>(
        [&enrollment] { enrollment.setStatus("Unknown"); },
        "Reject invalid enrollment status"
    );
}

// Test StudentGroup class
void testStudentGroup()
{
    std::cout << "\n========== STUDENT GROUP TESTS ==========\n";

    Student student("S101", "John", "Smith", 2);
    StudentGroup group(1, "Group A");

    check(group.getGroupId() == 1, "StudentGroup ID");
    check(group.getGroupName() == "Group A", "StudentGroup name");
    check(group.getStudentCount() == 0, "StudentGroup initially empty");

    group.addStudent(&student);

    check(group.getStudentCount() == 1, "Add student to group");

    checkThrows<std::invalid_argument>(
        [&group, &student] { group.addStudent(&student); },
        "Reject duplicate student in group"
    );

    checkThrows<std::invalid_argument>(
        [&group] { group.addStudent(nullptr); },
        "Reject null student"
    );

    group.removeStudent(&student);

    check(group.getStudentCount() == 0, "Remove student from group");

    group.removeStudent(&student);

    check(group.getStudentCount() == 0, "Removing absent student changes nothing");

    checkThrows<std::invalid_argument>(
        [] { StudentGroup invalid(0, "Group B"); },
        "Reject invalid group ID"
    );
}

// Test Transcript class
void testTranscript()
{
    std::cout << "\n========== TRANSCRIPT TESTS ==========\n";

    Student student("S102", "Alice", "Brown", 3);
    Transcript transcript(&student, "2026-2027");

    check(transcript.getAcademicYear() == "2026-2027", "Transcript academic year");
    check(transcript.getGrades().empty(), "Transcript initially has no grades");

    Grade grade("S102", "CS101", 95);
    transcript.addGrade(grade);

    check(transcript.getGrades().size() == 1, "Add grade to transcript");
    check(transcript.getGrades()[0].getScore() == 95, "Transcript stores correct grade");

    Student anotherStudent("S103", "Mark", "Jones", 2);
    transcript.setStudent(&anotherStudent);

    check(true, "Change transcript student");

    checkThrows<std::invalid_argument>(
        [] { Transcript invalid(nullptr, "2026-2027"); },
        "Reject null transcript student"
    );

    checkThrows<std::invalid_argument>(
        [&transcript] { transcript.setStudent(nullptr); },
        "Reject null replacement student"
    );

    checkThrows<std::invalid_argument>(
        [&student] { Transcript invalid(&student, ""); },
        "Reject empty transcript academic year"
    );
}

void testInfrastructure()
{
    std::cout << "\n===== INFRASTRUCTURE TESTS =====\n";

    // Address
    Address address(
        "ADDR1", "Main Street", "Berlin", "10115", "Germany"
    );

    check(address.getAddressId() == "ADDR1",
          "Address returns the correct ID");

    check(!address.getFullAddress().empty(),
          "Address returns its full address");

    address.updateAddress(
        "New Street", "Hamburg", "20095", "Germany"
    );

    check(address.getFullAddress().find("Hamburg") != std::string::npos,
          "Address updates its location");

    // InfrastructureBuilding
    InfrastructureBuilding building(
        "BLD1", "Main Building", "ADDR1", 4
    );

    check(building.getBuildingId() == "BLD1",
          "Building returns its ID");

    check(building.getBuildingName() == "Main Building",
          "Building returns its name");

    check(building.getAddressId() == "ADDR1",
          "Building returns its address ID");

    building.updateBuildingName("New Main Building");

    check(building.getBuildingName() == "New Main Building",
          "Building updates its name");

    // LibraryCard
    LibraryCard card("CARD1", "STU1", "BOOK1");

    check(card.hasBorrowedBook(),
          "Library card starts with a borrowed book");

    card.returnBook();

    check(!card.hasBorrowedBook(),
          "Library card returns a borrowed book");

    card.borrowBook("BOOK2");

    check(card.hasBorrowedBook(),
          "Library card can borrow another book");

    // Transport
    Transport transport(
        "TR1", "Bus", "Route A", 50, 2.50
    );

    check(transport.hasAvailableSeats(30),
          "Transport has seats for 30 passengers");

    check(!transport.hasAvailableSeats(60),
          "Transport has no seats for 60 passengers");

    check(transport.hasAvailableSeats(50),
          "Transport accepts exactly its capacity");
}

// Test UndergraduateStudent class
void testUndergraduateStudent()
{
    std::cout << "\n========== UNDERGRADUATE STUDENT TESTS ==========\n";

    UndergraduateStudent student("U101", "Peter", "Green", 2, "Computer Science", 30);

    check(student.getSpecialization() == "Computer Science", "Undergraduate specialization");
    check(student.getCreditsCompleted() == 30, "Undergraduate initial credits");
    check(!student.isEligibleForInternship(), "Not eligible with insufficient credits");

    student.completeCredits(30);

    check(student.getCreditsCompleted() == 60, "Complete additional credits");
    check(student.isEligibleForInternship(), "Eligible for internship with 60 credits");
    check(student.registerForInternship(), "Register eligible student for internship");
    check(!student.registerForInternship(), "Prevent duplicate internship registration");

    checkThrows<std::invalid_argument>(
        [&student] { student.completeCredits(0); },
        "Reject zero additional credits"
    );

    checkThrows<std::invalid_argument>(
        [] { UndergraduateStudent invalid("U102", "Anna", "White", 1, "", 10); },
        "Reject empty specialization"
    );
}

// Test GraduateStudent class
void testGraduateStudent()
{
    std::cout << "\n========== GRADUATE STUDENT TESTS ==========\n";

    GraduateStudent student(
        "G101", "David", "Black", 1,
        "Artificial Intelligence",
        "Machine Learning Research",
        "Professor Smith"
    );

    check(student.getResearchArea() == "Artificial Intelligence", "Graduate research area");
    check(student.getThesisTitle() == "Machine Learning Research", "Graduate thesis title");
    check(student.getResearchProgress() == 0, "Graduate initial research progress");
    check(!student.isThesisSubmitted(), "Thesis initially not submitted");

    student.updateResearchProgress(50);

    check(student.getResearchProgress() == 50, "Update research progress");

    student.changeThesisTitle("Updated Research");

    check(student.getThesisTitle() == "Updated Research", "Change thesis title");

    checkThrows<std::invalid_argument>(
        [&student] { student.updateResearchProgress(101); },
        "Reject research progress above 100"
    );

    checkThrows<std::logic_error>(
        [&student] { student.submitThesis(); },
        "Reject thesis submission before completion"
    );

    student.updateResearchProgress(100);
    student.submitThesis();

    check(student.isThesisSubmitted(), "Submit completed thesis");

    checkThrows<std::logic_error>(
        [&student] { student.changeThesisTitle("Another Title"); },
        "Prevent changing submitted thesis"
    );

    checkThrows<std::logic_error>(
        [&student] { student.updateResearchProgress(90); },
        "Prevent updating submitted thesis"
    );

    checkThrows<std::invalid_argument>(
        [] {
            GraduateStudent invalid(
                "G102", "John", "Doe", 1,
                "", "Thesis", "Supervisor"
            );
        },
        "Reject empty graduate research information"
    );
}

// Test Academic class
void testAcademic()
{
    std::cout << "\n========== ACADEMIC TESTS ==========\n";

    Academic academic("2026-2027");

    check(academic.getAcademicYear() == "2026-2027", "Academic year");

    academic.setAcademicYear("2027-2028");

    check(academic.getAcademicYear() == "2027-2028", "Update academic year");

    academic.addDepartment("Computer Science");
    academic.addDepartment("Mathematics");

    check(academic.getDepartmentCount() == 2, "Add academic departments");

    academic.addDepartment("Computer Science");

    check(academic.getDepartmentCount() == 2, "Prevent duplicate departments");

    check(academic.removeDepartment("Mathematics"), "Remove existing department");
    check(!academic.removeDepartment("Physics"), "Return false for missing department");

    checkThrows<std::invalid_argument>(
        [&academic] { academic.addDepartment(""); },
        "Reject empty department"
    );

    checkThrows<std::invalid_argument>(
        [&academic] { academic.setAcademicYear(""); },
        "Reject empty academic year"
    );
}

// Test Course class
void testCourse()
{
    std::cout << "\n========== COURSE TESTS ==========\n";

    Course course("CS101", "Programming", "Introduction to C++", 5);

    check(course.getCode() == "CS101", "Course code");
    check(course.getName() == "Programming", "Course name");
    check(course.getDescription() == "Introduction to C++", "Course description");
    check(course.getCredits() == 5, "Course credits");

    course.setName("Advanced Programming");
    course.setDescription("Advanced C++ topics");
    course.setCredits(6);

    check(course.getName() == "Advanced Programming", "Update course name");
    check(course.getDescription() == "Advanced C++ topics", "Update course description");
    check(course.getCredits() == 6, "Update course credits");

    checkThrows<std::invalid_argument>(
        [] { Course invalid("", "Programming", "Description", 5); },
        "Reject empty course code"
    );

    checkThrows<std::invalid_argument>(
        [] { Course invalid("CS102", "Programming", "Description", 0); },
        "Reject invalid course credits"
    );

    checkThrows<std::invalid_argument>(
        [&course] { course.setName(""); },
        "Reject empty updated course name"
    );
}

// Test Grade class
void testGrade()
{
    std::cout << "\n========== GRADE TESTS ==========\n";

    Grade grade("S101", "CS101", 95);

    check(grade.getStudentId() == "S101", "Grade student ID");
    check(grade.getSubjectCode() == "CS101", "Grade subject code");
    check(grade.getLetterGrade() == "A", "Calculate A grade");
    check(grade.isPassing(), "A grade is passing");

    grade.setScore(85);
    check(grade.getLetterGrade() == "B", "Calculate B grade");

    grade.setScore(75);
    check(grade.getLetterGrade() == "C", "Calculate C grade");

    grade.setScore(65);
    check(grade.getLetterGrade() == "D", "Calculate D grade");

    grade.setScore(50);
    check(grade.getLetterGrade() == "F", "Calculate F grade");
    check(!grade.isPassing(), "Failing grade is not passing");

    checkThrows<std::invalid_argument>(
        [] { Grade invalid("S101", "CS101", 101); },
        "Reject grade above 100"
    );

    checkThrows<std::invalid_argument>(
        [&grade] { grade.setScore(-1); },
        "Reject negative updated grade"
    );
}

// Test GradeBook class
void testGradeBook()
{
    std::cout << "\n========== GRADEBOOK TESTS ==========\n";

    GradeBook book("GB101", "S101");

    check(book.getGradeCount() == 0, "GradeBook initially empty");

    book.addGrade("A");
    book.addGrade("B");

    check(book.getGradeCount() == 2, "Add grades to GradeBook");
    check(book.containsGrade("A"), "Find existing grade");
    check(!book.containsGrade("C"), "Do not find missing grade");

    book.removeGrade("A");

    check(book.getGradeCount() == 1, "Remove grade from GradeBook");
    check(!book.containsGrade("A"), "Removed grade no longer exists");

    checkThrows<std::invalid_argument>(
        [&book] { book.addGrade(""); },
        "Reject empty grade record"
    );

    checkThrows<std::invalid_argument>(
        [&book] { book.removeGrade("Missing"); },
        "Reject removal of missing grade"
    );

    book.clearGrades();

    check(book.getGradeCount() == 0, "Clear all GradeBook records");

    checkThrows<std::invalid_argument>(
        [] { GradeBook invalid("", "S101"); },
        "Reject empty GradeBook ID"
    );
}

// Test Subject class
void testSubject()
{
    std::cout << "\n========== SUBJECT TESTS ==========\n";

    Subject subject("Mathematics", "Calculus", 5);

    check(subject.getName() == "Mathematics", "Subject name");
    check(subject.getDescription() == "Calculus", "Subject description");
    check(subject.getCredits() == 5, "Subject credits");

    subject.setName("Advanced Mathematics");
    subject.setDescription("Advanced calculus");
    subject.setCredits(6);

    check(subject.getName() == "Advanced Mathematics", "Update subject name");
    check(subject.getDescription() == "Advanced calculus", "Update subject description");
    check(subject.getCredits() == 6, "Update subject credits");

    checkThrows<std::invalid_argument>(
        [&subject] { subject.setName(""); },
        "Reject empty subject name"
    );

    checkThrows<std::invalid_argument>(
        [&subject] { subject.setCredits(0); },
        "Reject invalid subject credits"
    );
}

// Test additional branches across Lab 2 classes
void testMoreBranches()
{
    std::cout << "\n========== ADDITIONAL BRANCH TESTS ==========\n";

    // GraduateStudent validation and submission rules
    GraduateStudent grad("GX", "Marie", "Curie", 2,
                         "Physics", "Thesis", "Dr X");

    throws([&] { grad.updateResearchProgress(-1); },
           "GraduateStudent rejects negative progress");

    throws([&] { grad.updateResearchProgress(101); },
           "GraduateStudent rejects progress above 100");

    throws([&] { grad.submitThesis(); },
           "GraduateStudent cannot submit incomplete thesis");

    throws([&] { grad.changeThesisTitle(""); },
           "GraduateStudent rejects empty thesis title");

    grad.updateResearchProgress(100);
    grad.submitThesis();

    throws([&] { grad.updateResearchProgress(90); },
           "GraduateStudent cannot update submitted research");

    throws([&] { grad.changeThesisTitle("Another thesis"); },
           "GraduateStudent cannot change submitted thesis");


    // InternationalStudent validation
    throws([] {
        InternationalStudent x("I", "A", "B", 1, "", "P",
                               "2027", "French", 3);
    }, "InternationalStudent rejects empty country");

    throws([] {
        InternationalStudent x("I", "A", "B", 1, "France", "P",
                               "2027", "French", 0);
    }, "InternationalStudent rejects invalid proficiency");

    InternationalStudent intl("IX", "A", "B", 1, "France", "P",
                              "2027", "French", 3);

    throws([&] { intl.renewVisa(""); },
           "InternationalStudent rejects empty visa date");

    throws([&] { intl.updateLanguageProficiency(6); },
           "InternationalStudent rejects proficiency above 5");

    throws([&] { intl.updateNativeLanguage(""); },
           "InternationalStudent rejects empty language");


    // InfrastructureBuilding validation and association
    Address address1("ADDR1", "Street", "City", "1000", "Country");
    Address address2("ADDR2", "Road", "City", "2000", "Country");

    InfrastructureBuilding ib("IBX", "Main", "ADDR1", 3);
check(ib.getAddressId() == address1.getAddressId(),
      "InfrastructureBuilding stores the correct address");

check(ib.getAddressId() != address2.getAddressId(),
      "InfrastructureBuilding rejects a different address");

    throws([&] { ib.updateBuildingName(""); },
           "InfrastructureBuilding rejects empty name");

    throws([&] { ib.updateNumberOfFloors(0); },
           "InfrastructureBuilding rejects zero floors");

    throws([] {
        InfrastructureBuilding x("", "Main", "A1", 2);
    }, "InfrastructureBuilding rejects empty ID");


    // ContactInfo validation
    ContactInfo contact("CX", "123", "a@example.com");

    check(contact.getContactId() == "CX",
          "ContactInfo ID getter");

    throws([&] { contact.updatePhoneNumber(""); },
           "ContactInfo rejects empty phone");

    throws([&] { contact.updateEmail(""); },
           "ContactInfo rejects empty email");

    throws([] {
        ContactInfo x("", "123", "a@example.com");
    }, "ContactInfo rejects empty ID");


    // Infrastructure removal and update validation
    Infrastructure infrastructure("IX", "Campus", "North");

    throws([&] { infrastructure.removeBuilding(); },
           "Infrastructure rejects removing absent building");

    throws([&] { infrastructure.removeRoom(); },
           "Infrastructure rejects removing absent room");

    throws([&] { infrastructure.updateLocation(""); },
           "Infrastructure rejects empty location");


    // LibraryCard error paths
    LibraryCard card("CARDX", "STUDENTX", "");

    throws([&] { card.borrowBook(""); },
           "LibraryCard rejects empty book ID");

    card.borrowBook("BOOK1");

    throws([&] { card.borrowBook("BOOK2"); },
           "LibraryCard rejects borrowing a second book");

    card.returnBook();

    throws([&] { card.returnBook(); },
           "LibraryCard rejects returning without a borrowed book");

    throws([] {
        LibraryCard x("", "STUDENTX", "");
    }, "LibraryCard rejects empty card ID");


    // Transport validation
    Transport transport("TX", "Bus", "Route1", 40, 2.5);

    throws([&] { transport.hasAvailableSeats(-1); },
           "Transport rejects negative passenger count");

    throws([&] { transport.updateFare(-1); },
           "Transport rejects negative fare");

    throws([] {
        Transport x("T", "Bus", "R", 0, 2.0);
    }, "Transport rejects zero capacity");

    throws([] {
        Transport x("T", "Bus", "R", 10, -1.0);
    }, "Transport rejects negative initial fare");


    // Room capacity boundary
    Building building(50, "Building", "Street");
    Schedule schedule(50);
    Room room(501, 20, &building, &schedule);

    check(!room.hasCapacity(-1),
          "Room rejects negative student count");

    check(room.hasCapacity(20),
          "Room accepts exact capacity");


    // Contract state transitions and validation
    Contract contract("CX", "SX", 500, "2026-01-01");

    throws([&] { contract.updateAmount(-10); },
           "Contract rejects negative amount");

    contract.signContract();

    throws([&] { contract.signContract(); },
           "Contract rejects signing twice");

    throws([&] { contract.updateAmount(600); },
           "Contract rejects updating signed contract");

    contract.cancelContract();

    throws([&] { contract.cancelContract(); },
           "Contract rejects cancelling twice");


    // Finance validation
    Finance finance("FX", 1000);

    throws([&] { finance.recordPayment(-1); },
           "Finance rejects negative payment");

    throws([&] { finance.recordScholarship(-1); },
           "Finance rejects negative scholarship");


    // DeaneryService duplicate and missing-record paths
    DeaneryService service("Test Service");

    throws([] { DeaneryService x(""); },
           "DeaneryService rejects empty name");

    service.registerStudent("S1");

    throws([&] { service.registerStudent("S1"); },
           "DeaneryService rejects duplicate student");

    throws([&] { service.removeStudent("missing"); },
           "DeaneryService rejects missing student");

    service.registerTeacher("T1");

    throws([&] { service.registerTeacher("T1"); },
           "DeaneryService rejects duplicate teacher");

    throws([&] { service.removeTeacher("missing"); },
           "DeaneryService rejects missing teacher");

    service.registerGroup("G1");

    throws([&] { service.registerGroup("G1"); },
           "DeaneryService rejects duplicate group");

    throws([&] { service.removeGroup("missing"); },
           "DeaneryService rejects missing group");

    service.registerOrder("O1");

    throws([&] { service.registerOrder("O1"); },
           "DeaneryService rejects duplicate order");

    throws([&] { service.removeOrder("missing"); },
           "DeaneryService rejects missing order");
}

void testDepartmentHead()
{
    std::cout << "\n========== DEPARTMENT HEAD TESTS ==========\n";

    DepartmentHead head("DH1", "Bob", "Jones", "CS", "Programming", 5000.0, 3, 10, "A101");

    check(head.getTeacherId() == "DH1", "DepartmentHead ID");
    check(head.getDepartment() == "CS", "DepartmentHead department");
    check(head.getYearsAsHead() == 3, "DepartmentHead years");
    check(head.getTeachersSupervised() == 10, "DepartmentHead teachers supervised");
    check(head.getOfficeNumber() == "A101", "DepartmentHead office");

    head.updateOfficeNumber("B202");
    check(head.getOfficeNumber() == "B202", "Update DepartmentHead office");

    std::ostringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    head.displayDepartmentHeadInformation();
    std::cout.rdbuf(originalBuffer);
    check(!output.str().empty(), "DepartmentHead display");
}

void testHeadOfDepartment()
{
    std::cout << "\n========== HEAD OF DEPARTMENT TESTS ==========\n";

    HeadOfDepartment head("H1", "D1", "T1");

    check(head.getHeadId() == "H1", "HeadOfDepartment ID");
    check(head.getDepartmentId() == "D1", "HeadOfDepartment department");
    check(head.getTeacherId() == "T1", "HeadOfDepartment teacher");

    std::ostringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    head.displayInformation();
    std::cout.rdbuf(originalBuffer);
    check(!output.str().empty(), "HeadOfDepartment display");
}

void testLabAssistant()
{
    std::cout << "\n========== LAB ASSISTANT TESTS ==========\n";

    LabAssistant assistant("LA1", "T1", "Room101");

    check(assistant.getAssistantId() == "LA1", "LabAssistant ID");
    check(assistant.getTeacherId() == "T1", "LabAssistant teacher");
    check(assistant.getAssignedRoom() == "Room101", "LabAssistant room");

    std::ostringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    assistant.displayInformation();
    std::cout.rdbuf(originalBuffer);
    check(!output.str().empty(), "LabAssistant display");
}

void testDormRoom()
{
    std::cout << "\n========== DORM ROOM TESTS ==========\n";
    DormRoom room("R101", "D1", 101, 2);
    check(room.getRoomId() == "R101", "DormRoom ID");
    check(room.getDormitoryId() == "D1", "DormRoom dormitory ID");
    check(room.getRoomNumber() == 101, "DormRoom number");
    check(room.getCapacity() == 2, "DormRoom capacity");
    check(!room.isFull(0), "DormRoom not full 0");
    check(!room.isFull(1), "DormRoom not full 1");
    check(room.isFull(2), "DormRoom full 2");
    check(room.isFull(3), "DormRoom full 3");
    room.updateCapacity(4);
    check(room.getCapacity() == 4, "Update DormRoom capacity");
}

void testDormitory()
{
    std::cout << "\n========== DORMITORY TESTS ==========\n";
    Dormitory dorm("D1", "North Hall", "North Campus", 50);
    check(dorm.getDormitoryId() == "D1", "Dormitory ID");
    check(dorm.getDormitoryName() == "North Hall", "Dormitory name");
    check(dorm.getTotalRooms() == 50, "Dormitory total rooms");
    check(dorm.hasAvailableRooms(), "Dormitory has rooms");
    dorm.updateAddress("South Campus");
    dorm.updateTotalRooms(60);
    check(dorm.getTotalRooms() == 60, "Update dormitory rooms");
    dorm.updateTotalRooms(0);
    check(!dorm.hasAvailableRooms(), "Dormitory no rooms at 0");
}

void testCafeteria()
{
    std::cout << "\n========== CAFETERIA TESTS ==========\n";
    Cafeteria cafe("C1", "Main Cafe", "Building A", 100);
    check(cafe.getCafeteriaId() == "C1", "Cafeteria ID");
    check(cafe.getCafeteriaName() == "Main Cafe", "Cafeteria name");
    check(cafe.getLocation() == "Building A", "Cafeteria location");
    check(cafe.getSeatingCapacity() == 100, "Cafeteria capacity");
    check(cafe.hasAvailableSeats(50), "Cafeteria seats 50");
    check(!cafe.hasAvailableSeats(100), "Cafeteria no seats at exact capacity");
    check(!cafe.hasAvailableSeats(101), "Cafeteria no seats 101");
    cafe.updateSeatingCapacity(120);
    check(cafe.getSeatingCapacity() == 120, "Update cafeteria capacity");
}

void testMeal()
{
    std::cout << "\n========== MEAL TESTS ==========\n";
    Meal meal("M1", "Lunch", "C1", 12.5, "Lunch");
    check(meal.isAffordable(20.0), "Meal affordable 20");
    check(meal.isAffordable(12.5), "Meal affordable exact");
    check(!meal.isAffordable(10.0), "Meal not affordable 10");
    meal.updatePrice(15.0);
    check(meal.isAffordable(20.0), "Updated meal affordable 20");
    check(!meal.isAffordable(14.0), "Updated meal not affordable 14");
}
void testRoute()
{
    std::cout << "\n========== ROUTE TESTS ==========\n";
    Route route("RT1", "Campus", "Downtown", 10.0, 30);
    check(route.getAverageSpeed() > 0.0, "Route positive speed");
    route.updateDuration(60);
    double speed = route.getAverageSpeed();
    check(speed > 9.0 && speed < 11.0, "Updated route speed");
    checkThrows<std::invalid_argument>(
        [&route] { route.updateDuration(0); },
        "Route rejects zero duration"
    );
    checkThrows<std::invalid_argument>(
        [&route] { route.updateDuration(-5); },
        "Route rejects negative duration"
    );
}
void testBook()
{
    std::cout << "\n========== BOOK TESTS ==========\n";
    Book book("B1", "C++ Primer", "L1", "CS101");
    check(book.belongsToSubject("CS101"), "Book belongs CS101");
    check(!book.belongsToSubject("MATH101"), "Book not in MATH101");
    book.updateTitle("C++ Primer 5th");
    check(book.belongsToSubject("CS101"), "Updated book belongs CS101");
}

void testLibrary()
{
    std::cout << "\n========== LIBRARY TESTS ==========\n";
    Library library("L1", "Main Library", "Campus", 1000);
    check(library.hasBooksAvailable(), "Library has books");
    library.updateTotalBooks(0);
    check(!library.hasBooksAvailable(), "Library empty");
    library.updateTotalBooks(500);
    check(library.hasBooksAvailable(), "Library updated has books");
}

void testLibraryBook()
{
    std::cout << "\n========== LIBRARY BOOK TESTS ==========\n";
    LibraryBook libBook("B1", "Title", "Author", "L1");
    libBook.setAvailability(false);
    check(!libBook.isAvailable(), "LibraryBook unavailable");
    libBook.setAvailability(true);
    check(libBook.isAvailable(), "LibraryBook available");
}

void testDepartment()
{
    std::cout << "\n========== DEPARTMENT TESTS ==========\n";
    Department dept("D1", "Computer Science", "CS dept");
    check(dept.getId() == "D1", "Department ID");
    check(dept.getName() == "Computer Science", "Department name");
    check(dept.getDescription() == "CS dept", "Department description");
    check(dept.getCourseCount() == 0, "Department empty");
    dept.setName("Computing");
    check(dept.getName() == "Computing", "Update dept name");
    dept.setDescription("Computing dept");
    check(dept.getDescription() == "Computing dept", "Update dept desc");
    dept.addCourse("CS101");
    check(dept.getCourseCount() == 1, "Add course");
    check(dept.hasCourse("CS101"), "Has course");
    dept.addCourse("CS102");
    check(dept.getCourseCount() == 2, "Add 2nd course");
    check(dept.removeCourse("CS101"), "Remove course");
    check(!dept.removeCourse("MISSING"), "Remove missing false");
    check(!dept.hasCourse("CS101"), "Removed absent");
}

void testSemester()
{
    std::cout << "\n========== SEMESTER TESTS ==========\n";
    Semester sem("S1", "Fall 2026", "2026-09-01", "2026-12-20");
    check(sem.getId() == "S1", "Semester ID");
    check(sem.getName() == "Fall 2026", "Semester name");
    check(sem.getStartDate() == "2026-09-01", "Semester start");
    check(sem.getEndDate() == "2026-12-20", "Semester end");
    sem.setName("Autumn 2026");
    check(sem.getName() == "Autumn 2026", "Update semester name");
    sem.setDates("2026-09-15", "2026-12-25");
    check(sem.getStartDate() == "2026-09-15", "Update semester start");
    check(sem.getEndDate() == "2026-12-25", "Update semester end");
    sem.activate();
    check(sem.isActive(), "Activate semester");
    sem.deactivate();
    check(!sem.isActive(), "Deactivate semester");
}

void testTimetable()
{
    std::cout << "\n========== TIMETABLE TESTS ==========\n";
    Timetable tt("CS101", "Monday", "10:00", "12:00", "R101");
    check(tt.getSubject() == "CS101", "Timetable subject");
    check(tt.getDay() == "Monday", "Timetable day");
    check(tt.getStartTime() == "10:00", "Timetable start");
    check(tt.getEndTime() == "12:00", "Timetable end");
    check(tt.getRoom() == "R101", "Timetable room");
    tt.setSubject("CS102");
    check(tt.getSubject() == "CS102", "Update subject");
    tt.setDay("Tuesday");
    check(tt.getDay() == "Tuesday", "Update day");
    tt.setTime("14:00", "16:00");
    check(tt.getStartTime() == "14:00", "Update start");
    check(tt.getEndTime() == "16:00", "Update end");
    tt.setRoom("R202");
    check(tt.getRoom() == "R202", "Update room");
}

void testFaculty()
{
    std::cout << "\n========== FACULTY TESTS ==========\n";
    Faculty faculty("F1", "Engineering");
    check(faculty.getId() == "F1", "Faculty ID");
    check(faculty.getName() == "Engineering", "Faculty name");
    check(faculty.getDepartmentCount() == 0, "Faculty empty");
    faculty.setName("Engineering & Science");
    check(faculty.getName() == "Engineering & Science", "Update faculty name");
    faculty.addDepartment("CS");
    check(faculty.getDepartmentCount() == 1, "Add department");
    check(faculty.hasDepartment("CS"), "Has department");
    faculty.addDepartment("Math");
    check(faculty.getDepartmentCount() == 2, "Add 2nd dept");
    check(faculty.removeDepartment("CS"), "Remove dept");
    check(!faculty.removeDepartment("Missing"), "Remove missing false");
    check(!faculty.hasDepartment("CS"), "Removed absent");
}

void testLecturer()
{
    std::cout << "\n========== LECTURER TESTS ==========\n";
    Lecturer lecturer("L1", "John", "Doe", "CS", "Programming", 4000.0, 20, 3, "Senior");
    check(lecturer.getTeacherId() == "L1", "Lecturer ID");
    check(lecturer.getDepartment() == "CS", "Lecturer dept");
    check(lecturer.getWeeklyTeachingHours() == 20, "Lecturer hours");
    check(lecturer.getCoursesAssigned() == 3, "Lecturer courses");
    check(lecturer.getTeachingLevel() == "Senior", "Lecturer level");
    lecturer.assignCourse();
    check(lecturer.getCoursesAssigned() == 4, "Assign course");
    lecturer.updateTeachingHours(25);
    check(lecturer.getWeeklyTeachingHours() == 25, "Update hours");
    std::ostringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    lecturer.displayLecturerInformation();
    std::cout.rdbuf(originalBuffer);
    check(!output.str().empty(), "Display lecturer");
}

void testExamSheet()
{
    std::cout << "\n========== EXAMSHEET TESTS ==========\n";
    ExamSheet sheet("ES1", "E1", "T1");
    check(sheet.getStudentCount() == 0, "ExamSheet empty");
    check(!sheet.containsStudent("S1"), "ExamSheet no S1");
    sheet.addStudent("S1");
    check(sheet.getStudentCount() == 1, "Add student");
    check(sheet.containsStudent("S1"), "Contains S1");
    sheet.addStudent("S2");
    check(sheet.getStudentCount() == 2, "Add 2nd student");
    sheet.removeStudent("S1");
    check(sheet.getStudentCount() == 1, "Remove student");
    check(!sheet.containsStudent("S1"), "Removed absent");
}
void testPayment()
{
    std::cout << "\n========== PAYMENT TESTS ==========\n";
    Payment payment("P1", "C1", "S1", 500.0);
    check(payment.getPaymentId() == "P1", "Payment ID");
    check(payment.getContractId() == "C1", "Payment contract");
    check(payment.getStudentId() == "S1", "Payment student");
    check(payment.getAmount() == 500.0, "Payment amount");
    check(payment.isValid(), "Payment valid");
    payment.updateAmount(750.0);
    check(payment.getAmount() == 750.0, "Update amount");
    checkThrows<std::invalid_argument>(
        [&payment] { payment.updateAmount(-100.0); },
        "Payment rejects negative amount"
    );
    std::string receipt = payment.generateReceipt();
    check(!receipt.empty(), "Payment receipt");
}

void testScholarship()
{
    std::cout << "\n========== SCHOLARSHIP TESTS ==========\n";

    Scholarship scholarship("SCH1", "S1", 1000.0, "2026-2027");
    check(scholarship.getScholarshipId() == "SCH1", "Scholarship ID");
    check(scholarship.getAmount() == 1000.0, "Scholarship amount");
    check(scholarship.isValid(), "Scholarship valid");

    checkThrows<std::invalid_argument>(
        [] { Scholarship invalid("SCH2", "S2", -100.0, "2026-2027"); },
        "Scholarship rejects negative amount"
    );
    checkThrows<std::invalid_argument>(
        [] { Scholarship zero("SCH3", "S3", 0.0, "2026-2027"); },
        "Scholarship rejects zero amount"
    );
}


void testScholarshipManagerFinance()
{
    std::cout << "\n========== SCHOLARSHIP MANAGER TESTS ==========\n";
    ScholarshipManager manager("M1", 5000.0);
    check(manager.getManagerId() == "M1", "Manager ID");
    check(manager.getMaximumScholarship() == 5000.0, "Manager max");
    check(manager.getScholarshipCount() == 0, "Manager empty");
    manager.addScholarship(Scholarship("SCH1", "S1", 1000.0, "2026-2027"));
    manager.addScholarship(Scholarship("SCH2", "S2", 1500.0, "2026-2027"));
    check(manager.getScholarshipCount() == 2, "Manager added");
    check(manager.calculateTotalScholarships() == 2500.0, "Manager total");
    Scholarship* found = manager.findScholarship("SCH1");
    check(found != nullptr, "Manager found");
    check(found != nullptr && found->getScholarshipId() == "SCH1", "Found ID matches");
    check(manager.findScholarship("MISSING") == nullptr, "Manager null missing");
    check(manager.removeScholarship("SCH1"), "Manager remove");
    check(manager.getScholarshipCount() == 1, "Manager count after remove");
    check(!manager.removeScholarship("MISSING"), "Manager remove missing false");
}

void testNotification()
{
    std::cout << "\n========== NOTIFICATION TESTS ==========\n";
    Notification notif("N1", "S1", "Hello");
    check(notif.getMessage() == "Hello", "Notification message");
    notif.updateMessage("World");
    check(notif.getMessage() == "World", "Update message");
}

void testNotificationService()
{
    std::cout << "\n========== NOTIFICATION SERVICE TESTS ==========\n";
    NotificationService service("TestService");
    check(service.getNotificationsSent() == 0, "Service zero");
    service.notifyStudent("S1", "Hello");
    check(service.getNotificationsSent() == 1, "Service notify student");
    service.notifyTeacher("T1", "Hello");
    check(service.getNotificationsSent() == 2, "Service notify teacher");
    service.resetCounter();
    check(service.getNotificationsSent() == 0, "Service reset");
}

void testCurator()
{
    std::cout << "\n========== CURATOR TESTS ==========\n";
    Curator curator("C1", "GroupA");
    check(curator.getCuratorId() == "C1", "Curator ID");
    check(curator.getGroupId() == "GroupA", "Curator group");
    std::ostringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    curator.displayInformation();
    std::cout.rdbuf(originalBuffer);
    check(!output.str().empty(), "Curator display");
}

// ============================================================
// FINAL COVERAGE PUSH — services, administration, finance, infra
// ============================================================

void testScholarshipAwardService()
{
    std::cout << "\n========== SCHOLARSHIP AWARD SERVICE TESTS ==========\n";

    ScholarshipAwardService svc(5000.0);

    check(svc.getMaximumScholarship() == 5000.0, "Award service max");
    check(svc.getScholarshipsAwarded() == 0, "Award service zero awarded");
    check(!svc.hasScholarship("SCH1"), "Award service no SCH1 yet");

    svc.awardScholarship("SCH1");
    check(svc.getScholarshipsAwarded() == 1, "Award service award SCH1");
    check(svc.hasScholarship("SCH1"), "Award service has SCH1");

    svc.awardScholarship("SCH2");
    check(svc.getScholarshipsAwarded() == 2, "Award service award SCH2");

    svc.revokeScholarship("SCH1");
    check(!svc.hasScholarship("SCH1"), "Award service revoke SCH1");
    check(svc.getScholarshipsAwarded() == 1, "Award service count after revoke");

    checkThrows<std::invalid_argument>(
        [&svc] { svc.revokeScholarship("MISSING"); },
        "Award service rejects revoking missing"
    );
}

void testApplication()
{
    std::cout << "\n========== APPLICATION TESTS ==========\n";

    Student student("S1", "John", "Doe", 2);
    DeaneryService service("TestService");
    Order order(1, &student, &service, "draft");

    Application app(1, &student, &order, "pending");

    check(app.getApplicationId() == 1, "Application ID");
    check(app.getStatus() == "pending", "Application status");

    app.setStatus("approved");
    check(app.getStatus() == "approved", "Application update status");
}

void testOrder()
{
    std::cout << "\n========== ORDER TESTS ==========\n";

    Student student("S1", "John", "Doe", 2);
    DeaneryService service("TestService");

    Order order(1, &student, &service, "draft");

    check(order.getOrderId() == 1, "Order ID");
    check(order.getStatus() == "draft", "Order status");

    order.setStatus("issued");
    check(order.getStatus() == "issued", "Order update status");
}

void testFinance()
{
    std::cout << "\n========== FINANCE TESTS ==========\n";

    Finance finance("F1", 10000.0);

    check(finance.getFinanceId() == "F1", "Finance ID");
    check(finance.getAnnualBudget() == 10000.0, "Finance budget");
    check(finance.getTotalPayments() == 0.0, "Finance zero payments");
    check(finance.getTotalScholarships() == 0.0, "Finance zero scholarships");
    check(finance.getRemainingBudget() == 10000.0, "Finance remaining full");

    finance.recordPayment(1500.0);
    check(finance.getTotalPayments() == 1500.0, "Finance record payment");
    check(finance.getRemainingBudget() == 8500.0, "Finance remaining after payment");

    finance.recordScholarship(500.0);
    check(finance.getTotalScholarships() == 500.0, "Finance record scholarship");
    check(finance.getRemainingBudget() == 8000.0, "Finance remaining after scholarship");

    checkThrows<std::invalid_argument>(
        [&finance] { finance.recordPayment(-1.0); },
        "Finance rejects negative payment"
    );
    checkThrows<std::invalid_argument>(
        [&finance] { finance.recordScholarship(-1.0); },
        "Finance rejects negative scholarship"
    );
}

void testInfrastructureCoverage()
{
    std::cout << "\n========== INFRASTRUCTURE TESTS ==========\n";

    Infrastructure infra("I1", "Main Campus", "North");

    check(infra.getInfrastructureId() == "I1", "Infrastructure ID");
    check(infra.getInfrastructureName() == "Main Campus", "Infrastructure name");
    check(infra.getLocation() == "North", "Infrastructure location");
    check(infra.getTotalBuildings() == 0, "Infrastructure zero buildings");
    check(infra.getTotalRooms() == 0, "Infrastructure zero rooms");

    checkThrows<std::logic_error>(
        [&infra] { infra.removeBuilding(); },
        "Infrastructure rejects removing building when empty"
    );
    checkThrows<std::logic_error>(
        [&infra] { infra.removeRoom(); },
        "Infrastructure rejects removing room when empty"
    );

    infra.addBuilding();
    check(infra.getTotalBuildings() == 1, "Infrastructure add building");

    infra.addBuilding();
    check(infra.getTotalBuildings() == 2, "Infrastructure add 2nd building");

    infra.addRoom();
    infra.addRoom();
    infra.addRoom();
    check(infra.getTotalRooms() == 3, "Infrastructure add 3 rooms");

    infra.removeBuilding();
    check(infra.getTotalBuildings() == 1, "Infrastructure remove building");

    infra.removeRoom();
    check(infra.getTotalRooms() == 2, "Infrastructure remove room");

    infra.updateLocation("South");
    check(infra.getLocation() == "South", "Infrastructure update location");

    infra.removeBuilding();
    check(infra.getTotalBuildings() == 0, "Infrastructure remove last building");

    checkThrows<std::logic_error>(
        [&infra] { infra.removeBuilding(); },
        "Infrastructure rejects remove when already empty"
    );
}

void testInternationalStudentFull()
{
    std::cout << "\n========== INTERNATIONAL STUDENT FULL TESTS ==========\n";

    InternationalStudent s("I1", "Anna", "Lee", 2, "France", "P123",
                           "2027-01-01", "French", 4);

    check(s.getHomeCountry() == "France", "Intl home country");
    check(s.getPassportNumber() == "P123", "Intl passport");
    check(s.getVisaExpiryDate() == "2027-01-01", "Intl visa expiry");

    s.renewVisa("2028-01-01");
    check(s.getVisaExpiryDate() == "2028-01-01", "Intl renew visa");

    s.updateLanguageProficiency(5);
    s.updateNativeLanguage("German");

    check(s.isVisaValid(), "Intl visa valid");

    std::ostringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    s.displayInformation();
    std::cout.rdbuf(originalBuffer);
    check(!output.str().empty(), "Intl display information");
}

// ============================================================
// COVERAGE PUSH TO 90% — remaining gaps
// ============================================================

void testAdministrationBuilding()
{
    std::cout << "\n========== ADMIN BUILDING TESTS ==========\n";

    Building bld(1, "Main Hall", "123 Street");

    check(bld.getName() == "Main Hall", "Admin Building name");
    check(bld.getRoomCount() == 0, "Admin Building initially empty");

    // Room needs Building* and Schedule*, so create both
    Schedule sched(10);
    Room r1(101, 30, &bld, &sched);
    bld.addRoom(&r1);
    check(bld.getRoomCount() == 1, "Admin Building add room");

    Room r2(102, 25, &bld, &sched);
    bld.addRoom(&r2);
    check(bld.getRoomCount() == 2, "Admin Building add 2nd room");
}

void testAdministrationSchedule()
{
    std::cout << "\n========== ADMIN SCHEDULE TESTS ==========\n";

    Schedule sched(10);

    check(sched.getScheduleId() == 10, "Schedule ID");
    check(sched.getRoomCount() == 0, "Schedule initially empty");

    Building bld(1, "Main Hall", "123 Street");
    Room r1(101, 30, &bld, &sched);
    sched.addRoom(&r1);
    check(sched.getRoomCount() == 1, "Schedule add room");

    Room r2(102, 25, &bld, &sched);
    sched.addRoom(&r2);
    check(sched.getRoomCount() == 2, "Schedule add 2nd room");
}

void testAdministrationRoomFull()
{
    std::cout << "\n========== ADMIN ROOM FULL TESTS ==========\n";

    Building bld(1, "Main Hall", "123 Street");
    Schedule sched(10);
    Room room(101, 30, &bld, &sched);

    check(room.getRoomNumber() == 101, "Admin Room number");
    check(room.getCapacity() == 30, "Admin Room capacity");

    check(room.hasCapacity(0), "Admin Room capacity 0");
    check(room.hasCapacity(15), "Admin Room capacity 15");
    check(room.hasCapacity(29), "Admin Room capacity 29");
    check(room.hasCapacity(30), "Admin Room capacity 30 exact");
    check(!room.hasCapacity(31), "Admin Room no capacity 31");
    check(!room.hasCapacity(-1), "Admin Room rejects negative");
}
void testDormRoomFull()
{
    std::cout << "\n========== DORM ROOM FULL TESTS ==========\n";

    DormRoom room("R101", "D1", 101, 2);

    check(room.getRoomId() == "R101", "DormRoom ID");
    check(room.getDormitoryId() == "D1", "DormRoom dorm ID");
    check(room.getRoomNumber() == 101, "DormRoom number");
    check(room.getCapacity() == 2, "DormRoom capacity");

    check(!room.isFull(0), "DormRoom 0 residents");
    check(!room.isFull(1), "DormRoom 1 resident");
    check(room.isFull(2), "DormRoom 2 residents");
    check(room.isFull(3), "DormRoom 3 residents");

    room.updateCapacity(4);
    check(room.getCapacity() == 4, "DormRoom update capacity to 4");

    check(!room.isFull(3), "DormRoom 3 of 4 not full");
    check(room.isFull(4), "DormRoom 4 of 4 full");

    room.updateCapacity(1);
    check(room.getCapacity() == 1, "DormRoom shrink capacity to 1");

    // Constructor validation
    checkThrows<std::invalid_argument>(
        [] { DormRoom r("", "D1", 101, 2); },
        "DormRoom rejects empty room ID"
    );
    checkThrows<std::invalid_argument>(
        [] { DormRoom r("R1", "", 101, 2); },
        "DormRoom rejects empty dorm ID"
    );
    checkThrows<std::invalid_argument>(
        [] { DormRoom r("R1", "D1", 0, 2); },
        "DormRoom rejects zero room number"
    );
    checkThrows<std::invalid_argument>(
        [] { DormRoom r("R1", "D1", 101, 0); },
        "DormRoom rejects zero capacity"
    );

    // isFull validation
    checkThrows<std::invalid_argument>(
        [&room] { room.isFull(-1); },
        "DormRoom rejects negative residents"
    );

    // updateCapacity validation
    checkThrows<std::invalid_argument>(
        [&room] { room.updateCapacity(0); },
        "DormRoom rejects zero update capacity"
    );
    checkThrows<std::invalid_argument>(
        [&room] { room.updateCapacity(-1); },
        "DormRoom rejects negative update capacity"
    );
}

void testContactInfoFull()
{
    std::cout << "\n========== CONTACT INFO FULL TESTS ==========\n";

    ContactInfo c("C1", "123456", "test@example.com");

    check(c.getContactId() == "C1", "ContactInfo ID");
    check(c.getPhoneNumber() == "123456", "ContactInfo phone");
    check(c.getEmail() == "test@example.com", "ContactInfo email");

    c.updatePhoneNumber("999999");
    check(c.getPhoneNumber() == "999999", "ContactInfo update phone");

    c.updateEmail("new@example.com");
    check(c.getEmail() == "new@example.com", "ContactInfo update email");

    checkThrows<std::invalid_argument>(
        [] { ContactInfo x("", "123", "a@b.c"); },
        "ContactInfo rejects empty ID"
    );
    checkThrows<std::invalid_argument>(
        [] { ContactInfo x("C1", "", "a@b.c"); },
        "ContactInfo rejects empty phone"
    );
    checkThrows<std::invalid_argument>(
        [] { ContactInfo x("C1", "123", ""); },
        "ContactInfo rejects empty email"
    );
}

void testNotificationFull()
{
    std::cout << "\n========== NOTIFICATION FULL TESTS ==========\n";

    Notification notif("N1", "S1", "Hello");

    check(notif.getMessage() == "Hello", "Notification initial message");

    notif.updateMessage("World");
    check(notif.getMessage() == "World", "Notification update 1");

    notif.updateMessage("Again");
    check(notif.getMessage() == "Again", "Notification update 2");

    checkThrows<std::invalid_argument>(
        [&notif] { notif.updateMessage(""); },
        "Notification rejects empty message"
    );
}

void testNotificationServiceFull()
{
    std::cout << "\n========== NOTIFICATION SERVICE FULL TESTS ==========\n";

    NotificationService svc("TestService");

    check(svc.getNotificationsSent() == 0, "Service zero sent");

    svc.notifyStudent("S1", "Hello");
    check(svc.getNotificationsSent() == 1, "Service notify student 1");

    svc.notifyStudent("S2", "Hello2");
    check(svc.getNotificationsSent() == 2, "Service notify student 2");

    svc.notifyTeacher("T1", "HelloT");
    check(svc.getNotificationsSent() == 3, "Service notify teacher 1");

    svc.notifyTeacher("T2", "HelloT2");
    check(svc.getNotificationsSent() == 4, "Service notify teacher 2");

    svc.resetCounter();
    check(svc.getNotificationsSent() == 0, "Service reset");

    svc.notifyStudent("S3", "After reset");
    check(svc.getNotificationsSent() == 1, "Service notify after reset");
   
}

 void testMealFull()
{
    std::cout << "\n========== MEAL FULL TESTS ==========\n";

    Meal meal("M1", "Lunch", "C1", 12.5, "Lunch");

    check(meal.isAffordable(20.0), "Meal affordable 20");
    check(meal.isAffordable(12.5), "Meal affordable exact");
    check(!meal.isAffordable(10.0), "Meal not affordable 10");

    meal.updatePrice(15.0);
    check(meal.isAffordable(15.0), "Meal updated affordable exact");
    check(!meal.isAffordable(14.99), "Meal updated not affordable");

    meal.updatePrice(0.0);
    check(meal.isAffordable(0.0), "Meal zero price affordable");

    checkThrows<std::invalid_argument>(
        [&meal] { meal.updatePrice(-1.0); },
        "Meal rejects negative price"
    );
}

// Forward declarations for new tests
void testDormRoom();
void testDormitory();
void testCafeteria();
void testMeal();
void testRoute();
void testBook();
void testLibrary();
void testLibraryBook();
void testDepartment();
void testSemester();
void testTimetable();
void testFaculty();
void testLecturer();
void testExamSheet();
void testPayment();
void testScholarship();
void testScholarshipManagerFinance();
void testNotification();
void testNotificationService();
void testCurator();
void testDepartmentHead();
void testHeadOfDepartment();
void testLabAssistant();
void testScholarshipAwardService();
void testApplication();
void testOrder();
void testFinance();
void testInfrastructureCoverage();
void testInternationalStudentFull();
void testAdministrationBuilding();
void testAdministrationSchedule();
void testAdministrationRoomFull();
void testDormRoomFull();
void testMealFull();
void testNotificationFull();
void testNotificationServiceFull();
void testContactInfoFull();

int main()
{

    testAllExceptions();

    testTeacher();
    testProfessor();

    testTeacherContract();
    testTeacherEvaluation();
    testTeacherResearch();
    testTeacherSchedule();

    testStudent();
    testStudentProfile();

    testEnrollment();
    testStudentGroup();
    testTranscript();
    testUndergraduateStudent();
    testGraduateStudent();

    testAcademic();
    testCourse();
    testGrade();
    testGradeBook();
    testSubject();
    testMoreBranches();
    testInfrastructure();

    testDormRoom();
    testDormitory();
    testCafeteria();
    testMeal();
    testRoute();
    testBook();
    testLibrary();
    testLibraryBook();
    testDepartment();
    testSemester();
    testTimetable();
    testFaculty();
    testLecturer();
    testExamSheet();
    testPayment();
    testScholarship();
    testScholarshipManagerFinance();
    testNotification();
    testNotificationService();
    testCurator();
    testDepartmentHead();
    testHeadOfDepartment();
    testLabAssistant();
        testScholarshipAwardService();
    testApplication();
    testOrder();
    testFinance();
        testInfrastructureCoverage();
    testInternationalStudentFull();
        testAdministrationBuilding();
    testAdministrationSchedule();
    testAdministrationRoomFull();
    testDormRoomFull();
    testMealFull();
    testNotificationFull();
    testNotificationServiceFull();
        testContactInfoFull();

    std::cout << "\n========== TEST SUMMARY ==========\n";
    std::cout << "Passed: " << passed << std::endl;
    std::cout << "Failed: " << failed << std::endl;

    if (failed == 0)
    {
        std::cout << "\nAll tests passed successfully!\n";
        return 0;
    }

    std::cout << "\nSome tests failed!\n";
    return 1;
}
