#include <stdio.h>

#define alturaMaxima 2.25

typedef struct 
{
	float peso;    // peso em quilogramas
	float altura;  // altura em metros
} PesoAltura;

int main()
{
	PesoAltura pessoa1;  // PesoAltura é o novo tipo de dados
	
	pessoa1.peso = 80;
	pessoa1.altura = 1.85;
	
	printf("\nPeso: %0.2f, altura: %0.2f", pessoa1.peso, pessoa1.altura);
	
	if(pessoa1.altura > alturaMaxima)
		printf("\n\nAltura acima da maxima permitida.");
	else
		printf("\n\nAltura abaixo da maxima permitida.");
	return(0);
}