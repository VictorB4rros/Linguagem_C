// Este programa implementa uma lista encadeada simples

// Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// Tipos de dados definidos pelo programador
typedef struct celula {
    int dado;                   // Valor da célula
    struct celula *proximo;     // Ponteiro para a próxima célula
} Celula;

// Função para inserir um dado no início da estrutura
int inserirInicio (Celula **lista, int valor) {
    Celula *temp;

    temp = (Celula *) malloc (sizeof(Celula));

    if (temp != NULL) {
        // Conseguiu alocar memória, aqui se cria uma nova célula
        temp->dado = valor;
        // aqui o campo próximo de temp é ligado ao ponteiro lista, para
        // que o resto dos elementos que já estão na lista não se percam
        temp->proximo = *lista;
        // o ponteiro lista agora pega a clula que havia sido manipulada por temp
        *lista = temp;
        // Caso haja sucesso, retorna 1
        return 1;
    }
    return 0; // Deu errado
}

int inserirOrdenado (Celula **lista, int valor) {
    Celula *nova = (Celula *) malloc (sizeof(Celula));
    Celula *atual = *lista;
    Celula *anterior = NULL;

    if (nova == NULL) {
        return 0; // Falha na alocação de memória
    }

    nova->dado = valor;
    nova->proximo = NULL;

    // Encontra a posição correta para inserção
    while (atual != NULL && atual->dado < valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {
        // Inserção no início da lista
        nova->proximo = *lista;
        *lista = nova;
    } else {
        // Inserção no meio ou no final, conforme for necessário
        anterior->proximo = nova;
        nova->proximo = atual;
    }
    return 1;
}

// Função para remoção de elementos
int remover (Celula **lista, int valor) {
    Celula *atual = *lista;
    Celula *anterior = NULL;

    // Percorre a lista em busca do valor
    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        // Valor não encontrado
        return 0;
    }

    if (anterior == NULL) {
        // O valor está no primeiro nó
        *lista = atual->proximo;
    } else {
        // O valor está em um nó intermediário ou final
        anterior->proximo = atual->proximo;
    }

    free(atual); // Libera a memória do nó removido
    return 1;    // Remoção bem-sucedida
}

// Função para exibir os dados da estrutura
void exibir (Celula *lista) {
    int i = 0;
    Celula *temp;
    temp = lista;   // Utiliza a variável temporária em vez da que marca
                    // o início da estrutura
    if (temp != NULL) {
        printf ("\n Elementos da lista:\n");
        while (temp != NULL) {
            printf (" Elemento[%d]: %d\n", i, temp->dado);
            temp = temp->proximo;
            i++;
        }
    }
    else {
        printf ("\n A lista esta vazia.\n");
    }
}

// Libera a memória alocada para todos os nós, ao final do programa
void liberarMemoria (Celula **lista) {
    Celula *atual = *lista;
    Celula *temp;

    while (atual != NULL) {
        temp = atual;               // Salva o ponteiro atual
        atual = atual->proximo;     // Avança para o próximo nó
        free (temp);                // Libera a memória do nó atual
    }

    *lista = NULL;
}

// Menu do programa
void menu (void) {
    int opcao, elemento, retorno;
    Celula *lista = NULL; // Inicializa a lista como vazia
    
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
            printf ("\n  3 - Exibir conteudo da lista");
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
                    printf ("\n Digite o elemento que deseja inserir na lista => ");
                    retorno = scanf ("%d", &elemento);
                    if ( retorno != 1) {
                        printf ("Entrada inv%clida! Por favor, tente novamente.", 160);
                        while (getchar() != '\n');
                        getch ();
                    }
                } while (retorno != 1);
                if (inserirOrdenado (&lista, elemento)) {
                    printf ("\n Elemento inserido com sucesso!");
                } else 
                    printf ("\n Falha na insercao do elemento.");
                printf ("\n\n Pressione qualquer tecla para continuar...");
                getch();
                break;
            case 2:
                do {
                    printf ("\n Digite o elemento que deseja remover da lista => ");
                    retorno = scanf ("%d", &elemento);
                    if ( retorno != 1) {
                        printf ("Entrada inv%clida! Por favor, tente novamente.", 160);
                        while (getchar() != '\n');
                        getch ();
                    }
                } while (retorno != 1);
                if (remover (&lista, elemento)) {
                    printf ("\n Elemento removido com sucesso!");
                } else
                    printf ("\n Falha na remocao do elemento.");
                printf ("\n\n Pressione qualquer tecla para continuar...");
                getch();
                break;
            case 3: 
                exibir (lista);
                printf ("\n\n Pressione qualquer tecla para continuar...");
                getch();
                break;
            case 4:
                liberarMemoria (&lista);
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