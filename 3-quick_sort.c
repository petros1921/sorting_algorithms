#include "sort.h"

/**
 * int_swap - Swaps two integers.
 * @array: Pointer to the array
 * @size: Size of the array
 * @a1: Pointer to the first integer
 * @a2: Pointer to the second integer
 * By Kidus Yohannes and Petros Worku
 */
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

/**
 * lomuto_partition - Partitions an array using the Lomuto partition scheme.
 * @array: Pointer to the array to be partitioned
 * @size: Size of the array
 * @left: Leftmost index of the partition range
 * @right: Rightmost index of the partition range
 * Returns: The index of the pivot element after partitioning
 * By Kidus Yohannes and Petros Worku
 */
size_t lomuto_partition(int *array, size_t size, ssize_t left, ssize_t right)
{
	int len, m, new_h = array[right];

	for (len = m = left; m < right; m++)
		if (array[m] < new_h)
			int_swap(array, size, &array[m], &array[len++]);
	int_swap(array, size, &array[len], &array[right]);

	return (len);
}

/**
 * lomuto_sort - Sorts an array of integers using the Lomuto partition scheme.
 * @array: Pointer to the array to be sorted
 * @left: Leftmost index of the partition range
 * @right: Rightmost index of the partition range
 * By Kidus Yohannes and Petros Worku
 */
void lomuto_sort(int *array, size_t size, ssize_t left, ssize_t right)
{
	if (left < right)
	{
		size_t p = lomuto_partition(array, size, left, right);

		lomuto_sort(array, size, left, p - 1);
		lomuto_sort(array, size, p + 1, right);

	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * By Kidus Yohannes and Petros Worku
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
