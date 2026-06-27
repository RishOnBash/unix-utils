#include <stdio.h>
#include <errno.h>

/* 
 * display file contents to STDOUT
 *
 * Author: Rish <RishOnBash>
 * Date: 27 June, 2026
 * License: MIT
 */

int main(int argc, char *argv[]) {
    if (argc < 2)
        fprintf (stderr, "Usage: %s FILE ...\n", argv[0]);

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "rb");
        if (!fp) {
        fprintf (stderr, "%s: %s: %s\n", argv[0],argv[i], strerror(errno));
        continue;
        }

        unsigned char buffer [4096];
        size_t b_read;   // bytes read
        while ((b_read = fread(buffer, 1, sizeof(buffer), fp)) > 0)
            fwrite(buffer, 1, b_read, stdout);

    fclose(fp);
    }

    return 0;
}
