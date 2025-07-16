#pragma once

#include "../include/YetAnotherNotepad.h"

#include "../include/files/FileManager.h"
#include "../include/gui/frames/MainFrame.h"

namespace YetAnotherNotepad {

    Files::FileManager* file_manager = new Files::FileManager();


    bool YetAnotherNotepad::OnInit() {

        YetAnotherNotepad:GUI:Frames:
            auto* frame = new GUI::Frames::MainFrame("YAN");

        frame->Show();
        return true;
    }

    int YetAnotherNotepad::OnExit() {
        //TODO

        return wxApp::OnExit();
    }
}

wxIMPLEMENT_APP(YetAnotherNotepad::YetAnotherNotepad);