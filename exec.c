#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
    printf ("Eu sou o processo filho chamado por syscall.\n");

    exit (0);
}