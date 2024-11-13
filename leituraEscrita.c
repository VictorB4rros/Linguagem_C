#include <stdio.h>

int main()
{
	char buffer[10]; // declaração de um string de tamanho 10
	printf("\nEntre com o seu nome: ");
	gets(buffer); // leitura do string, que pode conter espaço em branco
	printf("O nome %c: %s\n", 130, buffer);
	puts("O nome eh: ");
	puts(buffer);
	return 0;
}