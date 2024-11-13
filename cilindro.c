/* Este programa recebe o raio e a altura de um cilindro e calcula a quantidade de latas de tinta necessárias
   e o custo para pintar a superfície do cilindro 
   1 lata custa R$ 20,00 
   Cada lata contém 5 litros 
   Cada litro de tinta pinta 3 metros quadrados */
   
// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

// Variáveis globais
float raio, h, areaCilindro;	// h é a altura do cilindro
float litros; 					// litros de tinta necessários
float latas;					// quantidade de latas de tinta necessárias
float custo;					// custo em reais para comprar as latas de tinta
char opcao;

// Corpo do programa
int main()
{
	do
	{
		system("cls");
		printf("\nInsira o raio do cilindro em metros: ");
		fflush(stdin);
		scanf("%f", &raio);
		printf("\nInsira a altura do cilindro em metros: ");
		fflush(stdin);
		scanf("%f", &h);
		printf("\nDados inseridos: raio = %0.1fm / altura = %0.1fm", raio, h);
		printf("\n\nDeseja continuar com esses dados? [S/s] = sim ");
		opcao = getche();
	} while (opcao != 'S' && opcao != 's');
	
	areaCilindro = 3.14*(raio*raio) + 2*3.14*raio*h; // Cálculo da área do cilindro
	
	litros = areaCilindro/3;	// Cálculo da quantidade de litros necessária para pintar toda a área do cilindro, dado que 1 litro pinta 3 metros quadrados
	
	latas = litros/5;           // Cálculo da quantidade de latas necessária, dado que 1 lata contém 5 litros de tinta
	
	custo = ceil(latas)*20;     // Cálculo do custo total, dado que cada lata custa R$20,00
	
	system("cls");
	printf("\n\nArea do cilindro: %0.1fm%c", areaCilindro, 253);
	printf("\n\nQuantidade de litros de tinta: %0.1fL", litros);
	printf("\n\nQuantidade de latas de tinta: %0.1f", ceil(latas));
	printf("\n\nCusto total para pintar o cilindro: R%c%0.2f", 36, custo);
	
	getch();
	return (0);
}