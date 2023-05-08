#include "main.h"

/**
 * create_file - its creates a file.
 * @filename: A pointer to the name of the file that will be created.
 * @text_content: A pointer to a string to write to that file.
 * Return: If the function fails show -1.
 *         Otherwise show 1.
 */
int create_file(const char *filename, char *text_content)
{
	int t, m, sat = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (sat = 0; text_content[sat];)
			sat++;
	}

	m = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	t = write(m, text_content, sat);

	if (m == -1 || t == -1)
		return (-1);

	close(m);

	return (1);
}
