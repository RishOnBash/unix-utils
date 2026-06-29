#include <stdio.h>

/*
 * Repeatedly output a line with specified STRING, or 'y'
 *
 * Author: Rish <RishOnBash>
 * Date: 29 June, 2026
 * License: MIT
 */

int main(int argc, char *argv[]) {
    if (argc == 1)
        while (1)
            puts("y");
    else
        while (1)
            printf("%s\n", argv[1]);
    return 0;
}
