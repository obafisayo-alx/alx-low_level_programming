#include "main.h"

/**
 * str_concat - This funcion is used to concatenate two strings together
 * @s1: This is the first string
 * @s2: This is the second string
 * Return: This is a string containing both string 1 and 2 together.
*/
char *str_concat(char *s1, char *s2)
{
    char *catstr;
    unsigned int i , j, len, a, b;

    i = j = a = b = 0;
    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";
    for (; s1[i] != '\0'; i++)
        ;
    for (; s2[j] != '\0'; j++)
        ;
    len = i + j + 1;
    catstr = (char *)malloc(sizeof(char) * len);
    if (catstr == NULL)
        return (NULL);
    while (a < i)
    {
        catstr[a] = s1[a];
        a++;
    }
    while (b < j)
    {
        catstr[a] = s2[b];
        a++;
        b++;
    }
    catstr[len] = '\0';
    return (catstr);
}
