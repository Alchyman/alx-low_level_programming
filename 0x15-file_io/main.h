#ifndef MAIN_H
#define MAIN_H

/*
 * File: is holberton.h
 * Auth: Alachngel Migwi
 * Desc: Header file containing prototypes for all the functions
 *       written in the 0x14-file_io directory.
 */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int append_text_to_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);

#endif /* MAIN_H */
