#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *h;
	ssize_t x;
	ssize_t z;
	ssize_t w;

	x = open(filename, O_RDONLY);
	if (x == -1)
		return (0);
	h = malloc(sizeof(char) * letters);
	w = read(x, h, letters);
	z = write(STDOUT_FILENO, h, w);

	free(h);
	close(x);
	return (z);
}
