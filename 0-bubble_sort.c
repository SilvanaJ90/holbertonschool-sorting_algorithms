#include "sort.h"
#include <time.h>

/**
 * swap - check code
 * @xp: array
 * @yp: tamapo
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * bubble_sort - check code
 * @array: pointer array
 * @size: pointer size
 */

void bubble_sort(int *array, size_t size)
{
	/*clock_t begin = clock();*/
	size_t i, j;

	if (size == 0)
		return;

	/* el -1 es porque no se quiere llegar al final */
	for (i = 0; i < size - 1; i++)			/* n  */
	{
		for (j = 0; j < size - i - 1; j++)	/* n^2 */
		{
			if (array[j] > array[j + 1])	/* n^2 */
			{
				/* Intercambiar  */
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}

}
