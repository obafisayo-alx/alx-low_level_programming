#include "dog.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _strdup - Return pointer to a new string that duplicates given string,
 * allocate mem w/ malloc
 * @str: String to duplicate
 *
 * Return: Pointer to new string, NULL if failed to make memory
 */
char *_strdup(char *str)
{
	char *nstr;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);
	i = len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	len++;
	nstr = malloc(len * sizeof(*str));
	if (nstr == NULL)
		return (NULL);
	while (i <= len)
	{
		nstr[i] = str[i];
		i++;
	}
	return (nstr);
}

/**
 * new_dog - This function creates a new dog
 * @name: This is the name of the dog
 * @age: This is the age of the dog
 * @owner: This is the owner of the dog
 * Return: This is a pointer to the newly created dog
*/
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *p = malloc(sizeof(dog_t));
    char *n_name, *n_owner;

    n_name = _strdup(name);
    n_owner = _strdup(owner);
    if (p == NULL)
        return (NULL);
    p->name = n_name;
    p->owner = n_owner;
    if (n_name == NULL || n_owner == NULL)
    {
        free(n_name);
        free(n_owner);
        free(p);
        return NULL;
    }
    p->age = age;
    return (p);
}
