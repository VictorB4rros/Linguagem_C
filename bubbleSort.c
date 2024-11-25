// Este programa implementa o algoritmo Bubble sort para ordenar um vetor

// Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "ordenacao.h"

// Corpo do programa
int main(void) {
    int n;
    printf ("Determine o tamanho do vetor que deseja ordenar: ");
    scanf ( "%d", &n );
    int vetor [n];
    system ( "cls" );


    printf ("Insira os n%cmeros que ser%co ordenados: \n", 163, 198);
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]=> ", i);
        scanf ("%d", &vetor[i]);
    }

    bubbleSort (vetor, n);
    system ("cls");
    printf ("Vetor ordenado: \n");

    for (int i = 0; i < n; i++) {
        printf (" %d", vetor[i]);
    }

    getch();
    return (0);
}