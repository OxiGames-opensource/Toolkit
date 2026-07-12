#include "Application/Launcher/ArgumentParser.hpp"

#include <string>

namespace OxiToolkit::Application::Launcher {

ExecutionMode ArgumentParser::parse(int argc, char* argv[]) const
{
    for (int index = 1; index < argc; ++index) {
        const std::string argument(argv[index]);

        if (argument == "--debug") {
            return ExecutionMode::Debug;
        }

        if (argument == "--help" || argument == "-h") {
            return ExecutionMode::Help;
        }

        if (argument == "--version" || argument == "-v") {
            return ExecutionMode::Version;
        }
    }

    return ExecutionMode::Normal;
}

}