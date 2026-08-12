/*
 * rmdir clone - remove empty directories
 *
 * Author: Rish <RishOnBash>
 * Date: August 12, 2026
 * License: MIT
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        dprintf(2, "%s: missing operand\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        if (rmdir(argv[i]) < 0) {
            dprintf(2, "%s: %s: %s\n",
                    argv[0], argv[i], strerror(errno));
            continue;
        }
    }
    return 0;
}
