#include "sort.h"

/**
 * merge_subarray - Merges two subarrays into a single sorted subarray.
 * @sub: Pointer to the original array containing the subarrays
 * @b: Temporary buffer array for merging
 * @a1: Start index of the first subarray
 * @a12: End index (exclusive) of the first subarray.
 * @a2: End index (exclusive) of the second subarray
 * By Kidus Yohannes and Petros Worku.
 */
void merge_subarray(int *sub, int *b, size_t a1, size_t a12, size_t a2)
{
	size_t index_sub, mid, buff = 0;

	printf("Merging...\n[left]: ");
	print_array(sub + a1, a12 - a1);

	printf("[right]: ");
	print_array(sub + a12, a2 - a12);

	for (index_sub = a1, mid = a12; index_sub < a12 && mid < a2; buff++)
		b[buff] = (sub[index_sub] < sub[mid]) ? sub[index_sub++] : sub[mid++];
	for (; index_sub < a12; index_sub++)
		b[buff++] = sub[index_sub];

	for (; mid < a2; mid++)
		b[buff++] = sub[mid];

	for (index_sub = a1, buff = 0; index_sub < a2; index_sub++)
		sub[index_sub] = b[buff++];

	printf("[Done]: ");
	print_array(sub + a1, a2 - a1);
}

/**
 * sort_recursive - Sorts the subarray within the given range.
 * @arr: Pointer to the original array
 * @temp: Temporary buffer array for merging subarrays
 * @start: Start index of the subarray
 * @end: End index (exclusive) of the subarray
 * By Kidus Yohannes and Petros Worku.
 */
void sort_recursive(int *arr, int *temp, size_t start, size_t end)
{
	size_t middle;

	if (end - start > 1)
	{
		middle = start + (end - start) / 2;
		sort_recursive(arr, temp, start, middle);
		sort_recursive(arr, temp, middle, end);
		merge_subarray(arr, temp, start, middle, end);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order.
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * By Kidus Yohannes and Petros Worku.
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;

	sort_recursive(array, tmp, 0, size);

	free(tmp);
}
