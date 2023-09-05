#include "main.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
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
        if (filename = NULL)
        {
                return (0);
        }

        char *buffer = malloc(sizeof(char) * letters);
        if (buffer == NULL)
        {
                return (0);
        }

        int fd = open("filename", O_RDONLY);
        if ( fd == -1 )
        {
                free(buffer);
                return (0);
        }

        ssize_t bytes_read = read(fd, buffer, letters);
        if (bytes_read == -1)
        {
                free(buffer);
                return (0);
        }

        close(fd);
        
        ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
        if (bytes_written == -1)
        {
                free(buffer);
                return (0);
        }
        
        if (bytes_written != bytes_read)
        {
                return (0);
        }

        return (bytes_read);
}