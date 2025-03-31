#include "./flags.h"
#include <cstring>

int get_flags(char * args[], int size) {
    int flags = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(args[i], "--help") == 0 || strcmp(args[i], "-h") == 0) {
            flags |= FLAG_HELP;
        } else if (strcmp(args[i], "--cli") == 0 || strcmp(args[i], "-c") == 0) {
            flags |= FLAG_CLI;
        } else if (strcmp(args[i], "-o") == 0 || strcmp(args[i], "--output") == 0) {
            if (flags & FLAG_OUTPUT) {
                flags |= FLAG_OUTPUT_REPEATED;
            }
            flags |= FLAG_OUTPUT;
        } else if (strcmp(args[i], "-v") == 0 || strcmp(args[i], "--version") == 0) {
            flags |= FLAG_VERSION;
        } else {
            if (args[i][0] == '-'){
                flags |= FLAG_INVALID_FLAG;
            }
        }
    }
    return flags;
}