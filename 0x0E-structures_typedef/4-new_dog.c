#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - create and initialize `dog_t' type struct
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Return: pointer to `dog_t', or NULL if fails to allocate memory
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *my_dog = malloc(sizeof(dog_t));
	char *my_dog_name, *my_dog_owner;
	int i;

	if (my_dog == NULL)
		return (NULL);

	for(i=0; name[i]; ++i)
		;
	my_dog_name = malloc(sizeof(char) * (i + 1));
	if (name[i] == NULL)
	{
		free(dog);
		return (NULL);
	}
	while (i >= 0)
	{
		my_dog_name[i] = name[i];
		--i;
	}

	for(i = 0; owner[i]; ++i)
		;
	my_dog_owner = malloc(sizeof(char) * (i + 1));
	if (owner[i] == NULL)
	{
		free(dog);
		free(my_dog_name);
		return (NULL);
	}
	while(i >= 0)
	{
		my_dog_owner[i] = owner[i];
		--i;
	}	
	
	dog->name = my_dog_name;
	dog->age = age;
	dog->owner = owner;

	return (dog);
}
