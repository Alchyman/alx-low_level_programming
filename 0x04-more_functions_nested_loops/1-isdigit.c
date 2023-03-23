#include "main.h"

/**
 * _isdigit -Check if character is a digit
 * @x: the number to be changed
 * Return: 1 for a character that will be a digit or 0 for any else
 */

int _isdigit(int x)

{

	if (x >= 48 && x <= 57)
	{
	return (1);
	}
	return (0);
}

