#include "sort.h"

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
				
