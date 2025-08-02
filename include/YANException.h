//
// Created by developer on 7/16/25.
//

#pragma once
#ifndef YANEXCEPTION_H
#define YANEXCEPTION_H

#include <iostream>

namespace YetAnotherNotepad {
    class YANException : std::exception {
    public:
        std::string message_;

        explicit YANException(const std::string& message)
        : message_(message) {}

        const char* what() const noexcept override {
            return message_.c_str();
        }

        [[nodiscard]] const std::string& getMessage() const { return message_; }
    };
}

#endif //YANEXCEPTION_H
