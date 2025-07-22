#include <iostream>

#include "../../include/files/FileManager.h"

#include <fstream>
#include <wx/file.h>
#include <wx/msgdlg.h>

#include "../../include/files/exceptions/FilesExceptions.h"

namespace YetAnotherNotepad::Files {

    void FileManager::setCurrentFile(FileInfo& file_info) {
        this->current_file_info_ = file_info;
    }

    FileInfo& FileManager::getCurrentFile() {
        return this->current_file_info_;
    }

    std::string FileManager::readFile(FileInfo& file_info) {

        std::ifstream file(file_info.absPath());

        if (not file.good()) {
            throw FilePremissionDeniedException(file_info.absPath() + "cannot be opened!");
        }

        return {std::istreambuf_iterator<char>{file}, std::istreambuf_iterator<char>{}};
    }

    std::string FileManager::readFile() {
        return readFile(getCurrentFile());
    }

    void FileManager::writeFile() {

    }

    void FileManager::appendFile() {

    }
}
