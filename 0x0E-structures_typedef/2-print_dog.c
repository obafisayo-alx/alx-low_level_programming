#include "dog.h"

/**
 * print_dog - This is print dog function
 * @d: a pointe to a struct dog
 * Return: void
*/
void print_dog(struct dog *d)
{
    if (d == NULL)
        return ;
    d->name ? printf("Name: %s\n", d->name) : printf("Name: (nil)\n");
    d->age ? printf("Name: %s\n", d->age) : printf("Age: (nil)\n");
    d->owner ? printf("Name: %s\n", d->owner) : printf("Owner: (nil)\n");
    return ;
}
