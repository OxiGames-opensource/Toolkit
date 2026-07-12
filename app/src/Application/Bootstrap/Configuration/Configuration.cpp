#include "Application/Bootstrap/Configuration/Configuration.hpp"

#include <utility>

namespace OxiToolkit::Application::Bootstrap::Configuration {

Configuration::Configuration(
    const bool debugEnabled,
    std::filesystem::path workingDirectory
)
    : debugEnabled(debugEnabled),
      currentWorkingDirectory(std::move(workingDirectory))
{
}

bool Configuration::isDebugEnabled() const noexcept
{
    return debugEnabled;
}

const std::filesystem::path&
Configuration::workingDirectory() const noexcept
{
    return currentWorkingDirectory;
}

}