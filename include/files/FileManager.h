//
// Created by developer on 7/16/25.
//

#pragma once
#include "FileInfo.h"

namespace YetAnotherNotepad::Files {

    class FileManager {
    private:
        FileInfo current_file_info_;
    public:
        FileManager() = default;

        virtual std::string readFile(FileInfo &file_info);
        virtual std::string readFile();
        virtual void writeFile();
        virtual void appendFile();

    protected:
        virtual void setCurrentFile(FileInfo &file_info);
        virtual FileInfo* getCurrentFile();
    };

}
