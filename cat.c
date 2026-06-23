#include <stdio.h>
#include <errno.h>

/* 
 * display file contents to STDOUT
 *
 * Author: Rish <RishOnBash>
 * Date: 23 June, 2026
 * License: MIT
 */

int main(int argc, char *argv[]) {
    if (argc < 2)
        fprintf (stderr, "Usage: %s FILE ...\n", argv[0]);

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (!fp) {
        fprintf (stderr, "%s: %s: %s\n", argv[0],argv[i], strerror(errno));
        continue;
        }
        char buffer [1024];
        while (fgets(buffer, sizeof(buffer), fp)) {
            printf ("%s", buffer);
        }
    fclose(fp);
    }
    return 0;
}
