#include <errno.h>
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
        fprintf (stderr, "Usage: %s [ -c | -l | -w ] FILE ...\n", argv[0]);
        //return 1;
    }

    for (int i=2; i<argc; i++) {    // loop through files
        FILE *fp = fopen(argv[i], "r");
        if (!fp) {
        fprintf (stderr, "%s: %s\n", argv[i], strerror(errno));
        return 1;
        }

        // get character count
        if (strcmp(argv[1], "-c") == 0) {
            int c, count = 0;
            while ((c = fgetc(fp)) != EOF) 
                count++;
            printf ("%5i %s\n", count, argv[i]);
        }
         
        // get line count
        else if (strcmp(argv[1], "-l") == 0) {
            char buffer [1024];
            int count = 0;
            while (fgets(buffer, sizeof(buffer), fp)) {
                if (strchr(buffer, '\n'))
                    count ++;
            }
            printf ("%5i %s\n", count, argv[i]);
        } 

        // get word count
        else if (strcmp(argv[1], "-w") == 0) {
            char buffer [255];  // how big a word can go, idk!?
            int c, count = 0;
            // no bounded check, it returns incorrect word count
            while ((c = fscanf(fp, "%s", buffer)) != EOF)
                count++;
            printf ("%5i %s\n", count, argv[i]);
        }
    
        else
            fprintf (stderr, "Usage: %s [ -c | -l | -w ] FILE ...\n", argv[0]);
    
        fclose(fp);
    }
    return 0;
}
