/*
 * whoami clone - print effective user name
 *
 * Author: Rish <RishOnBash>
 * Date: August 11, 2026
 * License: MIT
 */

#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    struct passwd *pwd = getpwuid(getuid());
    if (!pwd) {
        perror("getpwuid");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", pwd->pw_name);
    return 0;
}
