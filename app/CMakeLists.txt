cmake_minimum_required(VERSION 3.16)

project(OxiToolkit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(oxitoolkit
    src/Application/main/main.cpp
    src/Application/Bootstrap/StartupDiagnostics.cpp
    src/Application/Kernel/Kernel.cpp
    src/Runtime/main/Runtime.cpp
)

target_include_directories(oxitoolkit PRIVATE
    src
)