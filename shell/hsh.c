#include "hsh.h"

#define MAX_ERROR_MESSAGE_LENGTH 256

/**
 * main - main entry point
 * @argc: arguement count variable.
 * @argv: arguement vector.
 * @env: environment path.
 * Return: always 0
 */
int main(int argc, char *argv[], char *env[])
{
	char *line_ptr = NULL;
	size_t len = 0;
	ssize_t c_read;
	char **tokens;
	int i;
	bool from_pipe = false;
	pid_t child_pid;
	int status;
	struct stat st;

	while (!from_pipe && argc == 1)
	{
		if (isatty(STDIN_FILENO) == 0)
			from_pipe = true;
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);

		c_read = getline(&line_ptr, &len, stdin);
		if (c_read == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (line_ptr[c_read - 1] == '\n')
			line_ptr[c_read - 1] = '\0';
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: Can't create child process");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			tokens = split_string(line_ptr);
			execute_file(tokens, &st, env, argv);
			for (i = 0; tokens[i] != NULL; i++)
			{
				free(tokens[i]);
			}
			free(tokens);
		}
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("Error: Can't wait for child_pid");
			exit(EXIT_FAILURE);
		}
	}
	free(line_ptr);
	return (0);
}
