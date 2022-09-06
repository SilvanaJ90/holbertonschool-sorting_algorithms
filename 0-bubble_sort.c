#include "sort.h"
#include <time.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int *array, size_t size)
{
	/*clock_t begin = clock();*/
	size_t i, j;

	/* el -1 es porque no se quiere llegar al final */
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (array[j] > array[j + 1])
				/* Intercambiar  */
				swap(&array[j], &array[j + 1]);

	/*clock_t end = clock();*/
	/*double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;*/

	/*printf("Spent time: %f\n", time_spent);*/
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d%s", arr[i], i + 1 == size ? "}" : ", ");
    printf("\n");
}
