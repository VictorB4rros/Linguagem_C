// Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

// Variáveis globais
int *v;

// Corpo do programa
int main()
{
	v = malloc(10 * sizeof(int)); // esta linha tem o mesmo efeito prático de escrever int v[10];
	
	for(int i=0; i<=9; i++)
	{
		system("cls");
		printf("\nInsira o numero da posicao %d: ", i);
		scanf("%d", &v[i]);
	}
	system("cls");
	printf("\nConteudos de cada um dos 10 elementos do vetor escritos em decimal:");
	for(int i=0; i<=9; i++)
	{
		Sleep(250);
		printf("\n%d", v[i]);
	}
	printf("\nConteudos de cada um dos 10 elementos do vetor escritos em hexadecimal:");
	for(int i=0; i<=9; i++)
	{
		Sleep(250);
		printf("\n%x", v[i]);
	}
	printf("\n\nEnderecos de memoria de cada uma das 10 posicoes do vetor:");
	for(int i=0; i<=9; i++)
	{
		Sleep(250);
		printf("\n%p", &v[i]);
	}
	
	getch();
	return(0);
}