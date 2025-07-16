//
// Created by developer on 7/16/25.
//

#pragma once

#include "../../../include/gui/frames/MainFrame.h"

namespace YetAnotherNotepad {

    MainFrame::MainFrame(const wxString &title)
        : wxFrame(nullptr, wxID_ANY, title) {

        CreateControls();
        CreateMenu();
        BindEvents();

        SetMinSize(wxSize(800, 600));
        Center();
    }

    void MainFrame::CreateControls() {
        wxPanel* panel = new wxPanel(this);
        m_textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize,
            wxTE_MULTILINE | wxTE_RICH | wxTE_DONTWRAP);

        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(m_textCtrl, 1, wxEXPAND);
        panel->SetSizer(sizer);
    }

    void MainFrame::CreateMenu() {

        m_menuBar = new wxMenuBar();

        wxMenu* fileMenu = new wxMenu();
        fileMenu->Append(wxID_NEW, "&New\tCtrl+N");
        fileMenu->Append(wxID_OPEN, "&Open\tCtrl+O");

        m_menuBar->Append(fileMenu, "&File");
        SetMenuBar(m_menuBar);
    }

    void MainFrame::BindEvents() {
        Bind(wxEVT_MENU, &MainFrame::OnFileNew, this, wxID_NEW);
        Bind(wxEVT_MENU, [this](auto&) { Close(true); }, wxID_EXIT); // ???
    }

    void MainFrame::OnFileNew(wxCommandEvent &event) {
        m_textCtrl->Clear();
        SetTitle("Test 123456");
    }
}