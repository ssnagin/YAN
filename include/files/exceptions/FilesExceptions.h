//
// Created by developer on 7/16/25.
//

#ifndef FILESEXCEPTIONS_H
#define FILESEXCEPTIONS_H
#include <exception>
#include <iostream>

#include "../../YANException.h"

namespace YetAnotherNotepad::Files {

    class FileDoesNotExistException final : public YANException {
    public:
        explicit FileDoesNotExistException(const std::string &message)
            : YANException(message) {
        }
    };

    class FilePremissionDeniedException final : public YANException {
    public:
        explicit FilePremissionDeniedException(const std::string &message)
            : YANException(message) {
        }
    };

}

#endif //FILESEXCEPTIONS_H
