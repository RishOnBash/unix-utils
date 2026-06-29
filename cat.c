#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* 
 * display file contents to STDOUT
 *
 * Author: Rish <RishOnBash>
 * Date: 29 June, 2026
 * License: MIT
 */

int main(int argc, char *argv[]) {
    ssize_t b_read;     //bytes read
    unsigned char buf[BUFSIZ];

    if (argc > 1) {
        for (int i=1; i<argc; i++) {
            int fd = open(argv[i], O_RDONLY);
            if (fd < 0) {
                fprintf (stderr, "%s: %s: %s\n",
                        argv[0], argv[i], strerror(errno));
                continue;
            }
            while ((b_read = read(fd, buf, BUFSIZ)) > 0)
                write(1, buf, b_read);
            close(fd);
        }

    // read from STDIN
    } else
        while ((b_read = read(0, buf, BUFSIZ)) > 0)
            write(1, buf, b_read);
    return 0;
}
