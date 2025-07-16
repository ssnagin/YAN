//
// Created by developer on 7/16/25.
//

#pragma once

#include <wx/filedlg.h>
#include <wx/file.h>
#include <memory>


#include "../../../include/gui/frames/MainFrame.h"

#include "../../../include/files/FileInfo.h"

namespace YetAnotherNotepad::GUI::Frames {

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
        fileMenu->Append(wxID_NEW, L"&Новый\tCtrl+N");
        fileMenu->Append(wxID_OPEN, L"&Открыть\tCtrl+O");
        fileMenu->Append(wxID_SAVEAS, L"&Сохранить как\tCtrl+Shift+S");

        fileMenu->AppendSeparator();

        fileMenu->Append(wxID_EXIT, L"&Выход\tAlt+F4");

        m_menuBar->Append(fileMenu, "&File");
        SetMenuBar(m_menuBar);
    }

    void MainFrame::BindEvents() {
        Bind(wxEVT_MENU, &MainFrame::OnFileNew, this, wxID_NEW);
        Bind(wxEVT_MENU, &MainFrame::OnFileOpen, this, wxID_OPEN);
        Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    }

    void MainFrame::OnFileNew(wxCommandEvent &event) {
        m_textCtrl->Clear();
        SetTitle("YAN");
    }

    void MainFrame::OnFileOpen(wxCommandEvent &event) {
        wxFileDialog openFileDialog(this, _(L"Open File"), "", "",
                               "all files (*.*)|*.*",
                               wxFD_OPEN|wxFD_FILE_MUST_EXIST);

        if (openFileDialog.ShowModal() == wxID_CANCEL) return;

        wxString path = openFileDialog.GetPath();

        wxFile file;
        if (!file.Open(path, wxFile::read)) {
            wxMessageBox(L"Не удалось загрузить файл", L"Ошибка", wxICON_ERROR);
            return;
        }

        wxString content;
        file.ReadAll(&content);
        file.Close();

        m_textCtrl->AppendText(content);
    }

    void MainFrame::OnFileSaveAs(wxCommandEvent &event) {
        
    }

    void MainFrame::OnExit(wxCommandEvent &event) {
        Close(true);
    }
}
