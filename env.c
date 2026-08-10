/*
 * env clone
 *
 * Author: Rish <RishOnBash>
 * Date: August 10, 2026
 * License: MIT
 */

#include <stdio.h>

int main(void) {
    extern char **environ;
    while (*environ != NULL) {
        printf("%s\n", *environ);
        environ++;
    }
    return 0;
}
