// Este programa implementa o algoritmo merge sort para ordenar um vetor

// Bibliotecas
#include <stdio.h>
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
            printf ("Entrada inválida! Por favor, tente novamente.");
            while (getchar() != '\n');
        }    
    } while ( retorno != 1 );

    int * vetor = (int *) malloc (n * sizeof(int));
    if (vetor == NULL) {
        printf ("Erro ao alocar memória!!!\n");
        return (1);
    }

    #ifdef _WIN32
        system ("cls");
    #else
        system ("clear");
    #endif


    printf ("Insira os números que serão ordenados: \n");
    for (int i = 0; i < n; i++) {
        do {
            printf("Elemento [%d]=> ", i);
            retorno = scanf ("%d", &vetor[i]);
            if ( retorno != 1) {
                printf ("Entrada inválida! Por favor, tente novamente.");
                while (getchar() != '\n');
            }    
        } while ( retorno != 1 );
    }

    mergeSort (vetor, 0, n-1);
    system ("cls");
    printf ("Vetor ordenado: \n");

    for (int i = 0; i < n; i++) {
        printf (" %d", vetor[i]);
    }

    getchar();
    free (vetor);
    return (0);
}