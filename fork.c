#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main () {
    printf ("Chamando o processo filho...\n");
    pid_t pid = fork();

    if (pid < 0) {
        perror ("Falha no fork.");
        exit (1);
    }

    if (pid == 0) {
        char *args[] = {"./exec", NULL};
        execvp (args[0], args);

        perror ("Falha ao executar execvp.");
        exit (1);
    }

    return 0;
}