#include <stdio.h>

/* 
 * display file contents to STDOUT
 *
 * Author: Rish
 * Date: 15 June, 2026
 * License: MIT
 */

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf ("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf ("%s: %s: No such file\n", argv[0],argv[1]);
        return 1;
    }
    char buffer [255];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf ("%s", buffer);
    }
    fclose(fp);
    return 0;
}
