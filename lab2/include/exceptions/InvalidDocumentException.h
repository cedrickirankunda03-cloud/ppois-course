
#ifndef INVALID_DOCUMENT_EXCEPTION_H
#define INVALID_DOCUMENT_EXCEPTION_H

#include "DeaneryException.h"

class InvalidDocumentException : public DeaneryException {
public:
    using DeaneryException::DeaneryException;
};

#endif
