#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	size_t i;
	ssize_t bytes_to_write;
    char *buffer;

	if (filename == NULL)
		return (-1);

    if (buffer == NULL)
        return (-1);

    for ( i = 0; text_content && text_content[i]; i++)
        ;
    
    buffer = malloc(sizeof(char) * i);
    fd = open(fd, O_APPEND | O_WRONLY);
    if (fd == -1)
    {   
        free(buffer);
        return (-1);
    }
    
    if (text_content == NULL)
    {
        free(buffer);
        close(fd);
        write(fd, text_content, i);
    }  else 
        bytes_to_write = write(fd, buffer, sizeof(buffer) - 1);

    close(fd);
    if (bytes_to_write == -1)
        return (-1);

    return (1);

} 