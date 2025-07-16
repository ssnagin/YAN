
#pragma once;
#include "../../../include/files/factories/FileInfoFactory.h"
#include <wx/filename.h>

#include "../../../include/files/exceptions/FilesExceptions.h"
//
// Created by developer on 7/16/25.
//
namespace YetAnotherNotepad::Files {
    FileInfo* FileInfoFactory::create(wxFileDialog wx_file_dialog)
    throw(FileDoesNotExistException, FilePremissionDeniedException) {

        wxFileName file(wx_file_dialog.GetPath());

        if (!file.FileExists())
            throw FileDoesNotExistException("File does not exist or cannot be accessed!");

        return new FileInfo(
            std::string(file.GetName()),
            std::string(file.GetPath()),
            std::string(file.GetAbsolutePath()),
            std::string(file.GetExt()),
            file.GetSize().ToULong()
        );
    }
}
