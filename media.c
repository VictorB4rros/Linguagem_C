// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Variáveis globais
float n1, n2, n3, media;

// Corpo do programa
int main()
{
	printf("\nInsira a nota 1: ");
	fflush(stdin);
	scanf("%f", &n1);
	
	system("cls");
	
	printf("\nInsira a nota 2: ");
	fflush(stdin);
	scanf("%f", &n2);
	
	system("cls");
	
	printf("\nInsira a nota 3: ");
	fflush(stdin);
	scanf("%f", &n3);
	
	system("cls");
	
	media = (n1+n2+n3)/3;
	
	printf("\nA media final eh: %f", media);
	getch();
	return(0);
}