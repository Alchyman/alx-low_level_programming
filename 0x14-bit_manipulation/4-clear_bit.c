#include "main.h"
#include <stdio.h>
/**
 * clear_bit - set value of a bit to 0 at a given index
 * @n: pointer to a decimal number to change
 * @index: index position that will be changed
 * Return: 1 if it worked, -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int hold;
	unsigned long int i;

	if (index > 64)
		return (-1);
	hold = index;
	for (i = 1; hold > 0; i *= 2, hold--)
		;

	if ((*n >> index) & 1)
		*n -= i;

	return (1);
}
