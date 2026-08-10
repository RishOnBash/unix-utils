/*
 * printenv clone - print all or part of environment
 *
 * Author: Rish <RishOnBash>
 * Date: August 10, 2026
 * License: MIT
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc == 1) {
        extern char **environ;
        while (*environ != NULL) {
            printf("%s\n", *environ);
            environ++;
        }
        exit(EXIT_SUCCESS);
    }

    for (int i = 1; i < argc; i++) {
        char *env = getenv(argv[i]);
        if (env == NULL) continue;
            printf("%s\n", env);
    }

    return 0;
}
