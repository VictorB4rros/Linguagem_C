// Este programa implementa uma estrutura do tipo fila utilizando um vetor

// Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// Constantes pré-definidas
#define MAX_QUEUE_SIZE 100

// Tipos de dados definidos pelo programador
typedef struct Fila {
    int dados[MAX_QUEUE_SIZE]; // vetor que será utilizado para a fila
    int size; // variável que armazena o tamanho do vetor, conforme elementos forem adicionados
} Fila;

// Funções auxiliares
void inicializar (Fila *fila) {
    fila->size = 0; // inicializa o campo size como 0, pois a fila está vazia
}

// Função para inserir um elemento na fila
int inserir (Fila *fila, int elemento) {
    if (fila->size == MAX_QUEUE_SIZE) {
        printf ("\n Erro: fila cheia.\n");
        return 0; // Falha na inserção
    }

    fila->dados[fila->size] = elemento;
    fila->size++; // Atualiza o campo size
    return 1; // Sucesso na inserção
}

// Função para remover elementos da fila
int remover (Fila *fila) {
    if (fila->size == 0) {
        printf ("\n Erro: fila vazia.\n");
        return 0;
    }

    for (int i = 0; i < fila->size; i++) {
        fila->dados[i] = fila->dados[i + 1];
    }

    fila->size--;
    return 1; // Sucesso na remoção do dado
}

// Exibe os elementos da fila na tela
void exibir (Fila *fila) {
    if (fila->size == 0) {
        printf ("\n A fila esta vazia.\n");
        return;
    }
    printf ("\n Elementos da fila:\n");
    for (int i = 0; i < fila->size; i++) {
        printf (" Elemento[%d]: %d\n", i, fila->dados[i]);
    }
}

// menu do programa
void menu (void) {
    int opcao, elemento, retorno;
    Fila fila;

    inicializar (&fila);
    
    do {
        #ifdef _WIN32
            system ("cls");
        #else
            system ("clear");
        #endif
        
        do {
            printf ("\n Menu de opcoes: \n");
            printf ("\n  1 - Inserir dados");
            printf ("\n  2 - Remover dados");
            printf ("\n  3 - Exibir conteudo da fila");
            printf ("\n  4 - Sair do programa\n");
            printf ("\n  Opcao desejada => ");
            retorno = scanf ("%d", &opcao);
            if ( retorno != 1) {
                printf ("Entrada inv%clida! Por favor, tente novamente.", 160);
                while (getchar() != '\n');
                getch ();
            }
        } while ( retorno != 1 );

        #ifdef _WIN32
            system ("cls");
        #else
            system ("clear");
        #endif

        switch (opcao) {
            case 1: 
                do {
                    printf ("\n Digite o elemento que deseja inserir na fila => ");
                    retorno = scanf ("%d", &elemento);
                    if ( retorno != 1) {
                        printf ("Entrada inv%clida! Por favor, tente novamente.", 160);
                        while (getchar() != '\n');
                        getch ();
                    }
                } while (retorno != 1);
                if (inserir (&fila, elemento)) {
                    printf ("\n Elemento inserido com sucesso!");
                } else 
                    printf ("\n Falha na insercao do elemento.");
                printf ("\n\n Pressione qualquer tecla para continuar...");
                getch();
                break;
            case 2:
                if (remover (&fila)) {
                    printf ("\n Elemento removido com sucesso!");
                } else
                    printf ("\n Falha na remocao do elemento.");
                printf ("\n\n Pressione qualquer tecla para continuar...");
                getch();
                break;
            case 3: 
                exibir (&fila);
                printf ("\n\n Pressione qualquer tecla para continuar...");
                getch();
                break;
            case 4:
                printf ("\n Encerrando...");
                getch();
                break;
            default:
                printf ("\n Opcao invalida. Tente novamente.");
                printf ("\n\n Pressione qualquer tecla para continuar...");
                getch();
                break;
        }
    } while (opcao != 4);
}

// Corpo do programa
int main (void) {
    menu ();
    return 0;
}