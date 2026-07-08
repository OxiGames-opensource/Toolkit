#include "Application/Kernel/Kernel.hpp"

#include <string>

int main(int argc, char* argv[])
{
    bool debug = false;

    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--debug") {
            debug = true;
        }
    }

    OxiToolkit::Application::Kernel::Kernel kernel(debug);

    return kernel.run();
}