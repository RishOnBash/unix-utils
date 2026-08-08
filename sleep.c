/* 
 * sleep clone
 *
 * Author: Rish <RishOnBash>
 * Date: August 8, 2026
 * License: MIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        dprintf(2, "%s: missing operand\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    unsigned int secs = (unsigned int)atoi(argv[1]);
    sleep(secs);

    return 0;
}
