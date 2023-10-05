#include "main.h"

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
    len = i + j;
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
