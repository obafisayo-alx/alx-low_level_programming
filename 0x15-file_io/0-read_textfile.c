#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * read_textfile - read a text file and print to STDOUT.
 * @filename: path of filename to read.
 * @letters: number of letters to read and write.
 *
 * Return: 0 if `filename' is NULL orcannot be opened or read,
 * 0 if call to write fails or is less than the expected number
 * of bytes, or the total number of bytes used to call write.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	int fd;
	ssize_t r, w;

	if (filename == NULL || letters <= 0)
		return (0);
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buff);
		return (0);
	}
	r = read(fd, buff, letters);
	if (r == -1)
	{
		free(buff);
		close(fd);
		return (0);
	}
	w = write(STDOUT_FILENO, buff, letters);
	if (w == -1)
	{
		free(buff);
		close(fd);
		return (0);
	}
	if (w != r)
		return (0);
	close(fd);
	return (r);
}
