
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char** argv)
{
	int fd;
    char *run;

    printf("El tamaño del BUFFER_SIZE ES:    --  %d   --\n", BUFFER_SIZE);
    printf("-----------------------------------------------\n");
    printf ("----INICIO DEL CONTENIDO DEL ARCHIVO----------\n");    
    run = "1";
	fd = open ( "fichero.txt", O_RDONLY);        
	    if (fd == -1)
        {
            printf ("File error\n");
        }
        else
        {
           while (run)
            {
               run = get_next_line(fd);
               if (run)
                printf("%s",run);
            }           
            close (fd);
        }
	return 0;
}

