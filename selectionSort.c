// Este programa implementa o algoritmo Selection Sort para ordenar um vetor

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ordenacao.h"

// Corpo do programa
int main(void) {
    int n, retorno;
    do {
        #ifdef _WIN32
            system ("cls");
        #else
            system ("clear");
        #endif
        printf ("Determine o tamanho do vetor que deseja ordenar: ");
        retorno = scanf ( "%d", &n );
        if ( retorno != 1) {
            printf ("Entrada inv%clida! Por favor, tente novamente.", 160);
            while (getchar() != '\n');
            getch();
        }    
    } while ( retorno != 1 );

    int * vetor = (int *) malloc (n * sizeof(int));
    if (vetor == NULL) {
        printf ("Erro ao alocar mem%cria!!!\n", 162);
        return (1);
    }

    #ifdef _WIN32
        system ("cls");
    #else
        system ("clear");
    #endif

    printf ("Insira os n%cmeros que ser%co ordenados: \n", 163, 198);
    for (int i = 0; i < n; i++) {
        do {
            printf("Elemento [%d]=> ", i);
            retorno = scanf ("%d", &vetor[i]);
            if ( retorno != 1) {
                printf ("Entrada inv%clida! Por favor, tente novamente.", 160);
                while (getchar() != '\n');
                getch ();
            }    
        } while ( retorno != 1 );
    }

    selectionSort (vetor, n);

    #ifdef _WIN32
        system ("cls");
    #else
        system ("clear");
    #endif

    printf("Vetor ordenado: \n");

    for (int i = 0; i < n; i++) {
        printf (" %d", vetor[i]);
    }

    free (vetor);
    vetor = NULL;

    getch();
    return (0);
}