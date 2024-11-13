// Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// Protótipos das funções
void multiplos_sete (void);

// Definições das funções
void multiplos_sete (void)
{
    int resultado = 0;
    for(int i = 0; i <= 100; i++)
    {
        resultado = 7*i;
        if (resultado <= 100)
        {
            printf("7 x %d = %d\n", i, resultado);
        }
    }
}

// Corpo do programa
int main()
{
    multiplos_sete();
    system("pause");
    return(0);
}