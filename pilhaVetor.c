// Este programa implementa uma estrutura do tipo pilha utilizando um vetor

// Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// Constantes pré-definidas
#define MAX_STACK_SIZE 100

// Tipos de dados definidos pelo programador
typedef struct Pilha {
    int dados[MAX_STACK_SIZE]; // vetor que será utilizado para a pilha
    int size; // variável que armazena o tamanho do vetor, conforme elementos forem adicionados
} Pilha;

// Funções auxiliares
void inicializar (Pilha *pilha) {
    pilha->size = 0; // inicializa o campo size como 0, pois a pilha está vazia
}

// Função para inserir um elemento na pilha
int inserir (Pilha *pilha, int elemento) {
    if (pilha->size == MAX_STACK_SIZE) {
        printf ("\n Erro: pilha cheia.\n");
        return 0; // Falha na inserção
    }

    pilha->dados[pilha->size] = elemento;
    pilha->size++; // Atualiza o campo size
    return 1; // Sucesso na inserção
}

// Função para remover elementos da pilha
int remover (Pilha *pilha) {
    if (pilha->size == 0) {
        printf ("\n Erro: pilha vazia.\n");
        return 0;
    }

    pilha->size--;
    return 1; // Sucesso na remoção do dado
}

// Exibe os elementos da pilha na tela
void exibir (Pilha *pilha) {
    if (pilha->size == 0) {
        printf ("\n A pilha esta vazia.\n");
        return;
    }
    printf ("\n Elementos da pilha:\n");
    for (int i = pilha->size - 1; i >= 0; i--) {
        printf (" Elemento[%d]: %d\n", i, pilha->dados[i]);
    }
}

// menu do programa
void menu (void) {
    int opcao, elemento, retorno;
    Pilha pilha;

    inicializar (&pilha);
    
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
            printf ("\n  3 - Exibir conteudo da pilha");
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
                    printf ("\n Digite o elemento que deseja inserir na pilha => ");
                    retorno = scanf ("%d", &elemento);
                    if ( retorno != 1) {
                        printf ("Entrada inv%clida! Por favor, tente novamente.", 160);
                        while (getchar() != '\n');
                        getch ();
                    }
                } while (retorno != 1);
                if (inserir (&pilha, elemento)) {
                    printf ("\n Elemento inserido com sucesso!");
                } else 
                    printf ("\n Falha na insercao do elemento.");
                printf ("\n\n Pressione qualquer tecla para continuar...");
                getch();
                break;
            case 2:
                if (remover (&pilha)) {
                    printf ("\n Elemento removido com sucesso!");
                } else
                    printf ("\n Falha na remocao do elemento.");
                printf ("\n\n Pressione qualquer tecla para continuar...");
                getch();
                break;
            case 3: 
                exibir (&pilha);
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