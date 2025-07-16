#pragma once
#include <iostream>

#include "../../include/files/FileManager.h"

namespace YetAnotherNotepad::Files {

    void FileManager::setCurrentFile(FileInfo& file_info) {
        this->current_file_info_ = file_info;
    }

    FileInfo FileManager::getCurrentFile() {
        return this->current_file_info_;
    }

    std::string FileManager::readFile(FileInfo& file_info) {
        return "";
    }

    std::string FileManager::readFile() {
        return ;
    }

    void FileManager::writeFile() {

    }

    void FileManager::appendFile() {

    }
}
