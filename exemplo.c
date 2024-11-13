// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Variáveis globais
int i;

// Corpo do programa
int main()
{
	for(i = 10; i > -1; i--)
	{
		printf("%d\n", i);
		Sleep(1000);
	}
	printf("\n\tTE AMO MUITOOOOOOO!!!\n");
	getch();
	
	return 0;
}