cmake_minimum_required(VERSION 3.28)
project(YAN)

set(CMAKE_CXX_STANDARD 23)
#
#find_program(WX_CONFIG_EXECUTABLE wx-config)
#if(NOT WX_CONFIG_EXECUTABLE)
#    message(FATAL_ERROR "wx-config was not found")
#endif()
#
#execute_process(
#        COMMAND ${WX_CONFIG_EXECUTABLE} --cxxflags
#        OUTPUT_VARIABLE WX_CXX_FLAGS
#        OUTPUT_STRIP_TRAILING_WHITESPACE
#)
#execute_process(
#        COMMAND ${WX_CONFIG_EXECUTABLE} --libs
#        OUTPUT_VARIABLE WX_LINK_FLAGS
#        OUTPUT_STRIP_TRAILING_WHITESPACE
#)

find_package(wxWidgets REQUIRED COMPONENTS core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()
#include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} main.cpp)

target_compile_options(YAN PRIVATE ${WX_CXX_FLAGS})
target_link_libraries(YAN ${wxWidgets_LIBRARIES})
target_link_libraries(YAN ${WX_LINK_FLAGS})