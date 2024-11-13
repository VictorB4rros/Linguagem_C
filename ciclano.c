// Bibliotecas
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Protótipos das funções
void crescimento(void); // Crescimento é um procedimento (porque não retorna nada)

// Definições das funções
void crescimento(void)
{
    float fulano = 1.5, ciclano = 1.1;
    int anos = 0;
    while(ciclano <= fulano)
    {
        printf("Fulano tem %0.2f de altura e ciclano tem %0.2f de altura.\n\n", fulano, ciclano);
        fulano += 0.02;
        ciclano += 0.03;
        anos++;
    }
    if (ciclano > fulano)
    printf("Foram necess%crios %d anos para que ciclano ficasse maior que fulano.", 0xa0, anos);
}

// Corpo do programa
int main()
{
    crescimento();
    system("pause");
    return(0);
}