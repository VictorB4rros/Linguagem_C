// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Variáveis globais
int n;
char opcao;

// Protótipos das funções utilizadas no programa
int soma_recursiva (int n);
int soma (int n);

// Definições das funções
int soma(int n) // Função que soma sem usar a recursividade
{
    int resultado = 0;
    if (n != 0)
    {
        for( ; n > 0; n--)
        {
            resultado = resultado + n;
        }
    }
    return resultado;
}

int soma_recursiva(int n) // Função soma que usa a recursividade
{
    if(n == 0)
    {
        return(0);
    }
    else
    {
        return (n + soma_recursiva(n-1));
    }
}

// Corpo do programa
int main()
{
    do
    {
        system("cls");
        printf("\nEste programa calcula a soma de todos os valores inteiros entre 1 e n, sendo n fornecido pelo usuario.");
        printf("\n\nPor favor, digite o valor de n: ");
        fflush(stdin);
        scanf("%d", &n);
        printf("\nO valor inserido foi: %d. Deseja continuar? [S/s] = Sim", n);
        opcao = getche();
    } while (opcao != 's' && opcao != 'S');

    printf("\n\nO valor da soma eh: %d", soma(n));

    printf("\n\nO valor da soma recursiva eh: %d", soma_recursiva(n));
    
    getch();
    return(0);
}