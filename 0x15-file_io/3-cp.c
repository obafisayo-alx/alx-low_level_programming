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
void writefiles(int *fd_from, int *fd_to);
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

	openfiles(file_from, file_to, &fd_from, &fd_to);
	writefiles(fd_from, fd_to);
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
	mode_t old_umask = umask(0);

	*fd_from = open(file_from, O_RDONLY);
	if (*fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	*fd_to = open(file_to, O_TRUNC | O_CREAT | O_WRONLY, 0664);
	umask(old_umask);
	if (*fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		close(fd_from);
		exit(99);
	}
}

void writefiles(int *fd_from, int *fd_to)
{
	ssize_t bytes_r, bytes_w;
	char *buffer[BUFFER_SIZE];

	while ((bytes_r = read(fd_from, buffer, sizeof(buffer)) > 0))
	{
		bytes_w = write(fd_to, buffer, bytes_r);
		if (bytes_w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to fd %d\n", fd_to);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}
	if (bytes_r == -1)
	{
		close(fd_from);
		dprintf(STDERR_FILENO, "Error: Can't read from fd %d\n", fd_from);
		close(fd_to);
		exit(98);
	}
}
