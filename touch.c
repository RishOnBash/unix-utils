/*
 * touch clone
 *
 * Author: Rish
 * Date: August 5, 2026
 * License: MIT
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf ("%s: missing file operand\n", argv[0]);
        return 1;
    }

    // parse through all the arguments
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "a");
        if (!fp) {
            printf ("%s: can't touch this!\n", argv[i]);
            continue;
        }

        fclose(fp);
    }

    return 0;
}
