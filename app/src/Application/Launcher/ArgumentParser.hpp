#pragma once

#include "Application/Launcher/ExecutionMode.hpp"

namespace OxiToolkit::Application::Launcher {

class ArgumentParser
{
public:
    ExecutionMode parse(int argc, char* argv[]) const;
};

}