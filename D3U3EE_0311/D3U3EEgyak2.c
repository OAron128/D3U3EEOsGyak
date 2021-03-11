#include	<stdio.h>
#include	<stdlib.h>

int main()
{

char utasitas[50];

do
{
printf("Adjon meg egy vagy több  Unix parancsot! Ctr + C-vel léphet ki.\n\n");
scanf("%s", utasitas);

system(utasitas);

printf("\n");
} while (1);

	exit(0);
}
