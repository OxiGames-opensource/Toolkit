#include "Application/Bootstrap/Bootstrap.hpp"

#include "Application/Kernel/Kernel.hpp"

namespace OxiToolkit::Application::Bootstrap {

int Bootstrap::run(bool debug)
{
    Kernel::Kernel kernel(debug);

    return kernel.run();
}

}