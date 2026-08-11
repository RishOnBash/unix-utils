/*
 * uname clone - print system information
 *
 * Author: Rish <RishOnBash>
 * Date: August 11, 2026
 * License: MIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>

void usage(void) {
    dprintf(2, 
            "Usage: uname [OPTION]...\n"
            "Print certain system information. With no OPTION, same as -s.\n\n"
            "   -a   print all information, in the following order,\n"
            "   -s   print the kernel name\n"
            "   -n   print the network node hostname\n"
            "   -r   print the kernel release\n"
            "   -v   print the kernel version\n"
            "   -m   print the machine hardware name\n"
            "   -h   display this help and exit\n"
            );
}

int main(int argc, char **argv) {
    struct utsname buf;

    if (uname(&buf) < 0) {
        perror("uname(2)");
        exit(EXIT_FAILURE);
    }

    int sysname = 0;
    int nodename = 0;
    int release = 0;
    int version = 0;
    int machine = 0;

    if (argc == 1) sysname = 1;

    int opt;
    while ((opt = getopt(argc, argv, "asnrvmh")) != -1) {
        switch(opt) {
            case 'a':
                sysname = 1;
                nodename = 1;
                release = 1;
                version = 1;
                machine = 1;
                break;
            case 's':
                sysname = 1;
                break;
            case 'n':
                nodename = 1;
                break;
            case 'r':
                release = 1;
                break;
            case 'v':
                version = 1;
                break;
            case 'm':
                machine = 1;
                break;
            case 'h':
                usage();
                exit(EXIT_SUCCESS);
            default:
                usage();
                exit(EXIT_FAILURE);
        }
    }

	if (sysname) printf("%s\n", buf.sysname);
	if (nodename) printf("%s\n", buf.nodename);
	if (release) printf("%s\n", buf.release);
	if (version) printf("%s\n", buf.version);
	if (machine) printf("%s\n", buf.machine);

	return 0;
}
