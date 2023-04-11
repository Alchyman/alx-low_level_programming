#include <stdlib.h>
#include "main.h"

/**
 * **alloc_grid - creates a single two dimensional array of ints
 * @width: width of the matrix
 * @height: height of matrix
 *
 * Return: created matrix (Success)
 * or NULL (Error)
 */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **arr;

	if (height <= 0 || width <= 0)
		return (NULL);

	arr = (int **) malloc(sizeof(int *) * height);

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		arr[i] = (int *) malloc(sizeof(int) * width);
		if (arr[i] == NULL)
		{
			free(arr);
			for (j = 0; j <= i; j++)
				free(arr[j]);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			arr[i][j] = 0;
		}
	}
	return (arr);
}
