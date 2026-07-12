#include "Application/Bootstrap/Bootstrap.hpp"

#include "Application/Bootstrap/Environment/Environment.hpp"
#include "Application/Bootstrap/StartupDiagnostics.hpp"
#include "Application/Kernel/Kernel.hpp"

#include <string>

namespace OxiToolkit::Application::Bootstrap {

int Bootstrap::run(const bool debug)
{
    StartupDiagnostics diagnostics(debug);
    Environment::Environment environment;

    const Environment::OperatingSystem operatingSystem =
        environment.detectOperatingSystem();

    diagnostics.info(
        "Operating system detected: "
        + std::string(Environment::Environment::operatingSystemName(operatingSystem))
    );

    if (operatingSystem == Environment::OperatingSystem::Unknown) {
        diagnostics.warn("Current operating system is not supported");
    } else {
        diagnostics.ok("Execution environment detected");
    }

    Kernel::Kernel kernel(debug);

    return kernel.run();
}

}