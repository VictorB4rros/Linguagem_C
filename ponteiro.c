#include <stdio.h>

int main()
{
	int x = 25;
	int * y;
	y = &x;
	*y = 30;
	printf("Valor atual de x: %i\n", x);
	printf("\nEndereco de memoria de x: %x", y);
	return 0;
}