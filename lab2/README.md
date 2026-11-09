# Lab 2 — Dean’s Office Domain Model

This C++17 project models a university deanery and its academic, student, teacher, finance, administration, infrastructure, and service workflows. The inventory below is generated from the current public headers; method names include constructors and accessors where declared.

## Requirement inventory

| Requirement | Current implementation |
|---|---:|
| Domain classes (excluding custom exceptions) | 58 (minimum 50) |
| Custom exception classes | 12 (minimum 12) |
| Declared data fields | 227 (minimum 150) |
| Substantive public behaviours (excluding constructors/getters/setters) | 150 (minimum 100) |
| Typed class associations (fields or method parameters; inheritance excluded) | 35 (minimum 30) |

The counts are based on declarations in `include/`. Association counting excludes inheritance and counts a distinct related class once per owning class.

## Class inventory

| Class | Fields | Public methods | Associations | Header |
|---|---:|---|---|---|
| `Academic` | 2 | `Academic`, `getAcademicYear`, `setAcademicYear`, `addDepartment`, `removeDepartment`, `getDepartmentCount` | `Department` | `include/academic/Academic.h` |
| `Course` | 4 | `Course`, `getCode`, `getName`, `getDescription`, `getCredits`, `setName`, `setDescription`, `setCredits`, `isInDepartment`, `coversSubject` | `Department`, `Subject` | `include/academic/Course.h` |
| `Department` | 4 | `Department`, `getId`, `getName`, `getDescription`, `setName`, `setDescription`, `addCourse`, `removeCourse`, `hasCourse`, `getCourseCount` | — | `include/academic/Department.h` |
| `Exam` | 5 | `Exam`, `getId`, `getSubjectCode`, `getDate`, `getDurationMinutes`, `getMaximumScore`, `setDate`, `setDurationMinutes` | — | `include/academic/Exam.h` |
| `ExamSheet` | 4 | `ExamSheet`, `addStudent`, `removeStudent`, `containsStudent`, `getStudentCount` | — | `include/academic/ExamSheet.h` |
| `Faculty` | 3 | `Faculty`, `getId`, `getName`, `setName`, `addDepartment`, `removeDepartment`, `hasDepartment`, `getDepartmentCount` | — | `include/academic/Faculty.h` |
| `Grade` | 4 | `Grade`, `getStudentId`, `getSubjectCode`, `getScore`, `getLetterGrade`, `setScore`, `isPassing`, `belongsToStudent` | `Student` | `include/academic/Grade.h` |
| `GradeBook` | 3 | `GradeBook`, `addGrade`, `removeGrade`, `containsGrade`, `getGradeCount`, `clearGrades` | — | `include/academic/GradeBook.h` |
| `Lecturer` | 3 | `Lecturer`, `getWeeklyTeachingHours`, `getCoursesAssigned`, `getTeachingLevel`, `assignCourse`, `updateTeachingHours`, `displayLecturerInformation` | — | `include/academic/Lecturer.h` |
| `Semester` | 5 | `Semester`, `getId`, `getName`, `getStartDate`, `getEndDate`, `isActive`, `setName`, `setDates`, `activate`, `deactivate` | — | `include/academic/Semester.h` |
| `Subject` | 3 | `Subject`, `getName`, `getDescription`, `getCredits`, `setName`, `setDescription`, `setCredits` | — | `include/academic/Subject.h` |
| `Timetable` | 5 | `Timetable`, `getSubject`, `getDay`, `getStartTime`, `getEndTime`, `getRoom`, `setSubject`, `setDay`, `setTime`, `setRoom` | — | `include/academic/Timetable.h` |
| `Application` | 4 | `Application`, `getApplicationId`, `getStatus`, `setStatus` | `Order`, `Student` | `include/administration/Application.h` |
| `Building` | 4 | `Building`, `getName`, `addRoom`, `getRoomCount` | `Room` | `include/administration/Building.h` |
| `Order` | 4 | `Order`, `getOrderId`, `getStatus`, `setStatus` | `DeaneryService`, `Student` | `include/administration/Order.h` |
| `Room` | 4 | `Room`, `getRoomNumber`, `getCapacity`, `hasCapacity` | `Building`, `Schedule` | `include/administration/Room.h` |
| `Schedule` | 2 | `Schedule`, `getScheduleId`, `addRoom`, `getRoomCount` | `Room` | `include/administration/Schedule.h` |
| `DeaneryException` | 0 | `DeaneryException` | — | `include/exceptions/DeaneryException.h` |
| `DuplicateEntityException` | 0 | — | — | `include/exceptions/DuplicateEntityException.h` |
| `GradeOutOfBoundsException` | 0 | — | — | `include/exceptions/GradeOutOfBoundsException.h` |
| `GroupNotFoundException` | 0 | — | — | `include/exceptions/GroupNotFoundException.h` |
| `InvalidDocumentException` | 0 | — | — | `include/exceptions/InvalidDocumentException.h` |
| `MissingPrerequisiteException` | 0 | — | — | `include/exceptions/MissingPrerequisiteException.h` |
| `RoomCapacityExceededException` | 0 | — | — | `include/exceptions/RoomCapacityExceededException.h` |
| `ScheduleConflictException` | 0 | — | — | `include/exceptions/ScheduleConflictException.h` |
| `ScholarshipLimitExceededException` | 0 | — | — | `include/exceptions/ScholarshipLimitExceededException.h` |
| `StudentNotFoundException` | 0 | `StudentNotFoundException` | — | `include/exceptions/StudentNotFoundException.h` |
| `TeacherNotFoundException` | 0 | — | — | `include/exceptions/TeacherNotFoundException.h` |
| `UnauthorizedAccessException` | 0 | — | — | `include/exceptions/UnauthorizedAccessException.h` |
| `Contract` | 5 | `Contract`, `getContractId`, `getStudentId`, `getTotalAmount`, `getContractDate`, `getStatus`, `updateAmount`, `signContract`, `cancelContract`, `isSigned`, `isCancelled` | — | `include/finance/Contract.h` |
| `Finance` | 4 | `Finance`, `getFinanceId`, `getAnnualBudget`, `getTotalPayments`, `getTotalScholarships`, `recordPayment`, `recordScholarship`, `getRemainingBudget` | — | `include/finance/Finance.h` |
| `Payment` | 4 | `Payment`, `getPaymentId`, `getContractId`, `getStudentId`, `getAmount`, `updateAmount`, `isValid`, `generateReceipt`, `isForContract` | `Contract` | `include/finance/Payment.h` |
| `Scholarship` | 4 | `Scholarship`, `isValid`, `getAmount`, `getScholarshipId`, `belongsToStudent` | `Student` | `include/finance/Scholarship.h` |
| `ScholarshipManager` | 3 | `ScholarshipManager`, `getManagerId`, `getMaximumScholarship`, `addScholarship`, `removeScholarship`, `findScholarship`, `calculateTotalScholarships`, `getScholarshipCount` | `Scholarship` | `include/finance/ScholarshipManager.h` |
| `Address` | 5 | `Address`, `getAddressId`, `getFullAddress`, `updateAddress` | — | `include/infrastructure/Address.h` |
| `Book` | 4 | `Book`, `updateTitle`, `belongsToSubject`, `isInLibrary` | `Library` | `include/infrastructure/Book.h` |
| `InfrastructureBuilding` | 4 | `InfrastructureBuilding`, `getBuildingId`, `getBuildingName`, `updateBuildingName`, `updateNumberOfFloors`, `isAtAddress` | `Address` | `include/infrastructure/Building.h` |
| `Cafeteria` | 4 | `Cafeteria`, `getCafeteriaId`, `getCafeteriaName`, `getLocation`, `getSeatingCapacity`, `updateSeatingCapacity`, `hasAvailableSeats` | — | `include/infrastructure/Cafeteria.h` |
| `ContactInfo` | 3 | `ContactInfo`, `getContactId`, `getPhoneNumber`, `getEmail`, `updatePhoneNumber`, `updateEmail` | — | `include/infrastructure/ContactInfo.h` |
| `DormRoom` | 4 | `DormRoom`, `getRoomId`, `getDormitoryId`, `getRoomNumber`, `getCapacity`, `isFull`, `updateCapacity`, `belongsToDormitory` | `Dormitory` | `include/infrastructure/DormRoom.h` |
| `Dormitory` | 4 | `Dormitory`, `getDormitoryId`, `getDormitoryName`, `getTotalRooms`, `updateAddress`, `updateTotalRooms`, `hasAvailableRooms` | — | `include/infrastructure/Dormitory.h` |
| `Infrastructure` | 5 | `Infrastructure`, `getInfrastructureId`, `getInfrastructureName`, `getLocation`, `getTotalBuildings`, `getTotalRooms`, `addBuilding`, `removeBuilding`, `addRoom`, `removeRoom`, `updateLocation` | — | `include/infrastructure/Infrastructure.h` |
| `Library` | 4 | `Library`, `updateTotalBooks`, `hasBooksAvailable`, `getLibraryId` | — | `include/infrastructure/Library.h` |
| `LibraryBook` | 4 | `LibraryBook`, `isAvailable`, `setAvailability` | — | `include/infrastructure/LibraryBook.h` |
| `LibraryCard` | 3 | `LibraryCard`, `borrowBook`, `returnBook`, `hasBorrowedBook`, `belongsToStudent` | `Student` | `include/infrastructure/LibraryCard.h` |
| `Meal` | 5 | `Meal`, `updatePrice`, `isAffordable`, `isProvidedBy` | `Cafeteria` | `include/infrastructure/Meal.h` |
| `Route` | 5 | `Route`, `updateDuration`, `getAverageSpeed` | — | `include/infrastructure/Route.h` |
| `Transport` | 5 | `Transport`, `updateFare`, `hasAvailableSeats` | — | `include/infrastructure/Transport.h` |
| `DeaneryService` | 5 | `DeaneryService`, `registerStudent`, `removeStudent`, `hasStudent`, `registerTeacher`, `removeTeacher`, `hasTeacher`, `registerGroup`, `removeGroup`, `hasGroup`, `registerOrder`, `removeOrder`, `hasOrder` | — | `include/services/DeaneryService.h` |
| `Notification` | 3 | `Notification`, `getMessage`, `updateMessage`, `isForStudent` | `Student` | `include/services/Notification.h` |
| `NotificationService` | 2 | `NotificationService`, `notifyStudent`, `notifyTeacher`, `getNotificationsSent`, `resetCounter`, `notifyStudent` | `Student` | `include/services/NotificationService.h` |
| `ScholarshipAwardService` | 3 | `ScholarshipAwardService`, `awardScholarship`, `revokeScholarship`, `hasScholarship`, `getScholarshipsAwarded`, `getMaximumScholarship` | — | `include/services/ScholarshipManager.h` |
| `Enrollment` | 5 | `Enrollment`, `getEnrollmentId`, `getStudentId`, `getCourseId`, `getEnrollmentDate`, `getStatus`, `setStatus`, `isActive`, `belongsToStudent` | `Student` | `include/students/Enrollment.h` |
| `GraduateStudent` | 5 | `GraduateStudent`, `getResearchArea`, `getThesisTitle`, `getResearchProgress`, `updateResearchProgress`, `changeThesisTitle`, `submitThesis`, `isThesisSubmitted`, `displayInformation` | — | `include/students/GraduateStudent.h` |
| `InternationalStudent` | 6 | `InternationalStudent`, `getHomeCountry`, `getPassportNumber`, `getVisaExpiryDate`, `renewVisa`, `updateLanguageProficiency`, `updateNativeLanguage`, `isVisaValid`, `displayInformation` | — | `include/students/InternationalStudent.h` |
| `Student` | 4 | `Student`, `getStudentId`, `getFirstName`, `getLastName`, `getYearOfStudy`, `updateName`, `promoteToNextYear`, `displayInformation` | — | `include/students/Student.h` |
| `StudentGroup` | 3 | `StudentGroup`, `getGroupId`, `getGroupName`, `addStudent`, `removeStudent`, `getStudentCount` | `Student` | `include/students/StudentGroup.h` |
| `StudentProfile` | 4 | `StudentProfile`, `getStudentId`, `getEmail`, `getPhoneNumber`, `getAddress`, `setEmail`, `setPhoneNumber`, `setAddress`, `belongsToStudent` | `Student` | `include/students/StudentProfile.h` |
| `Transcript` | 3 | `Transcript`, `setStudent`, `addGrade`, `getGrades`, `getAcademicYear` | `Grade`, `Student` | `include/students/Transcript.h` |
| `UndergraduateStudent` | 3 | `UndergraduateStudent`, `getSpecialization`, `getCreditsCompleted`, `completeCredits`, `isEligibleForInternship`, `registerForInternship`, `displayInformation` | — | `include/students/UndergraduateStudent.h` |
| `Curator` | 2 | `Curator`, `getCuratorId`, `getGroupId`, `displayInformation` | — | `include/teachers/Curator.h` |
| `DepartmentHead` | 3 | `DepartmentHead`, `getYearsAsHead`, `getTeachersSupervised`, `getOfficeNumber`, `updateOfficeNumber`, `displayDepartmentHeadInformation` | — | `include/teachers/DepartmentHead.h` |
| `HeadOfDepartment` | 3 | `HeadOfDepartment`, `getHeadId`, `getDepartmentId`, `getTeacherId`, `displayInformation` | — | `include/teachers/HeadOfDepartment.h` |
| `LabAssistant` | 3 | `LabAssistant`, `getAssistantId`, `getTeacherId`, `getAssignedRoom`, `displayInformation` | — | `include/teachers/LabAssistant.h` |
| `Professor` | 4 | `Professor`, `getAcademicRank`, `getResearchField`, `getPublications`, `addPublication`, `updateAcademicRank`, `displayProfessorInformation` | — | `include/teachers/Professor.h` |
| `Teacher` | 6 | `Teacher`, `getTeacherId`, `getFullName`, `getDepartment`, `getSalary`, `updateDepartment`, `updateSalary`, `displayInformation` | — | `include/teachers/Teacher.h` |
| `TeacherContract` | 6 | `TeacherContract`, `getContractId`, `getTeacherId`, `getContractType`, `getStartDate`, `getEndDate`, `isActive`, `activate`, `deactivate`, `updateEndDate`, `isForTeacher` | `Teacher` | `include/teachers/TeacherContract.h` |
| `TeacherEvaluation` | 5 | `TeacherEvaluation`, `getEvaluationId`, `getTeacherId`, `getTeachingScore`, `getComments`, `updateScore`, `updateComments`, `displayEvaluationInformation`, `isForTeacher` | `Teacher` | `include/teachers/TeacherEvaluation.h` |
| `TeacherResearch` | 5 | `TeacherResearch`, `getResearchId`, `getTeacherId`, `getResearchTitle`, `getPublication`, `getPublicationYear`, `updatePublication`, `displayResearchInformation`, `isForTeacher` | `Teacher` | `include/teachers/TeacherResearch.h` |
| `TeacherSchedule` | 2 | `TeacherSchedule`, `getTeacherId`, `addLesson`, `removeLesson`, `getLessonCount`, `getLessons`, `belongsToTeacher` | `Teacher` | `include/teachers/TeacherSchedule.h` |

## Custom exceptions

- `DeaneryException`
- `DuplicateEntityException`
- `GradeOutOfBoundsException`
- `GroupNotFoundException`
- `InvalidDocumentException`
- `MissingPrerequisiteException`
- `RoomCapacityExceededException`
- `ScheduleConflictException`
- `ScholarshipLimitExceededException`
- `StudentNotFoundException`
- `TeacherNotFoundException`
- `UnauthorizedAccessException`

All 12 custom exceptions derive from `DeaneryException` except the base class itself; the test suite verifies their message/exception behaviour.

## Build and test

Requirements: CMake 3.16+, a C++17 compiler, and GCC when collecting coverage. From the project root:

```powershell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug
ctest --test-dir build --output-on-failure -C Debug
.\build\dean_office_tests.exe
```

## Coverage

Coverage is enabled with GCC through the CMake option `ENABLE_COVERAGE`. Use a separate build directory so ordinary and coverage builds do not share compiler flags:

```powershell
cmake -S . -B build-coverage -DENABLE_COVERAGE=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build-coverage
ctest --test-dir build-coverage --output-on-failure
```

The verified run for this project version produced **202 passing checks, 0 failures**, and **91.54% source-line coverage (1,548 of 1,691 executable source lines)** using GCC/gcov. Coverage is measured over project `.cpp` files, excluding system headers and non-executable lines. Re-run the commands after any source or test change; coverage can change with compiler versions and build options.

## Test scope

`tests/Tests.cpp` exercises exception handling and representative constructor validation, getters, state changes, collection operations, calculations, service workflows, output methods, and typed relationships across the domain modules. The test runner reports individual checks and exits non-zero when any check fails.

## Documentation

Public declarations are documented in the headers. The repository includes a `Doxyfile`; generate API documentation from the project root with `doxygen Doxyfile`. Generated output is placed in `docs/doxygen/` and is ignored by Git.

