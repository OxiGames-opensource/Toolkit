#include "Runtime/main/Runtime.hpp"

namespace OxiToolkit::Runtime {

Runtime::Runtime()
    : currentStatus(RuntimeStatus::Created)
{
}

bool Runtime::start()
{
    currentStatus = RuntimeStatus::Started;
    return true;
}

bool Runtime::stop()
{
    currentStatus = RuntimeStatus::Stopped;
    return true;
}

RuntimeStatus Runtime::status() const
{
    return currentStatus;
}

}