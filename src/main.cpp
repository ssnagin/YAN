#include <codecvt>
#include <iostream>
#include <locale>
#include <string>
#include <fstream>

#include <wx/wx.h>

using namespace std;

wstring_convert<codecvt_utf8<wchar_t>> converter;

bool checkEOF(const string &input, const string &key = "EOF") {
    return input == key;
}

int main(int arg_counter, char *argv[]) {

    string current_line = "";
    string content = "";

    while (getline(cin, current_line)) {
        if (checkEOF(current_line)) break;
        content += current_line + "\n";
    }

    cout << content << endl;
    return 0;
}