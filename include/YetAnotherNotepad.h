//
// Created by developer on 7/16/25.
//

#pragma once
#include <wx/wx.h>

namespace YetAnotherNotepad {

    class YetAnotherNotepad : public wxApp {
    public:
        virtual bool OnInit() override;
        virtual int OnExit() override;
    };

}

