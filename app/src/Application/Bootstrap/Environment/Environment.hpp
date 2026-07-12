#pragma once

#include "Application/Bootstrap/Environment/OperatingSystem.hpp"

#include <string_view>

namespace OxiToolkit::Application::Bootstrap::Environment {

class Environment
{
public:
    [[nodiscard]] OperatingSystem detectOperatingSystem() const noexcept;

    [[nodiscard]] static std::string_view operatingSystemName(
        OperatingSystem operatingSystem
    ) noexcept;
};

}