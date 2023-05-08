#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_buffer - Allocates 1024 bytes for buffer.
 * @file: The name of the file that buffer is storing chars for.
 *
 * Return: A pointer to newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - it closes file descriptors.
 * @fd: The file descriptor that will be closed.
 */
void close_file(int fd)
{
	int m;

	m = close(fd);

	if (m == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a single file to another file.
 * @argc: The number of arguments supplied to program.
 * @argv: An array of pointers to arguments.
 * Return: 0 on success.
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or it cannot be read - exit code 98.
 *              If file_to cannot be created or it's written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	char *buffer;
	int pet, x, m, z;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	pet = open(argv[1], O_RDONLY);
	m = read(pet, buffer, 1024);
	x = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (pet == -1 || m == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		z = write(x, buffer, m);
		if (x == -1 || z == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		m = read(pet, buffer, 1024);
		x = open(argv[2], O_WRONLY | O_APPEND);

	} while (m > 0);

	free(buffer);
	close_file(pet);
	close_file(x);

	return (0);
}
