#include "Application/Kernel/Kernel.hpp"

#include <iostream>

namespace OxiToolkit::Application::Kernel {

Kernel::Kernel(bool debug)
    : debug(debug),
      diagnostics(debug),
      runtime()
{
}

int Kernel::run()
{
    std::cout << "OxiToolkit starting..." << std::endl;

    diagnostics.info("Debug mode: enabled");
    diagnostics.ok("Application kernel created");
    diagnostics.ok("Startup diagnostics initialized");

    diagnostics.info("Starting Runtime");

    if (!runtime.start()) {
        diagnostics.fail("Runtime start failed");
        return 1;
    }

    diagnostics.ok("Runtime started");

    std::cout << "OxiToolkit started." << std::endl;

    diagnostics.info("Stopping Runtime");

    if (!runtime.stop()) {
        diagnostics.fail("Runtime stop failed");
        return 1;
    }

    diagnostics.ok("Runtime stopped");

    std::cout << "OxiToolkit stopped." << std::endl;

    return 0;
}

}