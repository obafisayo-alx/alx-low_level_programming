#include "hsh.h"

/**
 * split_string - This is used to split the  stings passed into it.
 * It retuns an array of each wordsd
 * @string: This is the string to be parsed
 * Return: This returns an array of words
 */
char **split_string(const char *string)
{
	int i, t;
	size_t len;
	char *str, *token;
	char **words_arr;
	const char delim = ' ';

	t = 0;
	str = _strdup(string);
	for (token = strtok(str, &delim); token != NULL; token = strtok(NULL, &delim))
	{
		t++;
	}
	free(str);
	words_arr = (char **)malloc((t + 1) * sizeof(char *));
	if (words_arr == NULL)
	{
		write(STDERR_FILENO, "Memory allocation failed", 25);
		exit(1);
	}
	i = 0;
	str = _strdup(string);
	for (token = strtok(str, &delim); token != NULL; token = strtok(NULL, &delim))
	{
		len = _strlen(token);
		if (len > 0 && token[len - 1] == '\n')
		{
			token[len - 1] = '\0';
		}
		words_arr[i] = _strdup(token);
		i++;
	}
	words_arr[i] = NULL;
	free(str);
	return (words_arr);
}

