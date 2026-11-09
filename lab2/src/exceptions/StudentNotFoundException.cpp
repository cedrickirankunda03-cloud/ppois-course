#include "exceptions/StudentNotFoundException.h"

StudentNotFoundException::StudentNotFoundException(
    const std::string& studentId
)
    : DeaneryException("Student not found: " + studentId)
{
}
