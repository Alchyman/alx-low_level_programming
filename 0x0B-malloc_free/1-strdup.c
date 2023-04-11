#include <stdlib.h>
#include "main.h"

/**
 * *_strdup - copu string
 * @str: duplicate
 *
 * Return: pointer to string (Success), NULL (Error)
 */
char *_strdup(char *str)
{
	unsigned int i, len;
	char *dup;

	len = 0;
	i = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	while ((dup[i] = str[i]) != '\0')
		i++;

	return (dup);
}
