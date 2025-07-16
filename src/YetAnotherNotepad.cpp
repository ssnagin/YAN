#pragma once

#include "../include/YetAnotherNotepad.h"
#include "../include/gui/frames/MainFrame.h"

namespace YetAnotherNotepad {

    bool YetAnotherNotepad::OnInit() {

        MainFrame* frame = new MainFrame("My Text Editor");
        frame->Show();
        return true;
    }

    int YetAnotherNotepad::OnExit() {
        //TODO

        return wxApp::OnExit();
    }
}

wxIMPLEMENT_APP(YetAnotherNotepad::YetAnotherNotepad);