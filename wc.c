#include <stdio.h>
#include <string.h>

/*
 * wc clone, options are hardcoded as of now 
 * so ./wc <file> won't work, it need option
 * will fix that later, as i get better in C
 *
 * Author: Rish
 * Date: 22 June, 2026
 * License: MIT
 */

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf ("Usage: %s [ -c | -l | -w ] <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[2], "r");     //argv[2] = file
    if (!fp) {
        printf ("%s: no such file\n", argv[2]); return 1;
    }

    // get character count
    if (strcmp(argv[1], "-c") == 0) {   //argv[1] = flag
        int c, count = 0;
        while ((c = fgetc(fp)) != EOF) 
            count++;
        printf ("%i %s\n", count, argv[2]);
    }
        
    // get line count
    else if (strcmp(argv[1], "-l") == 0) {
        char buffer [1024];
        int count = 0;
        while (fgets(buffer, sizeof(buffer), fp)) {
            if (strchr(buffer, '\n'))
                count ++;
        }
        printf ("%i %s\n", count, argv[2]);
    } 

    // get word count
    else if (strcmp(argv[1], "-w") == 0) {
        char buffer [255];  // how big a word can go, idk!?
        int c, count = 0;
        // no bounded check, it returns incorrect word count
        while ((c = fscanf(fp, "%s", buffer)) != EOF)
            count++;
        printf ("%i %s\n", count, argv[2]);
    }
    
    else {
        printf ("Usage: %s [ -c | -l | -w ] <file>\n", argv[0]);
        return 1;
    }
    
    fclose(fp);
    return 0;
}
