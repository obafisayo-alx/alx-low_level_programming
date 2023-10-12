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
    (d->name != NULL) ? printf("Name: %s\n", d->name) : printf("Name: (nil)\n");
    d->age ? printf("Age: %f\n", d->age) : printf("Age: (nil)\n");
    (d->owner != NULL) ? printf("Owner: %s\n", d->owner) : printf("Owner: (nil)\n");
    return ;
}
