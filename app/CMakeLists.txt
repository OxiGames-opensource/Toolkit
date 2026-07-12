cmake_minimum_required(VERSION 3.16)

project(OxiToolkit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(oxitoolkit
    src/Application/Launcher/main.cpp
    src/Application/Launcher/Launcher.cpp
    src/Application/Launcher/ArgumentParser.cpp
    src/Application/Bootstrap/Bootstrap.cpp
    src/Application/Bootstrap/StartupDiagnostics.cpp
    src/Application/Bootstrap/Configuration/Configuration.cpp
    src/Application/Bootstrap/Environment/Environment.cpp
    src/Application/Kernel/Kernel.cpp
    src/Runtime/main/Runtime.cpp
)

target_include_directories(oxitoolkit PRIVATE
    src
)