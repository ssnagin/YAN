//
// Created by developer on 7/16/25.
//

#include <wx/filedlg.h>
#include <wx/file.h>
#include <memory>


#include "../../../include/gui/frames/MainFrame.h"

#include "../../../include/YetAnotherNotepad.h"
#include "../../../include/files/FileInfo.h"
#include "../../../include/files/FileManager.h"
#include "../../../include/files/exceptions/FilesExceptions.h"
#include "../../../include/files/factories/FileInfoFactory.h"

namespace YetAnotherNotepad::GUI::Frames {

    // std::unique_ptr<Files::FileManager> fileManager = std::make_unique<Files::FileManager>();
    Files::FileManager& fileManager = Files::FileManager::instance();

    auto* fileInfoFactory = new Files::FileInfoFactory();

    MainFrame::MainFrame(const wxString &title)
        : wxFrame(nullptr, wxID_ANY, title) {

        CreateControls();
        CreateMenu();
        BindEvents();

        SetMinSize(wxSize(800, 600));
        Center();
    }

    void MainFrame::CreateControls() {
        auto panel = new wxPanel(this);

        m_textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize,
            wxTE_MULTILINE | wxTE_RICH | wxTE_DONTWRAP);

        auto sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(m_textCtrl, 1, wxEXPAND);
        panel->SetSizer(sizer);
    }

    void MainFrame::CreateMenu() {

        m_menuBar = new wxMenuBar();

        auto* fileMenu = new wxMenu();
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
        Bind(wxEVT_MENU, &MainFrame::OnFileSaveAs, this, wxID_SAVEAS);
        Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    }

    void MainFrame::OnFileNew(wxCommandEvent &event) {
        m_textCtrl->Clear();
        SetTitle("YAN");
    }

    void MainFrame::OnFileOpen(wxCommandEvent &event) {

        std::string result;

        wxFileDialog openFileDialog(this, _(L"Open File"), "", "",
                               "all files (*.*)|*.*",
                               wxFD_OPEN|wxFD_FILE_MUST_EXIST);

        if (openFileDialog.ShowModal() == wxID_CANCEL) return;

        try {

            Files::FileInfo file_info = Files::FileInfoFactory::create(openFileDialog);
            result = fileManager.readFile(file_info);

            m_textCtrl->Clear();
            m_textCtrl->AppendText(result);

        } catch (const Files::FilePremissionDeniedException& exception) {
            wxString exceptionMessage(exception.getMessage().c_str(), wxConvUTF8);
            wxMessageBox(exceptionMessage, L"Ошибка", wxICON_ERROR);
        } catch (const Files::FileDoesNotExistException& exception) {
            wxString exceptionMessage(exception.getMessage().c_str(), wxConvUTF8);
            wxMessageBox(exceptionMessage, L"Ошибка", wxICON_ERROR);
        } catch (std::exception e) {
            wxMessageBox(e.what(), L"UNHANDLED EXCEPTION", wxICON_ERROR);
        }
    }

    void MainFrame::OnFileSaveAs(wxCommandEvent &event) {
        wxFileDialog openFileDialog(this, _(L"Save As"), "", "", "all files (*.*)|*.*",
            wxFD_SAVE);

        if (openFileDialog.ShowModal() == wxID_CANCEL) return;

        try {

        } catch (std::exception e) {

        }
    }

    void MainFrame::OnExit(wxCommandEvent &event) {
        Close(true);
    }
}
