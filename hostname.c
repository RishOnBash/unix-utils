/* 
 * hostname clone - get hostname
 *
 * Author: Rish <RishOnBash>
 * Date: August 11, 2026
 * License: MIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main(void) {
    struct utsname buf;
    if (uname(&buf) < 0) {
        perror("uname(2)");
        exit(EXIT_FAILURE);
    }
    
    printf("%s\n", buf.nodename);
    return 0;
}
