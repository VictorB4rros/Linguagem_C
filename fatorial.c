// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Variáveis globais
int n;
char opcao, opcao1;

// protótipos das funções usadas no programa
int fatorial_recursivo(int n);

// definição das funções usadas no programa
int fatorial_recursivo(int n)
{
	if((n==0) || (n==1))
		return 1;
	else
		return (n * fatorial_recursivo(n-1));
}

// Corpo do programa
int main()
{
	do
	{
		do
		{
			system("cls");
			printf("\nInsira o numero desejado para realizar a operacao fatorial: ");
			fflush(stdin);
			scanf("%d", &n);
			printf("\nNumero inserido: %d", n);
			printf("\n\nDeseja continuar com esse valor? [S/s] = sim ");
			opcao = getche();
		} while (opcao != 'S' && opcao != 's');
		system("cls");
		
		printf("\nO resultado do fatorial de %d eh: %d", n, fatorial_recursivo(n));
		
		printf("\n\nDeseja realizar outra operacao fatorial? [S/s] = sim ");
		opcao1 = getche();
	} while(opcao1 == 's');
	return(0);
}