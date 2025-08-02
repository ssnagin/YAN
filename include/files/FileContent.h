//
// Created by developer on 8/1/25.
//

#ifndef FILECONTENT_H
#define FILECONTENT_H
#include <string>

namespace YetAnotherNotepad::Files {

    struct FileContent {
    private:
        std::string content_ {};

    public:
        void append(std::string &text);
        void set(const std::string &text);

        [[nodiscard]] std::string get() const noexcept {return content_;}

        FileContent() : content_("") {}
    };
}

#endif //FILECONTENT_H
