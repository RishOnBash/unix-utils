#include <stdio.h>

/*
 * touch command clone
 *
 * Author: Rish
 * Date: 15 June, 2026
 * License: MIT
 */

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
