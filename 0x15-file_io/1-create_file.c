#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * create_file - Create `filename' with content from `text_content'
 * @filename: name of file to create
 * @text_content: content to insert into file `filename'
 *
 * Return: 1 on success, -1 if error occurs using `write`.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	size_t l;
	ssize_t btw;

	if (filename == NULL)
		return (-1);

	for (l = 0; text_content && text_content[l]; l++)
		;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	btw = write(fd, text_content, l);
	close(fd);
	if (btw == -1)
		return (-1);

	return (1);
}
