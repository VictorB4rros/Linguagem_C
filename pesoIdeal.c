// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Variáveis globais
float h, pesoIdeal;
char genero;

// Corpo do programa
int main()
{
	do
	{
		system("cls");
		printf("\nInsira o seu genero: (H/h -> homem; M/m -> mulher)\n");
		fflush(stdin);
		genero = getche();
		switch(genero)
		{
			case 'H': case 'h': {printf("\nGenero inserido: Homem");  getch(); break;}
			case 'M': case 'm': {printf("\nGenero inserido: Mulher"); getch(); break;}
			default : {printf("\nErro!!! Tente novamente.");          getch(); break;}
		}
	} while (genero != 'H' && genero != 'h' && genero != 'M' && genero != 'm');
	
	do
	{
		system("cls");
		printf("\nInsira a sua altura: ");
		fflush(stdin);
		scanf("%f", &h);
		if(h < 0 || h > 3)
		{
			printf("\nAltura invalida!!! Tente novamente.");
			getch();
		}
	} while(h < 0 || h > 3);
	
	if(genero == 'H' || genero == 'h')
	{
		pesoIdeal = (72.7*h) - 58;
		printf("\nSeu peso ideal eh: %f", pesoIdeal);
	}
	else
	if(genero == 'M' || genero == 'm')
	{
		pesoIdeal = (72.7*h) - 68;
		printf("\nSeu peso ideal eh: %f", pesoIdeal);
	}
	
	getch();
	return (0);
}