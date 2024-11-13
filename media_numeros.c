// Bibliotecas
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Protótipos das funções
void media(void);

// Definições das funções
void media(void)
{
    printf("Digite n%cmeros inteiros: \n", 0xa3);
    int divisor = 0, soma = 0, num;
    float resultado;
    do
    {
        fflush(stdin);
        scanf("%d", &num);
        if (num != -1)
        {
            soma += num;
            divisor++;
        }
    } while ( num != -1);
    resultado = soma / divisor;
    printf("A m%cdia dos n%cmeros inseridos %c: %0.2f", 0x82, 0xa3, 0x82, resultado);
}

// Corpo do programa
int main()
{
    media();
    system("pause");
    return(0);
}