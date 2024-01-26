#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * By Kidus Yohannes and Petros Worku
 */
void bubble_sort(int *array, size_t size)
{
	size_t len, m;
	int tmp;

	if (!array || !size)
		return;

	len = 0;
	while (len < size)
	{
		for (m = 0; m < size - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				tmp = array[m];
				array[m] = array[m + 1];
				array[m + 1] = tmp;
				print_array(array, size);
			}
		}
		len++;
	}
}
