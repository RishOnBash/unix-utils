/*
 * yes clone
 * Repeatedly output a line with specified STRING, or 'y'
 *
 * Author: Rish <RishOnBash>
 * Date: August 5, 2026
 * License: MIT
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc == 1)
        while (1)
            puts("y");
    else
        while (1)
            printf("%s\n", argv[1]);
    return 0;
}
