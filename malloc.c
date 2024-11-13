// Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

// Tipos de dados definidos pelo programador
typedef struct 
{
	int dia, mes, ano;
} data;

// Corpo do programa
int main()
{
	// Variáveis locais ao main
	data *d;
	int qtd_memoria;
	setlocale (LC_ALL, "");
	system("mode 115,6");
	
	// sizeof retornará a quantidade de bytes da estrutura data
	qtd_memoria = sizeof(data);
	
	// o ponteiro d apontará para o endereço de memória de onde começa a memória alocada por malloc
	d = (data *) malloc(qtd_memoria); /* malloc retorna um ponteiro do tipo genérico void *, ou seja, um ponteiro
	que aponta para qualquer tipo de dado. Mas d é um ponteiro do tipo data *, por isso fazemos a conversão explícita
	do ponteiro retornado por malloc para o tipo data * com (data *) */
	
	// os conteúdos da memória reservada são preenchidos
	d->dia = 1;		// no caso como d é um ponteiro, a sintaxe correta é -> e não . como estou acostumado
	d->mes = 8;
	d->ano = 2019;
	
	// monta o cabeçalho para exibição dos dados
	printf("& de qtd_memoria\t\t& do ponteiro d\t\t& de d->dia\t\t& de d->mes\t\t& de d->ano\n");
	// exibe os endereços de memória de: qtd_memoria, d, d->dia, d->mes e d->ano
	printf("[%p]\t[%p]\t[%p]\t[%p]\t[%p]\n", &qtd_memoria, &d, &d->dia, &d->mes, &d->ano);
	// exibe os conteúdos das variáveis: qtd_memoria, d, d->dia, d->mes e d->ano
	printf("qtd_memoria=%d\t\td=%p\tdia=%d\t\tmes=%d\t\tano=%d. ", qtd_memoria, d, d->dia, d->mes, d->ano);
	
	getch();
	return(0);
}