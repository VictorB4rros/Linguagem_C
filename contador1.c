// Bibliotecas
#include<conio.h>
#include<stdio.h>

// Protótipos
void contador(void);

// Definições das funções
void contador(void)
{
    for(int i = 100; i >= 1; i--)
    {
        printf("\n %d", i);
    }
    getch();
}

// Corpo do programa
int main()
{
    contador();
    return(0);
}