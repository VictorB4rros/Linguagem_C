// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Variáveis globais
float n, h = 0;
char opcao;

// Corpo do programa
int main()
{
	do
	{
		system("cls");
		printf("\nInsira o numero desejado: ");
		fflush(stdin);
		scanf("%f", &n);
		printf("\nNumero inserido: %0.1f", n);
		printf("\n\nDeseja continuar com esse valor? [S/s] = sim ");
		opcao = getche();
	} while (opcao != 'S' && opcao != 's');
	
	system("cls");
	for(int i = 1; i <= n; i++)
	{
		Sleep(500);
		h = h + 1.0/i;
		printf("\n%0.6f", h);
	}
	
	getch();
	return(0);
}