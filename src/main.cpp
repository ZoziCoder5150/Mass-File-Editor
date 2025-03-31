#include <iostream>
#include "./flags.h"
#include "./version.h"
#include "get_flags.cpp"

int main(int argc, char * argv[]) {
    if (argc <= 1) {
        std::cout << "Type Flag --help or -h to view help information\n";
        return 0;
    }

    int flags = get_flags(argv, argc);
    std::cout << flags << "\n";

    if (flags & FLAG_INVALID_FLAG) {
        std::cout << "Error: Invalid flag\n";
        return 1;
    }

    if (flags & FLAG_HELP) {
        std::cout << "flags:\n";
        std::cout << "-h  --help     Display Help information then exit\n";
        std::cout << "-o  --output   Output file\n";
        std::cout << "-c  --cli      Activate CLI mode\n";
        std::cout << "-v  --version  Display Version then exit\n";
        return 0;
    }
    if (flags & FLAG_VERSION) {
        std::cout << "Version " << VERSION << " Build number " << BUILDNUM;
    }

    if (flags & FLAG_OUTPUT_REPEATED) {
        std::cout << "Error: More than 1 output\n";
    }

    if (flags & FLAG_OUTPUT && !(flags & FLAG_OUTPUT_REPEATED)) {
        std::cout << "TODO: make output and everything else\n";
    }

    if (flags & FLAG_CLI) {
        std::cout << "TODO: make cli\n";
    }

    return 0;
}