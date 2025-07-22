//
// Created by developer on 7/16/25.
//

#ifndef FILEINFOFACTORY_H
#define FILEINFOFACTORY_H
#include "../FileInfo.h"
#include <wx/filedlg.h>

namespace YetAnotherNotepad::Files {
    class FileInfoFactory {
    public:
        static FileInfo create(wxFileDialog& wx_file_dialog);
    };
}

#endif //FILEINFOFACTORY_H
