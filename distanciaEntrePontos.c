/* Este programa recebe do usuário o X e Y de um ponto P e o X e Y de um ponto Q e calcula a distância entre os dois pontos */

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

// Variáveis globais
int x, y, z, w;
float distancia;
char opcao;

// Corpo do programa
int main()
{
	do{
		system("cls");
		printf("\nInsira o X do ponto P: ");
		fflush(stdin);
		scanf("%d", &x);
		printf("\nInsira o Y do ponto P: ");
		fflush(stdin);
		scanf("%d", &y);
		printf("\nValor inserido: (%d,%d)", x, y);
		printf("\nDeseja continuar com esse valor? [S/s = sim] ");
		opcao = getche();
	} while (opcao != 's' && opcao != 'S');
	
	do{
		system("cls");
		printf("\nInsira o X do ponto Q: ");
		fflush(stdin);
		scanf("%d", &z);
		printf("\nInsira o Y do ponto Q: ");
		fflush(stdin);
		scanf("%d", &w);
		printf("\nValor inserido: (%d,%d)", z, w);
		printf("\nDeseja continuar com esse valor? [S/s = sim] ");
		opcao = getche();
	} while (opcao != 's' && opcao != 'S');
	
	distancia = sqrt((z-x)*(z-x) + (w-y)*(w-y));
	
	system("cls");
	printf("\nA distancia entre os pontos P(%d,%d) e Q(%d,%d) eh: %0.1f", x, y, z, w, distancia);

	getch();
	return (0);
}