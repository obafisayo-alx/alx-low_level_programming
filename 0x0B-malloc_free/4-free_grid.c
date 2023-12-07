#include "main.h"

/**
 * free_grid - This function is used to free a two dimensional array
 * @grid: This is the grid to be freed
 * @height: This is the height of the grid
 * Return: There is no return value.
width*/
 void free_grid(int **grid, int height)
 {
	int i;

	for (i = 0; i <= height; i++)
	{
		free(grid[i]);
	}
	free(grid);
 }