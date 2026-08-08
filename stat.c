/*
 * stat clone - display file system status
 *
 * Author: Rish <RishOnBash>
 * Date: August 8, 2026
 * License: MIT
 */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#define T_FMT "%F %T"

int main(int argc, char **argv) {
    if (argc < 2) {
        dprintf(2, "Usage: %s FILE ...\n", argv[0]);
        return 1;
    }

    char T_STR[20];
    struct stat buf;

    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &buf) < 0) {
            dprintf(2, "%s: %s: %s\n",
                    argv[0], argv[i], strerror(errno));
        return -1;
        }

        printf("    File: %s\n", argv[i]);
        printf("-----------------------------\n");
        printf("    Type: ");

        switch (buf.st_mode & S_IFMT) {
            case S_IFBLK:  printf("block device\n");    break;
            case S_IFCHR:  printf("character device\n");break;
            case S_IFDIR:  printf("directory\n");       break;
            case S_IFIFO:  printf("FIFO/pipe\n");       break;
            case S_IFLNK:  printf("symlink\n");         break;
            case S_IFREG:  printf("regular file\n");    break;
            case S_IFSOCK: printf("socket\n");          break;
            default:       printf("unknown?\n");        break;
        }

        printf("    Size: %ld bytes\n", buf.st_size);
        printf("    Mode: %o\n", buf.st_mode);
        printf("   Inode: %lu\n", buf.st_ino);
        printf(" User ID: %d\n", buf.st_uid);
        printf("Group ID: %d\n", buf.st_gid);
        printf("IO Block: %d\n", buf.st_blksize);
        if (strftime(T_STR, sizeof(T_STR), T_FMT, localtime(&buf.st_atime)))
            printf("  Access: %s\n", T_STR);
        if (strftime(T_STR, sizeof(T_STR), T_FMT, localtime(&buf.st_ctime)))
            printf("  Change: %s\n", T_STR);
        if (strftime(T_STR, sizeof(T_STR), T_FMT, localtime(&buf.st_mtime)))
            printf("  Modify: %s\n\n", T_STR);
    }
    return 0;
}
