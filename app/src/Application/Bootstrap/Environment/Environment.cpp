#include "Application/Bootstrap/Environment/Environment.hpp"

namespace OxiToolkit::Application::Bootstrap::Environment {

OperatingSystem Environment::detectOperatingSystem() const noexcept
{
#if defined(_WIN32)
    return OperatingSystem::Windows;
#elif defined(__APPLE__) && defined(__MACH__)
    return OperatingSystem::MacOS;
#elif defined(__linux__)
    return OperatingSystem::Linux;
#else
    return OperatingSystem::Unknown;
#endif
}

std::string_view Environment::operatingSystemName(
    const OperatingSystem operatingSystem
) noexcept
{
    switch (operatingSystem) {
        case OperatingSystem::Linux:
            return "Linux";

        case OperatingSystem::Windows:
            return "Windows";

        case OperatingSystem::MacOS:
            return "macOS";

        case OperatingSystem::Unknown:
            return "Unknown";
    }

    return "Unknown";
}

}