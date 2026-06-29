#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
 * copy files from source to destination
 *
 * Author: Rish <RishOnBash>
 * Date: 29 June, 2026
 * License: MIT
 */

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf ("Usage: %s <source_file> <destination_file>\n",
                argv[0]);
        return 1;
    }

    int fds = open(argv[1], O_RDONLY);    // fds = source file
    // create destination if does'nt exist, and set permission
    int fdd = open(argv[2], O_RDWR | O_CREAT, 0644);

    if (fds < 0) {
        fprintf (stderr, "%s: source '%s': %s\n",
                argv[0], argv[1], strerror(errno));
        return 11;  // source error
    }

    if (fdd < 0) {
        fprintf (stderr, "%s: destination '%s': %s\n",
                argv[0], argv[2], strerror(errno));
        close(fds);
        return 22;  // destination error
    }

    unsigned char buffer [BUFSIZ];
    ssize_t b_read;  // bytes read
    while ((b_read = read(fds, buffer, BUFSIZ)) > 0)
        write(fdd, buffer, b_read);
        
    close(fds);
    close(fdd);

    return 0;
}
