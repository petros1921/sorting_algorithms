#include "sort.h"

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

