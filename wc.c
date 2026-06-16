#include <stdio.h>
#include <string.h>

/*
 * wc clone, supports 2 options as of now
 * -c (character count) and -l (line count)
 * options are hardcoded so wc file won't work
 * will fix that later, as i get better in C
 *
 * Author: Rish
 * Date: 16 June, 2026
 * License: MIT
 */

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf ("Usage: %s [-c | -l] <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[2], "r");     //argv[2] = file
    if (!fp) {
        printf ("%s: no such file\n", argv[2]);
        return 1;
    }

    // get character count
    if (strcmp(argv[1], "-c") == 0) {   //argv[1] = flag
        int c, count = 0;
        while ((c = fgetc(fp)) != EOF) {
            count++;
        }
        printf ("Total characters: %i\n", count);
    }
        
    // get line count
    else if (strcmp(argv[1], "-l") == 0) {
        char buffer [1024];
        int count = 0;
        while (fgets(buffer, sizeof(buffer), fp)) {
            if (strchr(buffer, '\n'))
                count ++;
        }
        printf ("Total lines: %i\n", count);
    } else {
        printf ("Usage: %s [ -c | -l ] <file>\n", argv[0]);
        return 1;
    }
    
    fclose(fp);
    return 0;
}
