#include <wx/filename.h>
#include "../../../include/files/factories/FileInfoFactory.h"

#include "../../../include/files/exceptions/FilesExceptions.h"
//
// Created by developer on 7/16/25.
//
namespace YetAnotherNotepad::Files {
    FileInfo FileInfoFactory::create(wxFileDialog& wx_file_dialog) {

        wxFileName file(wx_file_dialog.GetPath());

        // if (!file.FileExists()) // Здесь крашится
        //     throw FileDoesNotExistException("File does not exist or cannot be accessed!");

        return FileInfo(
            std::string(file.GetName()),
            std::string(file.GetPath()),
            std::string(file.GetAbsolutePath()),
            std::string(file.GetExt()),
            file.GetSize().ToULong()
        );
    }
}
