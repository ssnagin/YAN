//
// Created by developer on 8/1/25.
//

#include "../../include/files/FileContent.h"

#include <iostream>

namespace YetAnotherNotepad::Files {
    void FileContent::append(std::string &text) {
        this->content_ += text;
    }

    void FileContent::set(const std::string &text) {
        this->content_ = text;
    }
}
