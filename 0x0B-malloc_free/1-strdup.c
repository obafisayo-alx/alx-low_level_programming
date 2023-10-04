#include "main.h"

/**
 * _strdup - This function works like the strdup function that is use to duplicate strings.
 * @str: This is the string to be duplicated.
 * Return: A pointer to a new string which is a duplicate of the string str. 
*/
char *_strdup(char *str)
{
    char *dupstr;
    unsigned int i, j;

    if (str == NULL)
        return (NULL);
    for (i = 0; str[i] != '\0'; i++)
        ;
    dupstr = malloc(sizeof(char) * (i + 1));
    while (j <= i)
    {
        dupstr[j] = str [j];
        j++;
    }
    
    dupstr[i] = '\0';
    if (dupstr == NULL)
        return (NULL);
    return (dupstr);
}