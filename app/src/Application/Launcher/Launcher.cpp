#include "Application/Launcher/Launcher.hpp"

#include "Application/Bootstrap/Bootstrap.hpp"

#include <iostream>

namespace OxiToolkit::Application::Launcher {

int Launcher::run(int argc, char* argv[])
{
    const ExecutionMode mode = argumentParser.parse(argc, argv);

    switch (mode) {
        case ExecutionMode::Help:
            printHelp();
            return 0;

        case ExecutionMode::Version:
            printVersion();
            return 0;

        case ExecutionMode::Debug: {
            Bootstrap::Bootstrap bootstrap;
            return bootstrap.run(true);
        }

        case ExecutionMode::Normal: {
            Bootstrap::Bootstrap bootstrap;
            return bootstrap.run(false);
        }
    }

    return 1;
}

void Launcher::printHelp() const
{
    std::cout
        << "OxiToolkit\n\n"
        << "Usage:\n"
        << "  oxitoolkit [options]\n\n"
        << "Options:\n"
        << "  --debug       Enable startup diagnostics\n"
        << "  --help, -h    Show this help\n"
        << "  --version, -v Show version\n";
}

void Launcher::printVersion() const
{
    std::cout << "OxiToolkit 0.1.0-dev" << std::endl;
}

}