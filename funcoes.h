//Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

//Funções para o projeto

void imprimeTitulo(void) //Função para imprimir o cabeçalho nas telas do programa
{
	printf("--------------------------------------------------------------------------------------------------------------------\n\n");
	printf("                                                 Contador de treinos\n\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
}

int anoBissexto(int ano) // Função que confere se o ano é bissexto
{
	if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
		return 1;
		return 0;
}

int diasNoAno (int ano) //Função que retorna o número de dias do ano
{
	if(anoBissexto(ano))
	return 366;
	return 365;
}

int diasDoMes(int mes, int ano) // Função que confere a quantidade de dias no mês
{
	switch (mes)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
		case 4: case 6: case 9: case 11: return 30;
		case 2: return anoBissexto(ano) ? 29 : 28;
	}
}

void incrementaData(int *dia, int *mes, int *ano, int incremento) // Função que incrementa as datas
{
	*dia += incremento;
	while(*dia > diasDoMes(*mes, *ano))
	{
		*dia -= diasDoMes(*mes, *ano);
		(*mes)++;
		if(*mes > 12)
		{
			*mes = 1;
			(*ano)++;
		}
	}
}

void formulaZeller(int dia, int mes, int ano, FILE *arquivo) // Função que identifica o dia da semana para uma determinada data (com espaços)
{
	if(mes == 1 || mes == 2)
	{
		mes += 12; ano -= 1;
	}
	int diaDaSemana = (dia + (((mes + 1)*13)/5) + ano % 100 + ((ano % 100)/4) + (ano / 400) + 5 * (ano/100)) % 7;
	
	switch(diaDaSemana)
	{
		case 0: printf("       S%cbado  ", 160); fprintf(arquivo, "       Sábado  "); break;
		case 1: printf("      Domingo  ");       fprintf(arquivo, "      Domingo  "); break;
		case 2: printf("Segunda-feira  ");       fprintf(arquivo, "Segunda-feira  "); break;
		case 3: printf("  Ter%ca-feira  ", 135); fprintf(arquivo, "  Terça-feira  "); break;
		case 4: printf(" Quarta-feira  ");       fprintf(arquivo, " Quarta-feira  "); break;
		case 5: printf(" Quinta-feira  ");       fprintf(arquivo, " Quinta-feira  "); break;
		case 6: printf("  Sexta-feira  ");       fprintf(arquivo, "  Sexta-feira  "); break; 
	}
}

void formulaZeller2(int dia, int mes, int ano, FILE *arquivo) // Função que identifica o dia da semana para uma determinada data
{
	if(mes == 1 || mes == 2)
	{
		mes += 12; ano -= 1;
	}
	int diaDaSemana = (dia + (((mes + 1)*13)/5) + ano % 100 + ((ano % 100)/4) + (ano / 400) + 5 * (ano/100)) % 7;
	
	switch(diaDaSemana)
	{
		case 0: printf("S%cbado", 160);      fprintf(arquivo, "Sábado");        break;
		case 1: printf("Domingo");           fprintf(arquivo, "Domingo");       break;
		case 2: printf("Segunda-feira");     fprintf(arquivo, "Segunda-feira"); break;
		case 3: printf("Ter%ca-feira", 135); fprintf(arquivo, "Terça-feira");   break;
		case 4: printf("Quarta-feira");      fprintf(arquivo, "Quarta-feira");  break;
		case 5: printf("Quinta-feira");      fprintf(arquivo, "Quinta-feira");  break;
		case 6: printf("Sexta-feira");       fprintf(arquivo, "Sexta-feira");   break; 
	}
}

int mdc(int x, int y) //Função que calcula o MDC de dois números
{
	int z;
	while(y != 0)
	{
		z = y;
		y = x%y;
		x = z;
	}
	return x;
}

int mmc(int x, int y) // Função que calcula o MMC de dois números
{
	return (x / mdc(x, y)) * y;
}

int mmc4(int x, int y, int z, int w) // Função que calcula o MMC de quatro números
{
	return mmc(mmc(mmc(x, y), z), w);
}