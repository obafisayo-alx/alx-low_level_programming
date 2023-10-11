#ifndef _DOG_H_
#define _DOG_H_

/**
 * struct dog - description of my dog
 * @name: The name of my dog
 * @owner: The owner of my dog
 * @age: The age of my dog
 * 
 * Description: This struct just holds the little details about my dog
*/
struct dog
{
    char *name;
    char *owner;
    float age;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif