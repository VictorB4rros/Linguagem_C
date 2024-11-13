// Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// Variáveis globais
int tempCelsius = -100;
float tempFar;

// Protótipos de funções
void conversao(void);

// Definições das funções
void conversao(void)
{
    for( ; tempCelsius <= 100; tempCelsius = tempCelsius + 10)
    {
        tempFar = (9.0 / 5.0) * (tempCelsius) + 32;
        printf("\nTemperatura em Celsius: %d - Temperatura em Fahrenheit: %0.2f", tempCelsius, tempFar);
    }
    getch();
}

// Corpo do programa
int main()
{
    conversao();
    return(0);
}