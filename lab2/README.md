# Lab 2: Dean's Office (Деканат) Domain Model

## Classes, Fields, Methods, and Associations

| Class | Fields | Methods | Associations (related classes) |
| :--- | :--- | :--- | :--- |
| University | 3 | 4 | Faculty, DeaneryService |
| Faculty | 4 | 5 | Department, Group |
| Department | 4 | 4 | Teacher, Subject |
| Group | 4 | 6 | Student, Schedule |
| Student | 7 | 10 | Group, Transcript, Application |
| Teacher | 5 | 7 | Department, Subject, Schedule |
| Dean | 3 | 5 | Faculty, Order |
| Subject | 3 | 3 | Teacher, Course |
| Schedule | 3 | 6 | Group, Teacher, Room, Lesson |
| Grade | 3 | 2 | Student, Subject |
| Exam | 3 | 5 | Subject, Student, Grade |
| Transcript | 3 | 5 | Student, Grade |
| Order | 4 | 4 | Student, DeaneryService |
| Application | 4 | 4 | Student, Order |
| Room | 4 | 3 | Building, Schedule |
| DeaneryService | 5 | 12 | Student, Teacher, Group, Order |
| Course | 3 | 4 | Subject, Semester |
| Semester | 3 | 2 | Course, Schedule |
| Lesson | 5 | 4 | Schedule, Subject, Teacher |
| AttendanceRecord | 3 | 3 | Student, Lesson |
| Credit | 3 | 4 | Subject, Student |
| Curriculum | 4 | 5 | Specialization, Subject |
| Specialization | 3 | 2 | Department, Curriculum |
| Syllabus | 4 | 3 | Subject, Curriculum |
| Applicant | 5 | 4 | Application, EntranceExam |
| EntranceExam | 4 | 3 | Applicant, Subject |
| HeadOfDepartment | 3 | 4 | Department, Teacher |
| Curator | 2 | 3 | Group, Student |
| Methodologist | 3 | 4 | DeaneryService, Curriculum |
| LabAssistant | 3 | 3 | Teacher, Room |
| Rector | 3 | 4 | University, Order |
| Diploma | 4 | 3 | Student, Faculty |
| StudentIDCard | 3 | 2 | Student |
| Contract | 5 | 4 | Student, Payment |
| Payment | 4 | 3 | Contract, Student |
| Scholarship | 4 | 4 | Student, ScholarshipManager |
| MedicalCertificate | 3 | 2 | Student |
| AcademicLeave | 4 | 3 | Student, Application |
| Building | 4 | 2 | Room, Address |
| Address | 5 | 2 | Building, Student, Teacher |
| ContactInfo | 3 | 2 | Student, Teacher, Applicant |
| Dormitory | 4 | 3 | DormRoom, Student |
| DormRoom | 4 | 2 | Dormitory, Student |
| Library | 3 | 3 | Book, LibraryCard |
| Book | 4 | 2 | Library, Subject |
| LibraryCard | 3 | 3 | Student, Book |
| ReportGenerator | 2 | 6 | Student, Group, DeaneryService |
| NotificationService | 2 | 4 | Student, Teacher |
| Notification | 3 | 2 | NotificationService, Student |
| ScholarshipManager | 3 | 5 | Scholarship, Student |
| ExamSheet | 4 | 4 | Exam, Teacher, Student |
| GradeBook | 3 | 5 | Student, Grade, Subject |



## Custom Exceptions (12)

1. DeaneryException (Base class)
2. StudentNotFoundException
3. TeacherNotFoundException
4. GroupNotFoundException
5. GradeOutOfBoundsException
6. ScheduleConflictException
7. InvalidDocumentException
8. UnauthorizedAccessException
9. ScholarshipLimitExceededException
10. RoomCapacityExceededException
11. DuplicateEntityException
12. MissingPrerequisiteException