// Este programa implementa uma estrutura do tipo lista utilizando um vetor

// Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// Constantes pré-definidas
#define MAX_SIZE 100

// Tipos de dados definidos pelo programador
typedef struct Lista {
    int dados[MAX_SIZE]; // vetor que será utilizado para a lista
    int size; // variável que armazena o tamanho do vetor, conforme elementos forem adicionados
} Lista;

// Funções auxiliares
void inicializar (Lista *lista) {
    lista->size = 0; // inicializa o campo size como 0, pois a lista está vazia
}

// Função para inserir um elemento dentro de um índice do vetor/lista
int inserir (Lista *lista, int elemento, int indice) {
    if (lista->size == MAX_SIZE) {
        printf ("\n Erro. A lista esta cheia.\n");
        return 0; // Falha na inserção
    }

    if (indice < 0 || indice > lista->size) {
        printf ("\n Erro. Indice invalido.\n");
        return 0; // Falha na inserção
    }

    // Desloca os elementos para abrir espaço
    for (int i = lista->size; i > indice; i--) {
        lista->dados[i] = lista->dados[i - 1];
    }

    lista->dados[indice] = elemento;
    lista->size++; // Atualiza o campo size
    return 1; // Sucesso na inserção
}

// Função para remover elementos da lista
int remover (Lista *lista, int indice) {
    if (lista->size == 0) {
        printf ("\n A lista esta vazia.\n");
        return 0;
    }

    if (indice < 0 || indice >= lista->size) {
        printf ("\n Erro. Indice invalido.\n");
        return 0; // Falha na remoção do dado
    }

    for (int i = indice; i < lista->size - 1; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }
    lista->size--;
    return 1; // Sucesso na remoção do dado
}

// Exibe os elementos da lista na tela
void exibir (Lista *lista) {
    if (lista->size == 0) {
        printf ("\n A lista esta vazia.\n");
        return;
    }
    printf ("\n Elementos da lista:\n");
    for (int i = 0; i < lista->size; i++) {
        printf (" Elemento[%d]: %d\n", i, lista->dados[i]);
    }
}

// menu do programa
void menu (void) {
    int opcao, elemento, indice;
    Lista lista;

    inicializar (&lista);
    
    do {
        #ifdef _WIN32
            system ("cls");
        #else
            system ("clear");
        #endif

        printf ("\n Menu de opcoes: \n");
        printf ("\n  1 - Inserir dados");
        printf ("\n  2 - Remover dados");
        printf ("\n  3 - Exibir conteudo da lista");
        printf ("\n  4 - Sair do programa\n");
        printf ("\n  Opcao desejada => ");
        scanf ("%d", &opcao);

        #ifdef _WIN32
            system ("cls");
        #else
            system ("clear");
        #endif

        switch (opcao) {
            case 1: 
                printf ("\n Digite o elemento que deseja inserir na lista => ");
                scanf ("%d", &elemento);
                printf ("\n Digite o indice em que deseja inserir o novo elemento => ");
                scanf ("%d", &indice);
                if (inserir (&lista, elemento, indice)) {
                    printf ("\n Elemento inserido com sucesso!");
                } else 
                    printf ("\n Falha na insercao do elemento.");
                printf ("\n\n Pressione qualquer tecla para continuar...");
                getch();
                break;
            case 2:
                printf ("\n Digite o indice do elemento que deseja remover => ");
                scanf ("%d", &indice);
                if (remover (&lista, indice)) {
                    printf ("\n Elemento removido com sucesso!");
                } else
                    printf ("\n Falha na remocao do elemento.");
                printf ("\n\n Pressione qualquer tecla para continuar...");
                getch();
                break;
            case 3: 
                exibir (&lista);
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