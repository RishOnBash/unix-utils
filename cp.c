#include <stdio.h>

/*
 * copy files from source to destination
 *
 * Author: Rish
 * Date: 15 June, 2026
 * License: MIT
 */

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf ("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }
    FILE *fps = fopen(argv[1], "r");    // fps = source file
    FILE *fpd = fopen(argv[2], "w");    // fpd = destination file

    if (!fps || !fpd) {
        puts ("Error: No such file(s)");
        return 1;
    }

    char buffer [1024];
    while (fgets(buffer, sizeof(buffer), fps)) {
        fprintf (fpd, "%s", buffer);
    }
    // close files 
    fclose(fps);
    fclose(fpd);

    return 0;
}
