#pragma once

#include "Application/Bootstrap/StartupDiagnostics.hpp"
#include "Runtime/main/Runtime.hpp"

namespace OxiToolkit::Application::Kernel {

class Kernel
{
public:
    explicit Kernel(bool debug);

    int run();

private:
    bool debug;
    Bootstrap::StartupDiagnostics diagnostics;
    Runtime::Runtime runtime;
};

}