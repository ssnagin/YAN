//
// Created by developer on 7/16/25.
//

#pragma once
#include <iostream>
#include <cstdint>
#include <filesystem>

namespace YetAnotherNotepad::Files {

    class FileInfo {
    private:
        std::string filename_ = "";
        std::string path_ = "";
        std::string absPath_ = "";
        std::string extension_ = "";
        uint64_t filesize_ = 0L;

    public:
        FileInfo(
            const std::string& filename,
            const std::filesystem::path& path,
            const std::filesystem::path& absPath,
            const std::string& extension,
            uint64_t filesize
        ) :
            filename_(filename),
            path_(path),
            absPath_(absPath),
            extension_(extension),
            filesize_(filesize)
        {
            if (filesize_ == UINT64_MAX)
                throw std::invalid_argument("Invalid filesize");
        }

        FileInfo(); // idk but this should be deleted in da future

        [[nodiscard]] const std::string& filename() const noexcept { return filename_; }
        [[nodiscard]] const std::string& path() const noexcept { return path_; }
        [[nodiscard]] const std::string& absPath() const noexcept { return absPath_; }
        [[nodiscard]] const std::string& extension() const noexcept { return extension_; }
        [[nodiscard]] uint64_t filesize() const noexcept { return filesize_; }
    };
}
