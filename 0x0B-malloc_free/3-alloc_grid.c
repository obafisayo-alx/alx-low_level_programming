#include "main.h"

/**
 * alloc_grid - this is the function
 * @width: the width
 * @height: the height
 * Return: the return value;
*/
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	i = j = 0;
	if (height <= 0 || width <= 0)
		return (NULL);
	grid = (int **)malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		grid[i] = (int *)malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
			free(grid[j]);
			free(grid);
			return (NULL);
		}
		for (j = 0; j < width; j++)
		grid[i][j] = 0;
	}
	return (grid);
}
