//
// Created by developer on 7/16/25.
//
#pragma once
#ifndef FILEINFOFACTORY_H
#define FILEINFOFACTORY_H
#include <wx/gtk/filedlg.h>
#include "../FileInfo.h"

namespace YetAnotherNotepad::Files {
    class FileInfoFactory {

        virtual FileInfo *create(wxFileDialog wx_file_dialog);
    };
}

#endif //FILEINFOFACTORY_H
