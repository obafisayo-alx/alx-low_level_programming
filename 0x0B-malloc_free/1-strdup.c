#include "main.h"

/**
 * _strdup - This function works like the strdup function that is use to duplicate strings.
 * @str: This is the string to be duplicated.
 * Return: A pointer to a new string which is a duplicate of the string str. 
*/
char *_strdup(char *str)
{
    char *dupstr;
    int i, j;

    if (str == NULL)
        return (NULL);
    for (i = 0; str[i] != '\0'; i++)
        ;
    dupstr = malloc(sizeof(char) * i);
    for (j = 0; str[j] != '\0'; j++)
    {
        dupstr[j] = str [j];
    }
    dupstr[i] = '\0';
    if (dupstr == NULL)
        return (NULL);
    return (dupstr);
}