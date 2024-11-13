// Este programa recebe um número inteiro e responde se ele é par ou ímpar e se é positivo ou negativo

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Variáveis globais
int numero; 		// valor que será analizado
char opcao;

// Corpo do programa
int main()
{
	do
	{
		system("cls");
		printf("\nInsira o numero desejado: ");
		fflush(stdin);
		scanf("%d", &numero);
		printf("\nNumero inserido: %d", numero);
		printf("\n\nDeseja continuar com esse valor? [S/s] = sim ");
		opcao = getche();
	} while (opcao != 'S' && opcao != 's');
	
	system("cls");
	if(numero % 2 == 0)
		printf("\nO numero eh par.");
		else printf("\nO numero eh impar.");
		
	if(numero >= 0)
		printf("\n\nO numero eh positivo.");
		else printf("\n\nO numero eh negativo.");
	
	getch();
	return(0);
}