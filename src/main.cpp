#include <codecvt>
#include <iostream>
#include <locale>
#include <string>
#include <fstream>

#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/msgdlg.h>
#include <wx/button.h>

using namespace std;

namespace YetAnotherNotepad {

    class Frame : public wxFrame {
    public:
        Frame() : wxFrame {nullptr, wxID_ANY, "Test", wxDefaultPosition, {640, 480}} {

        }
    private:
    wxPanel* panel = new wxPanel {this};
    };

    class Application : public wxApp {
        bool OnInit() override {return (new Frame)->Show();}
    };

    wstring_convert<codecvt_utf8<wchar_t>> converter;

    // bool checkEOF(const string &input, const string &key = "EOF") {
    //     return input == key;
    // }
    //
    // int main(int arg_counter, char *argv[]) {
    //
    //     string current_line = "";
    //     string content = "";
    //
    //     while (getline(cin, current_line)) {
    //         if (checkEOF(current_line)) break;
    //         content += current_line + "\n";
    //     }
    //
    //     cout << content << endl;
    //     return 0;
    // }

}

wxIMPLEMENT_APP(YetAnotherNotepad::Application);