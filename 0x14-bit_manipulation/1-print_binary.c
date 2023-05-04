#include "main.h"
#include <stdio.h>

/**
 * print_binary - print the binary representation of a number
 * @n: decimal number that will be  printed as binary
 */
void print_binary(unsigned long int n)
{
	int shifts;
	unsigned long int temp;

	if (n == 0)
	{
		printf("0");
		return;
	}

	for (temp = n, shifts = 0; (temp >>= 1) > 0; shifts++)
		;

	for (; shifts >= 0; shifts--)
	{
		if ((n >> shifts) & 1)
			printf("1");
		else
			printf("0");
	}
}
