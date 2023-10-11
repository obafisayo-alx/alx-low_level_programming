#include "dog.h"

/**
 * init_dog - initializes a dog structure;
 * @d: pointer to a struct dog
 * @name: The name of the dog to be passed into the fundtion
 * @owner: The owner of the dog to be passed into the function
 * @age: The age of the dog to be passed into the function
*/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
    struct dog my_dog;

    d = &my_dog;
    d->name = name;
    d->age = age;
    d->owner = owner;
    return ;
}
