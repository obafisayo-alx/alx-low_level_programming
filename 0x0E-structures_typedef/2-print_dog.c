#include "dog.h"

/**
 * print_dog - This is print dog function
 * @d: a pointe to a struct dog
 * Return: void
*/
void print_dog(struct dog *d)
{
    struct dog my_dog;

    d = &my_dog;
    if (d == NULL)
        return ;
    d->age ? d->age : printf("Name: (nil)\n");
    d->name ? d->name : printf("Age: (nil)\n");
    d->owner ? d->owner : printf("Owner: (nil)\n");
    return ;
}
