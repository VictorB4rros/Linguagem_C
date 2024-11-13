// Este programa recebe 3 comprimentos de reta do usuário e verifica se elas podem formar um triângulo
// Caso possam formar o triângulo, o programa informa que tipo de triângulo ele é

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Variáveis globais
float A, B, C; // comprimentos de reta inseridos pelo usuário
char opcao;

// Corpo do programa
int main()
{
	do
	{
		system("cls");
		printf("\nInsira o comprimento da primeira reta: ");
		fflush(stdin);
		scanf("%f", &A);
		printf("\nInsira o comprimento da segunda reta: ");
		fflush(stdin);
		scanf("%f", &B);
		printf("\nInsira o comprimento da terceira reta: ");
		fflush(stdin);
		scanf("%f", &C);
		printf("\nDados inseridos: reta A = %0.1f / reta B = %0.1f / reta C = %0.1f", A, B, C);
		printf("\n\nDeseja continuar com esses valores? [S/s] = sim ");
		opcao = getche();
	} while (opcao != 'S' && opcao != 's');
	
	system("cls");
	if(A <= (B+C) && B <= (A+C) && C <= (A+B))
	{
		printf("\nAs retas fornecidas formam um triangulo.");
		if(A == B && B == C && C == A)
		{
			printf("\n\nO triangulo eh equilatero.");
		}
		if((A == B && A != C) || (B == C && B != A) || (C == A && C != B))
		{
			printf("\n\nO triangulo eh isosceles.");
		}
		if(A != B && B != C && C != A)
		{
			printf("\n\nO triangulo eh escaleno.");
		}
	}
	else
	printf("\nAs retas fornecidas nao formam um triangulo.");
	
	getch();
	return(0);
}