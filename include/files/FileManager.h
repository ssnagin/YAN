//
// Created by developer on 7/16/25.
//

#pragma once
#include "FileInfo.h"

namespace YetAnotherNotepad::Files {

    class FileManager {

    public:
        FileInfo current_file_info = FileInfo();
        FileContent current_file_content = FileContent();

        static FileManager& instance() {static FileManager s; return s;}

        FileManager() = default;
        FileManager(FileManager const&) = delete;
        FileManager& operator=(FileManager const&) = delete;

        virtual std::string readFile(FileInfo &file_info);
        virtual std::string readFile();
        virtual void writeFile();
        virtual void appendFile();

    protected:
        virtual void setCurrentFile(FileInfo &file_info);
        virtual FileInfo& getCurrentFile();

        virtual void setCurrentFileContent(FileContent &file_content);
        virtual FileContent& getCurrentFileContent();
    };

}
