#include <errno.h>
#include <stdio.h>

/*
 * copy files from source to destination
 *
 * Author: Rish
 * Date: 27 June, 2026
 * License: MIT
 */

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf ("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }
    FILE *fps = fopen(argv[1], "rb");    // fps = source file
    FILE *fpd = fopen(argv[2], "wb");    // fpd = destination file

    if (!fps) {
        fprintf (stderr, "%s: source '%s': %s\n", argv[0], argv[1], strerror(errno));
        return 11;  // source error
    }

    if (!fpd) {
        fprintf (stderr, "%s: destination '%s': %s\n", argv[0], argv[2], strerror(errno));
        fclose(fps);
        return 22;  // destination error
    }

    unsigned char buffer [4096];
    size_t _read;
    while ((_read = fread(buffer, 1, sizeof(buffer), fps)) > 0)
        fwrite(buffer, 1, _read, fpd);
        
    fclose(fps);
    fclose(fpd);

    return 0;
}
