#pragma once

#include <filesystem>
#include <string_view>

namespace OxiToolkit::Application::Bootstrap::Configuration {

class Configuration
{
public:
    Configuration(
        bool debugEnabled,
        std::filesystem::path workingDirectory
    );

    [[nodiscard]] bool isDebugEnabled() const noexcept;

    [[nodiscard]] const std::filesystem::path&
    workingDirectory() const noexcept;

    [[nodiscard]] static constexpr std::string_view version() noexcept
    {
        return "0.1.0-dev";
    }

private:
    bool debugEnabled;
    std::filesystem::path currentWorkingDirectory;
};

}