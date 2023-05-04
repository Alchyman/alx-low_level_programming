#include "main.h"
#include <stdio.h>

/**
 * flip_bits - flip bits that will be  converting one number to another number
 * @n: the first number
 * @m: the second number to convert to
 * Return: number of bits that was needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int counter;
	unsigned long int diff;

	diff = n ^ m;
	counter = 0;

	while (diff)
	{
		counter++;
		diff &= (diff - 1);
	}

	return (counter);
}
