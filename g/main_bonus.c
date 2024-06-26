
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


/*
int main(int argc, char** argv)
{
	int fd[FOPEN_MAX];
    int i;
    int j;
    int more_lines;
     char *line1, *line2;

    i = 2;
    j = 0;
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    fd[0] = open(argv[1], O_RDONLY);
    fd[1] = open(argv[2], O_RDONLY);

    if (fd[0] < 0 || fd[1] < 0) {
        perror("open");
        return 1;
    }

more_lines = 1;
while (more_lines) {
        more_lines = 0;

        line1 = get_next_line(fd[0]);
        if (line1) {
            printf("%s", line1);
            free(line1);
            more_lines = 1;
        }
        printf ("**\n");
        if (line2) {
            printf("%s---", line2);
            free(line2);
            more_lines = 1;
        }
    }

	return 0;
}

*/


int  main(int argc, char **argv)
{
    int     fd[1024];
    int     i;
    char    *test_str;
    if (argc < 3)
    {
        write(1, "Wrong argument count: Must be al least 3.\n", 41);
        return (1);
    }
    test_str = NULL;
    i = 1;
    while (i < argc)
    {
        fd[i] = open(argv[i], O_RDONLY);
        if (fd[i] == -1)
        {
            write (1, "Error: Could not open file\n", 27);
            return (1);
        }
        i++;
    }
    i = 1;
    while ((test_str = get_next_line(fd[i])))
    {
        printf("%i -> %s", i, test_str);
        free(test_str);
        i++;
        if (i == argc)
            i = 1;
    }
    while (1 < argc)
    {
        close(fd[argc - 1]);
        argc--;
    }
    return (0);
}