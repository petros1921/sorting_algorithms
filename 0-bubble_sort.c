#include <stdio.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		for (size_t j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
		
		for (size_t k = 0; k < size; ++k)
		{
			printf("%d ", array[k]);
		}
		
		printf("\n");
	}
}
