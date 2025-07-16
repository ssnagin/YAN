cmake_minimum_required(VERSION 3.28)
project(YAN)

set(CMAKE_CXX_STANDARD 23)

find_package(wxWidgets REQUIRED COMPONENTS core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

add_executable(${PROJECT_NAME} src/YetAnotherNotepad.cpp
        include/YetAnotherNotepad.h
        include/files/FileManager.h
        src/files/FileManager.cpp
        src/events/EventManager.cpp
        include/events/EventManager.h
        src/gui/frames/MainFrame.cpp
        include/gui/frames/MainFrame.h
)

target_compile_options(YAN PRIVATE ${WX_CXX_FLAGS})
target_link_libraries(YAN ${wxWidgets_LIBRARIES})
target_link_libraries(YAN ${WX_LINK_FLAGS})