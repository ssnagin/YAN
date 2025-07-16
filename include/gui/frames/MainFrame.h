//
// Created by developer on 7/16/25.
//

#pragma once
#include <wx/wx.h>
#include <wx/textctrl.h>


namespace YetAnotherNotepad {

    class MainFrame : public wxFrame {
    public:
        MainFrame(const wxString& title);
    private:
        wxTextCtrl* m_textCtrl;
        wxMenuBar* m_menuBar;

        void CreateControls();
        void CreateMenu();
        void BindEvents();


        void OnFileNew(wxCommandEvent& event);
        void OnFileOpen(wxCommandEvent& event);

        void OnExit(wxCommandEvent& event);

    };

}
