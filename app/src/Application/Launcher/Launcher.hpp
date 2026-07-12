#pragma once

#include "Application/Launcher/ArgumentParser.hpp"

namespace OxiToolkit::Application::Launcher {

class Launcher
{
public:
    int run(int argc, char* argv[]);

private:
    void printHelp() const;
    void printVersion() const;

    ArgumentParser argumentParser;
};

}