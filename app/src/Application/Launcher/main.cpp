#include "Application/Launcher/Launcher.hpp"

int main(int argc, char* argv[])
{
    OxiToolkit::Application::Launcher::Launcher launcher;

    return launcher.run(argc, argv);
}