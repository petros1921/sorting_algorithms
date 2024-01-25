#include "sort.h"

void int_swap(int *array, size_t size, int *a1, int *a2)
{
	if (*a1 != *a2)
	{
		*a1 = *a1 + *a2;
		*a2 = *a1 - *a2;
		*a1 = *a1 - *a2;
		print_array((const int *)array, size);
	}
}

size_t lomuto_partition(int *array, size_t size, ssize_t left, ssize_t right)
{
	int len, m, new_h = array[right];

	for (len = m = left; m < right; m++)
		if (array[m] < new_h)
			int_swap(array, size, &array[m], &array[len++]);
	int_swap(array, size, &array[len], &array[right]);

	return (len);
}

void lomuto_sort(int *array, size_t size, ssize_t left, ssize_t right)
{
	if (left < right)
	{
		size_t p = lomuto_partition(array, size, left, right);

		lomuto_sort(array, size, left, p - 1);
		lomuto_sort(array, size, p + 1, right);

	}
}

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
