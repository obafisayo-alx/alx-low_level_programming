#include "dog.h"

dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *p, my_dog;

    p = &my_dog;
    p->name = name;
    p->age = age;
    p->owner = owner;
    return (p);
}
