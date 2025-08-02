#include <iostream>

#include "../../include/files/FileManager.h"

#include <fstream>
#include <wx/msgdlg.h>

#include "../../include/files/exceptions/FilesExceptions.h"

namespace YetAnotherNotepad::Files {

    void FileManager::setCurrentFile(FileInfo& file_info) {
        this->current_file_info = file_info;
    }

    FileInfo& FileManager::getCurrentFile() {
        return this->current_file_info;
    }

    FileContent &FileManager::getCurrentFileContent() {
        return this->current_file_content;
    }

    void FileManager::setCurrentFileContent(FileContent &file_content) {
        this->current_file_content = file_content;
    }

    void FileManager::newFile() {
        this->current_file_content = FileContent();
        this->current_file_info = FileInfo();
    }


    std::string FileManager::readFile(FileInfo& file_info) {

        std::ifstream file(file_info.absPath());

        if (not file.good()) {
            throw FilePremissionDeniedException(file_info.absPath() + "cannot be opened!");
        }

        setCurrentFile(file_info);

        this->current_file_content.set({std::istreambuf_iterator<char>{file}, std::istreambuf_iterator<char>{}});
        return current_file_content.get(); // перерефакторить потом это всё
    }

    std::string FileManager::readFile() {
        return readFile(getCurrentFile());
    }

    void FileManager::writeFile() {
        std::ofstream file;

        file.open(getCurrentFile().absPath(), std::ios::out);

        // if (!file.is_open()) {
        //     throw FilePremissionDeniedException("");
        // }

        file << this->current_file_content.get();

        file.close();
    }

    void FileManager::appendFile() {}
}
