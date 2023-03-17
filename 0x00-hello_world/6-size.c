#include <stdio.h>

/**
 * main - main function
 *
 * Return: 0 on success
 */

int main(void)
{
	printf("size of a char: %1u byte(s)", sizeof(char));
	printf("size of int: %1u byte(s)", sizeof(int));
	printf("size of a long int: %1u byte(s)", sizeof(long int));
	printf("size of a long long int: %1u byte(s)", sizeof(long long int));
	printf("size of a float: %1u byte(s)", sizeof(float));
	return (0);
}
