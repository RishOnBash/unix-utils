/*
 * pwd clone
 *
 * Author: Rish <RishOnBash>
 * Date: August 5, 2026
 * License: MIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char buf[4096];
    if (getcwd(buf, sizeof(buf)) != NULL) {
        printf("%s\n", buf);
    } else {
        perror("pwd");
        exit(EXIT_FAILURE);
    }
    return 0;
}
