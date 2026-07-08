#pragma once

namespace OxiToolkit::Runtime {

enum class RuntimeStatus
{
    Created,
    Started,
    Stopped,
    Failed
};

class Runtime
{
public:
    Runtime();

    bool start();
    bool stop();

    RuntimeStatus status() const;

private:
    RuntimeStatus currentStatus;
};

}