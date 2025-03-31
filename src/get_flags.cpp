#include "./flags.h"
#include <cstring>
#include <string>
#include <unordered_map>

int get_flags(char* args[], int size) {
    int flags = 0;

    static const std::unordered_map<std::string, int> flag_map = {
        {"--help", FLAG_HELP},
        {"-h", FLAG_HELP},
        {"--cli", FLAG_CLI},
        {"-c", FLAG_CLI},
        {"--output", FLAG_OUTPUT},
        {"-o", FLAG_OUTPUT},
        {"--version", FLAG_VERSION},
        {"-v", FLAG_VERSION},
    };

    for (int i = 0; i < size; i++) {
        auto it = flag_map.find(args[i]);
        if (it != flag_map.end()) {
            if (it->second == FLAG_OUTPUT) {
                if (flags & FLAG_OUTPUT)
                    flags |= FLAG_OUTPUT_REPEATED;
            }
            flags |= it->second;
        } else {
            if (args[i][0] == '-')
                flags |= FLAG_INVALID_FLAG;
        }
    }

    return flags;
}
