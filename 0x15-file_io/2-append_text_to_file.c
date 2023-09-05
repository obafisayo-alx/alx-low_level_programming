#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

 /**
 * append_text_to_file - append text `text_content' to the end of
 * file `filename'.
 * @filename: name of the file to append to
 * @text_content: content to append to `filename'
 *
 * Return: 1 on success, -1 if `write' or `open' fails
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	size_t i;
	ssize_t bytes_to_write;

	if (filename == NULL)
		return (-1);

    fd = open(filename, O_APPEND | O_WRONLY);
    if (fd == -1)  
        return (-1);

    for ( i = 0; text_content && text_content[i]; i++)
        ;
    
    if (text_content == NULL)
    {
        close(fd);
        return (-1);
    }  else 
        bytes_to_write = write(fd, text_content, i);

    close(fd);
    if (bytes_to_write == -1)
        return (-1);

    return (1);

} 