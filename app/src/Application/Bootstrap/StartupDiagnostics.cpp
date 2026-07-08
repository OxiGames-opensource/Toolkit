#include "Application/Bootstrap/StartupDiagnostics.hpp"

#include <iostream>

namespace OxiToolkit::Application::Bootstrap {

StartupDiagnostics::StartupDiagnostics(bool enabled)
    : enabled(enabled)
{
}

void StartupDiagnostics::info(const std::string& message) const
{
    if (enabled) {
        std::cout << "[INFO] " << message << std::endl;
    }
}

void StartupDiagnostics::ok(const std::string& message) const
{
    if (enabled) {
        std::cout << "[ OK ] " << message << std::endl;
    }
}

void StartupDiagnostics::warn(const std::string& message) const
{
    if (enabled) {
        std::cout << "[WARN] " << message << std::endl;
    }
}

void StartupDiagnostics::fail(const std::string& message) const
{
    if (enabled) {
        std::cout << "[FAIL] " << message << std::endl;
    }
}

bool StartupDiagnostics::isEnabled() const
{
    return enabled;
}

}