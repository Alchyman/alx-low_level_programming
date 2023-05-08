#include "main.h"

/**
 * append_text_to_file - Appends text at end of a file.
 * @filename: A pointer to name of the file.
 * @text_content: The string that will be added to the end of the file.
 * Return: If the function fails or filename is NULL show -1.
 *         If the file does not exist the user lacks write permissions show -1.
 *         Otherwise show 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int f, v, sat = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (sat = 0; text_content[sat];)
			sat++;
	}

	v = open(filename, O_WRONLY | O_APPEND);
	f = write(v, text_content, sat);

	if (v == -1 || f == -1)
		return (-1);

	close(v);

	return (1);
}
