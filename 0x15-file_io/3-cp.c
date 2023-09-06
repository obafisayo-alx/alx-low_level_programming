#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * file1fail - Print error message if can't read file
 * @file: Name of the file that can't be read
 */
void openfiles(char *file_from, char *file_to, int *fd_from, int *fd_to);
void writefiles(int *fd_from, int *fd_to, char *file_from, char *file_to);
void file_from_fail(char *file)
{
    dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(98);
}

void file_to_fail(char *file)
{
    dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	char *file_from = av[1];
	char *file_to = av[2];
	int fd_from, fd_to;

    if (file_from == NULL)
        file_from_fail(file_from);
    if (file_to == NULL)
        file_to_fail(file_to);
	openfiles(file_from, file_to, &fd_from, &fd_to);
	writefiles(fd_from, fd_to, file_from, file_to);
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", fd_to);
		exit(100);
	}
	return (0);
}

void openfiles(char *file_from, char *file_to, int *fd_from, int *fd_to)
{
	*fd_from = open(file_from, O_RDONLY);
	if (*fd_from == -1)
	{
		file_from_fail(*fd_from);
	}
	*fd_to = open(file_to, O_TRUNC | O_CREAT | O_WRONLY, 0664);
	if (*fd_to == -1)
	{
		file_to_fail(*fd_to);
	}
}

void writefiles(int *fd_from, int *fd_to, char *file_from, char *file_to)
{
	ssize_t bytes_r, bytes_w;
	char *buffer[BUFFER_SIZE];

    bytes_r = read(fd_from, buffer, BUFFER_SIZE);
    if (bytes_r == -1)
        file_from_fail(file_from);
	while ((bytes_r > 0))
	{
		bytes_w = write(fd_to, buffer, bytes_r);
		if (bytes_w != bytes_r)
			file_to_fail(file_to);
        bytes_r = read(fd_from, buffer, BUFFER_SIZE);
        if (bytes_r == -1)
            file_from_fail(file_from);
	}
}
