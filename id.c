/* 
 * id clone - get real user and group ID 
 *
 * Author: Rish <RishOnBash>
 * Date: August 9, 2026
 * License: MIT
 */

#include <pwd.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    struct passwd *pwd = getpwuid(getuid());
    if (!pwd) return 1;

    printf("   Username: %s\n", pwd->pw_name);
    printf("    User ID: %u\n", pwd->pw_uid);
    printf("   Group ID: %u\n", pwd->pw_gid);
    printf("  User info: %s\n", pwd->pw_gecos);
    printf("   Home dir: %s\n", pwd->pw_dir);
    printf("Login shell: %s\n", pwd->pw_shell);

    return 0;
}
