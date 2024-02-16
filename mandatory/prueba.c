#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#include "pipex.h"

int main()
{
    int fd[2];
    pid_t pid;

    // Creamos una tubería.
    if (pipe(fd) == -1)
    {
        fprintf(stderr, "Error creando la tubería: %s\n", strerror(errno));
        return 1;
    }

    // Creamos el proceso secundario 1.
    pid = fork();
    if (pid == -1)
    {
        printf("Error creando el proceso secundario: %s\n", strerror(errno));
        return 1;
    }
    if (pid == 0)
    {
        // El proceso secundario 1 escribe en la tubería.
        write(fd[1], "Hola, mundo!", 12);
        return 0;
    }

    // Creamos el proceso secundario 2.
    pid = fork();
    if (pid == -1)
    {
        printf("Error creando el proceso secundario: %s\n", strerror(errno));
        return 1;
    }
    if (pid2 == 0)
    {
        // El proceso secundario 2 lee de la tubería.
        char buf[12];
        read(fd[0], buf, 12);
        printf("%s\n", buf);
        return 0;
    }
    wait(NULL);

    return 0;
}