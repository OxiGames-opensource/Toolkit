#pragma once

#include <string>

namespace OxiToolkit::Application::Bootstrap {

class StartupDiagnostics
{
public:
    explicit StartupDiagnostics(bool enabled);

    void info(const std::string& message) const;
    void ok(const std::string& message) const;
    void warn(const std::string& message) const;
    void fail(const std::string& message) const;

    bool isEnabled() const;

private:
    bool enabled;
};

}