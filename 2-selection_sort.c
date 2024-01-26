#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * By Kidus Yohannes and Petros Worku
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t len, m, n;

	if (!array || !size)
		return;
	for (len = 0; len < size - 1; len++)
	{
		for (m = size - 1, n = len + 1; m > len; m--)
		{
			if (array[m] < array[n])
			{
				n = m;
			}
		}
		if (array[len] > array[n])
		{
			tmp = array[len];
			array[len] = array[n];
			array[n] = tmp;
			print_array(array, size);
		}
	}
}

