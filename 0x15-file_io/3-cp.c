#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * file_from_fail - Print error message if can't read file
 * @file: Name of the file that can't be read
 */
void file_from_fail(char *file)
{
    dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(98);
}

/**
 * file_to_fail - Print error message if can't read file
 * @file: Name of the file that can't be read
 */
void file_to_fail(char *file)
{
    dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}

/**
 * writeError - Print error message if file can't close
 * @file: Name of the file that can't be read
 */
void write_error(char *fd_from)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", fd_from);
	exit(100);
}

/**
  * main - copy the content of one file to another
  * @ac: Number of arguments received
  * @av: Array of arguments received
  *
  * Return: 0 on success
  */
int main(int ac, char **av)
{
	int fd_from, fd_to, bytes_r, bytes_w;
	char *buffer[BUFFER_SIZE];
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

    if (av[1] == NULL)
        file_from_fail(av[1]);
    if (av[2] == NULL)
        file_to_fail(av[2]);
    fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		file_from_fail(fd_from);
	fd_to = open(av[2], O_TRUNC | O_CREAT | O_WRONLY, mode);
	if (fd_to == -1)
		file_to_fail(fd_to);
    bytes_r = read(fd_from, buffer, BUFFER_SIZE);
    if (bytes_r == -1)
        file_from_fail(av[1]);
	while ((bytes_r > 0))
	{
		bytes_w = write(fd_to, buffer, bytes_r);
		if (bytes_w != bytes_r)
			file_to_fail(av[2]);
        bytes_r = read(fd_from, buffer, BUFFER_SIZE);
        if (bytes_r == -1)
            file_from_fail(av[1]);
	}
	if (close(fd_from) == -1)
        write_error(fd_from);
	if (close(fd_to) == -1)
        write_error(fd_to);
	return (0);
}
